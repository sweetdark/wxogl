#ifndef _OGL_INCLUDED_H
#define _OGL_INCLUDED_H
#include "wx\wx.h"
#include "wx\glcanvas.h"

class MyApp;

class GLContext : public wxGLContext
{
public:
  GLContext(wxGLCanvas *canva);

};

class GLCanvas : public wxGLCanvas
{
public:
  GLCanvas(wxWindow *parent, const wxSize &size);



};

#endif