// $Id$
//
// Class PlacementMap
// ---------------------
// The map between VGM and Root placements.
//
// Author: Ivana Hrivnacova; IPN Orsay

#include "RootGM/volumes/PlacementMap.h"

RootGM::PlacementMap*  RootGM::PlacementMap::fgInstance = 0;

//_____________________________________________________________________________
RootGM::PlacementMap* 
RootGM::PlacementMap::Instance()
{ 
// Singleton access function.
// ---

  if (!fgInstance) new RootGM::PlacementMap();
  
  return fgInstance;
}  

//_____________________________________________________________________________
RootGM::PlacementMap::PlacementMap()
{
//  
  fgInstance = this;
}

//_____________________________________________________________________________
RootGM::PlacementMap::~PlacementMap() 
{
//
  fgInstance = 0;
}  

//
// public methods
//  

//_____________________________________________________________________________
void  RootGM::PlacementMap::AddPlacement(VGM::IPlacement* iPlacement, 
                                         TGeoNode* rtPlacement)
{
// Adds the specified pair in the map.
// ---

  fPlacements[iPlacement] = rtPlacement;
}  

//_____________________________________________________________________________
TGeoNode* 
RootGM::PlacementMap::GetPlacement(VGM::IPlacement* iPlacement) const
{
// Finds the Root node corresponding to a specified VGM placement.
// ---

  RootPlacementMapCIterator i = fPlacements.find(iPlacement);
  if (i != fPlacements.end()) 
    return (*i).second;
  else                 
    return 0;
}
