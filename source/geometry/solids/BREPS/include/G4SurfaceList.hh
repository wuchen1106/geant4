// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4SurfaceList.hh,v 1.2 1999/12/15 14:49:57 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
#ifndef __G4SurfaceList_h
#define __G4SurfaceList_h 1

#include "G4Surface.hh"

class G4SurfaceList
{
 public:
  
  G4SurfaceList();
  ~G4SurfaceList();
  
  int number_of_elements;
  
  G4Surface* first;
  G4Surface* next;
  G4Surface* last;
  G4Surface* temp;
  G4Surface* index;
  
  void MoveToFirst(G4Surface *srf);
  void AddSurface(G4Surface *srf);
  
  G4Surface* GetSurface();
  G4Surface* GetSurface(int number);
  G4Surface* GetLastSurface();
  
  void RemoveSurface(G4Surface* srf);
  void RemovePointer();
  
  void MoveToFirst();
  void Step();
  
  void EmptyList();
  void G4SortList();
  
  void QuickG4Sort(G4Surface**, int, int);

};

#endif







