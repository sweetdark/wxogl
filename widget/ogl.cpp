#include "ogl.h"



GLCanvas::GLCanvas(wxWindow *parent, const wxSize &size) : wxGLCanvas(parent, wxID_ANY, NULL, wxDefaultPosition, size, wxFULL_REPAINT_ON_RESIZE)
{
  
}

GLContext::GLContext(wxGLCanvas *canvas) : wxGLContext(canvas)
{
  SetCurrent(*canvas);

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_LINE_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

}