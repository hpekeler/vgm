// $Id$
//
// Class Torus
// ---------------
// VGM implementation for Root torus solid.
//
// Author: Ivana Hrivnacova; IPN Orsay

#include "RootGM/solids/Torus.h"
#include "RootGM/solids/SolidMap.h"
#include "RootGM/common/Units.h"

//_____________________________________________________________________________
RootGM::Torus::Torus(const std::string& name, 
                     double rin, double rout, double rax, 
		     double sphi, double dphi)
  : BaseVGM::VTorus(),
    fTorus(new TGeoTorus(name.data(), 
                         rax  / RootGM::Units::Length(), 
		         rin  / RootGM::Units::Length(), 
		         rout / RootGM::Units::Length(), 
		         sphi / RootGM::Units::Angle(), 
		         dphi / RootGM::Units::Angle()))
{
// 
  RootGM::SolidMap::Instance()->AddSolid(this, fTorus); 
}


//_____________________________________________________________________________
RootGM::Torus::Torus(TGeoTorus* torus)
  : BaseVGM::VTorus(),
    fTorus(torus)
{    
  RootGM::SolidMap::Instance()->AddSolid(this, fTorus); 
}

//_____________________________________________________________________________
RootGM::Torus::~Torus() {
//
}    

//_____________________________________________________________________________
std::string RootGM::Torus::Name() const
{
  return fTorus->GetName();
}  
  
//_____________________________________________________________________________
double RootGM::Torus::InnerRadius() const
{
  return fTorus->GetRmin() * RootGM::Units::Length();
}  

//_____________________________________________________________________________
double RootGM::Torus::OuterRadius() const
{
  return fTorus->GetRmax() * RootGM::Units::Length();
}  

//_____________________________________________________________________________
double RootGM::Torus::AxialRadius() const
{
  return fTorus->GetR() * RootGM::Units::Length();
}  

//_____________________________________________________________________________
double RootGM::Torus::StartPhi() const
{
  return fTorus->GetPhi1() * RootGM::Units::Angle();
}  

//_____________________________________________________________________________
double RootGM::Torus::DeltaPhi() const
{
  return fTorus->GetDphi() * RootGM::Units::Angle();
}  