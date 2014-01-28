#include "controller.h"
#include <algorithm>
#include "canvassetting.h"
#include "primitivefactory.h"
#include <wx\bitmap.h>
#include <wx\glcanvas.h>
#include <stdlib.h>
#include <stdio.h>

// Define targa header. This is only used locally.
#pragma pack(1)
typedef struct
{
  GLbyte	identsize;              // Size of ID field that follows header (0)
  GLbyte	colorMapType;           // 0 = None, 1 = paletted
  GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
  unsigned short	colorMapStart;          // First colour map entry
  unsigned short	colorMapLength;         // Number of colors
  unsigned char 	colorMapBits;   // bits per palette entry
  unsigned short	xstart;                 // image x origin
  unsigned short	ystart;                 // image y origin
  unsigned short	width;                  // width in pixels
  unsigned short	height;                 // height in pixels
  GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
  GLbyte	descriptor;             // image descriptor
} TGAHEADER;
#pragma pack(8)


GLint gltWriteTGA(const char *szFileName)
{
  FILE *pFile;                // File pointer
  TGAHEADER tgaHeader;		// TGA file header
  unsigned long lImageSize;   // Size in bytes of image
  GLbyte	*pBits = NULL;      // Pointer to bits
  GLint iViewport[4];         // Viewport in pixels
  GLenum lastBuffer;          // Storage for the current read buffer setting

  // Get the viewport dimensions
  glGetIntegerv(GL_VIEWPORT, iViewport);

  // How big is the image going to be (targas are tightly packed)
  lImageSize = iViewport[2] * 3 * iViewport[3];	

  // Allocate block. If this doesn't work, go home
  pBits = (GLbyte *)malloc(lImageSize);
  if(pBits == NULL)
    return 0;

  // Read bits from color buffer
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glPixelStorei(GL_PACK_ROW_LENGTH, 0);
  glPixelStorei(GL_PACK_SKIP_ROWS, 0);
  glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

  // Get the current read buffer setting and save it. Switch to
  // the front buffer and do the read operation. Finally, restore
  // the read buffer state
  glGetIntegerv(GL_READ_BUFFER, (GLint *)&lastBuffer);
  glReadBuffer(GL_FRONT);
  glReadPixels(0, 0, iViewport[2], iViewport[3], GL_BGR_EXT, GL_UNSIGNED_BYTE, pBits);
  glReadBuffer(lastBuffer);

  // Initialize the Targa header
  tgaHeader.identsize = 0;
  tgaHeader.colorMapType = 0;
  tgaHeader.imageType = 2;
  tgaHeader.colorMapStart = 0;
  tgaHeader.colorMapLength = 0;
  tgaHeader.colorMapBits = 0;
  tgaHeader.xstart = 0;
  tgaHeader.ystart = 0;
  tgaHeader.width = iViewport[2];
  tgaHeader.height = iViewport[3];
  tgaHeader.bits = 24;
  tgaHeader.descriptor = 0;

  // Attempt to open the file
  pFile = fopen(szFileName, "wb");
  if(pFile == NULL)
  {
    free(pBits);    // Free buffer and return error
    return 0;
  }

  // Write the header
  fwrite(&tgaHeader, sizeof(TGAHEADER), 1, pFile);

  // Write the image data
  fwrite(pBits, lImageSize, 1, pFile);

  // Free temporary buffer and close the file
  free(pBits);    
  fclose(pFile);

  // Success!
  return 1;
}


Controller* Controller::m_self = NULL;
static bool IsActive(Primitive *p)
{
  if (p)
  {
    if (p->IsActive())
    {
      return true;
    }
  }
  return false;
}

static bool IsNotActive(Primitive *p)
{
  return !IsActive(p);
}

Controller::Controller() {}

Controller::~Controller() 
{
  ClearAll();
}

Controller & Controller::Get()
{
  if (m_self == NULL)
  {
    m_self = new Controller();
  }
  return *m_self;
}


void Controller::AddLine(Vertex v1, Vertex v2)
{
  Primitive *p = PrimitiveFactory::GetPrimitive(PT_Line);
  if (p)
  {
    p->AddVertex(v1);
    p->AddVertex(v2);
    m_primitvies.push_back(p);
  }
    
}

void Controller::AddPrimitive(Primitive *p)
{
  if (p)
  {
    m_primitvies.push_back(p);
  }
  //添加新图元的时候，去掉非激活状态的图元,不可以回退
  for(PriItr first = m_primitvies.begin(); first != m_primitvies.end();)
  {
    if ((*first) && !(*first)->IsActive())
    {
      delete *first;
      m_primitvies.erase(first++);
      break;
    }
    else
    {
      ++first;
    }
  }
}

void Controller::Draw()
{
  for (int i = 0; i < m_primitvies.size(); ++i)
  {
    m_primitvies[i]->Draw();
  }
}

void Controller::ClearAll()
{  
  std::for_each(m_primitvies.begin(), m_primitvies.end(), Controller::Delete); 
  m_primitvies.clear();
}

void Controller::Undo()
{
  for(int i = m_primitvies.size() - 1; i >= 0; --i)
  {
    if (m_primitvies[i] && m_primitvies[i]->IsActive())
    {
      m_primitvies[i]->Active(false); 
      break;
    }
  }
}
void Controller::Redo()
{
  PriItr itr = std::find_if(m_primitvies.begin(), m_primitvies.end(), IsNotActive);
  if (itr != m_primitvies.end())
    (*itr)->Active(true);
}

void Controller::SaveToTgaFile(const wxString &fileName)
{    
  gltWriteTGA(fileName.c_str());
}
