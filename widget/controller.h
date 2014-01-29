#ifndef _CONTROLLER_INCLUDED_H
#define _CONTROLLER_INCLUDED_H
#include <vector>
#include "typedef.h"
#include <wx\string.h>
using namespace std;

class Primitive;
class Controller
{
  typedef vector<Primitive *> Primitives;
  typedef Primitives::iterator PriItr;
  Controller();
  ~Controller();
public:
  static Controller &Get();

  void AddLine(Vertex v1, Vertex v2);
  void Draw();
  void AddPrimitive(Primitive *p);

  void ClearAll();

  void Undo();

  void Redo();

  void SaveToTgaFile(const wxString &fileName);
  void SaveToBmpFile(const wxString &fileName);
private:
  static void Delete(Primitive *p)
  {
    if (p)
    {
      delete p;
    }
  }

private:
  vector<Primitive* > m_primitvies;

  static Controller *m_self;
};

#endif