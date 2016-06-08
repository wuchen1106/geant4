// neutron_hp -- source file
// J.P. Wellisch, Nov-1996
// A prototype of the low energy neutron transport model.
//
#include "G4NeutronHPList.hh"

  void G4NeutronHPList::Check(G4int i)
  {
    if(i<0) 
    {
      G4int dummy; 
      G4Exception("G4NeutronHPList::Check(G4int) called with negative index");
    }
    if(i>nEntries) G4Exception("Skipped some index numbers in G4NeutronHPList");
    if(i==nPoints)
    {
      nPoints += 50;
      G4double * buff = new G4double[nPoints];
      for (G4int j=0; j<nEntries; j++) buff[j] = theData[j];
      delete [] theData;
      theData = buff;
    }
    if(i==nEntries) nEntries++;
  }
  
  void G4NeutronHPList::Init(G4std::ifstream & aDataFile, G4int nPar, G4double unit)
  {
    G4int i;
    G4double y;
    for (i=0; i<nPar; i++)
    {
      aDataFile >> y;
      SetValue(i,y*unit);
    }
  }

  void G4NeutronHPList::Init(G4std::ifstream & aDataFile, G4double unit)
  {
    G4int total, i;
    aDataFile >> total;
    G4double y;
    for (i=0;i<total;i++)
    {
      aDataFile >>y;
      SetValue(i,y*unit);
    }
  }
  
  G4double G4NeutronHPList::GetValue(G4int i) 
  { 
//    G4cout << "TestList "<<i<<" "<<nEntries<<G4endl;
    if(nEntries<0)
    {
//      G4cout <<nPoints<<" "<<nEntries<<" "<<theData<<G4endl;
//      for(G4int ii=0; ii<2; ii++) G4cout << theData[ii]<<" ";
//      G4cout << G4endl;
    }
    if (i<0) i=0;
    if(i>=GetListLength()) i=GetListLength()-1;
    return theData[i];
  }
  