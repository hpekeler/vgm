// $Id$

// -----------------------------------------------------------------------
// The test program of the Virtual Geometry Model
// Copyright (C) 2007, Ivana Hrivnacova               
// All rights reserved. 
//           
// For the licensing terms see vgm/LICENSE.
// Contact: ivana@ipno.in2p3.fr
// -----------------------------------------------------------------------

//
// Class TstGeometryViaVGM
// -------------------------------
// Class for building geometry vis VGM
//
// Author: Ivana Hrivnacova; IPN Orsay


#include "CLHEP/Vector/Rotation.h"
#include "CLHEP/Vector/ThreeVector.h"
#include "CLHEP/Geometry/Transform3D.h"
#include "CLHEP/Geometry/Transform3D.h"
#include "CLHEP/Units/SystemOfUnits.h"

#include "VGM/materials/IMaterialFactory.h"
#include "VGM/volumes/IFactory.h"
#include "VGM/volumes/IVolume.h"

#include "ClhepVGM/transform.h"
#include "ClhepVGM/Units.h"

#include "TstGeometryViaVGM.hh"

using namespace VGM;

using CLHEP::m;
using CLHEP::cm;
using CLHEP::cm3;
using CLHEP::deg;
using CLHEP::g;
using CLHEP::mg;
using CLHEP::mole;
using CLHEP::kelvin;
using CLHEP::atmosphere;
using CLHEP::hep_pascal;

//_____________________________________________________________________________
TstGeometryViaVGM::TstGeometryViaVGM(IFactory* factory)
  : TstVGeometry(),
    fFactory(factory),
    fCm(ClhepVGM::Units::Length(cm)),
    fDeg(ClhepVGM::Units::Angle(deg)),
    fGcm3(ClhepVGM::Units::MassDensity(g/cm3)),
    fGmole(ClhepVGM::Units::AtomicWeight(g/mole)),
    fKelvin(ClhepVGM::Units::Temperature(kelvin)),
    fAtm(ClhepVGM::Units::Pressure(atmosphere))
{
//
}  

//_____________________________________________________________________________
TstGeometryViaVGM::~TstGeometryViaVGM()
{
}

//
// private methods
// 

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateWorld(double x, double y, double z)
{
// Create world volume
// ---
  
  ISolid* worldS = fFactory->CreateBox("worldS", x, y, z);

  return fFactory->CreateVolume("world", worldS, "Basic");
}    

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateNewSolid()
{
  return CreateExtrudedSolid2();
}  


//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateBox()
{
  ISolid* boxS
    = fFactory->CreateBox("boxS", 20. * fCm, 60.* fCm, 50.* fCm);
  
  return fFactory->CreateVolume("box", boxS, "Basic");
}  


//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateCons(double sphi, double dphi)
{
  ISolid* consS
    = fFactory->CreateCons("consS", 
                           10.* fCm, 40.* fCm, 20.* fCm, 60.* fCm, 50* fCm,
                           sphi, dphi);
  
  return fFactory->CreateVolume("cons", consS, "Basic");
}

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateEllipticalTube()
{
  ISolid* eltuS
    = fFactory->CreateEllipticalTube("eltuS", 20.* fCm, 30.* fCm, 50* fCm);
  
  return fFactory->CreateVolume("eltu", eltuS, "Basic");
}
 
//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateExtrudedSolid1()
{   
  std::vector<VGM::TwoVector> polygon;
  polygon.push_back(VGM::TwoVector(-30.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector(-30.*fCm,  30.*fCm));
  polygon.push_back(VGM::TwoVector( 30.*fCm,  30.*fCm));
  polygon.push_back(VGM::TwoVector( 30.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector( 15.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector( 15.*fCm,  15.*fCm));
  polygon.push_back(VGM::TwoVector(-15.*fCm,  15.*fCm));
  polygon.push_back(VGM::TwoVector(-15.*fCm, -30.*fCm));
  
  double array1[] = { -40.*cm, -20.*cm, 10.*cm, 1.5 }; 
  double array2[] = {  10.*cm,   0.*cm,  0.*cm, 0.5 }; 
  double array3[] = {  15.*cm,   0.*cm,  0.*cm, 0.7 }; 
  double array4[] = {  40.*cm,  20.*cm, 20.*cm, 0.9 }; 

  std::vector< std::vector<double> > zsections;
  zsections.push_back(std::vector<double>(array1, array1 + 4));
  zsections.push_back(std::vector<double>(array2, array2 + 4));
  zsections.push_back(std::vector<double>(array3, array3 + 4));
  zsections.push_back(std::vector<double>(array4, array4 + 4));

  ISolid* xtruS
    = fFactory->CreateExtrudedSolid("xtruS",polygon, zsections);
  
  return fFactory->CreateVolume("xtru1", xtruS, "Basic");
}  
 
//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateExtrudedSolid2()
{   
  std::vector<VGM::TwoVector> polygon;
  polygon.push_back(VGM::TwoVector(-30.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector(-30.*fCm,  30.*fCm));
  polygon.push_back(VGM::TwoVector( 30.*fCm,  30.*fCm));
  polygon.push_back(VGM::TwoVector( 30.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector( 15.*fCm, -30.*fCm));
  polygon.push_back(VGM::TwoVector( 15.*fCm,  15.*fCm));
  polygon.push_back(VGM::TwoVector(-15.*fCm,  15.*fCm));
  polygon.push_back(VGM::TwoVector(-15.*fCm, -30.*fCm));
  
  double array1[] = { -40.*cm, -20.*cm, 10.*cm, 1.5 }; 
  double array2[] = {  10.*cm,   0.*cm,  0.*cm, 0.5 }; 
  double array3[] = {  10.*cm,   0.*cm,  0.*cm, 0.7 }; 
  double array4[] = {  40.*cm,  20.*cm, 20.*cm, 0.9 }; 

  std::vector< std::vector<double> > zsections;
  zsections.push_back(std::vector<double>(array1, array1 + 4));
  zsections.push_back(std::vector<double>(array2, array2 + 4));
  zsections.push_back(std::vector<double>(array3, array3 + 4));
  zsections.push_back(std::vector<double>(array4, array4 + 4));

  ISolid* xtruS
    = fFactory->CreateExtrudedSolid("xtruS",polygon, zsections);
  
  return fFactory->CreateVolume("xtru2", xtruS, "Basic");
}  
 
//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreatePara()
{
  ISolid* paraS
    = fFactory->CreatePara("paraS", 40.* fCm, 60.* fCm, 50.* fCm, 
                           30.* fDeg, 30.* fDeg, 30.* fDeg);

  return fFactory->CreateVolume("para", paraS, "Basic");
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreatePolycone(double sphi, double dphi)
{
  // Define parameters

  int nofPlanes = 3;
  double z[3];
  double rin[3];
  double rout[3];

  z[0] = -50.* fCm;
  rin[0] = 10.* fCm;
  rout[0] = 50.* fCm;
  
  z[1] = 10.* fCm;
  rin[1] = 20.* fCm;
  rout[1] = 30.* fCm;
  
  z[2] = 40.* fCm;
  rin[2] = 30.* fCm;
  rout[2] = 60.* fCm;
  
  ISolid* pconeS
    = fFactory->CreatePolycone("pconeS", sphi, dphi, nofPlanes, z, rin, rout);
  
  return fFactory->CreateVolume("pcone", pconeS, "Basic");
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreatePolyhedra(double sphi, double dphi)
{
  // Define parameters

  int nofSides = 4;
  int nofPlanes = 3;
  double z[3];
  double rin[3];
  double rout[3];

  z[0] = -50.* fCm;
  rin[0] = 10.* fCm;
  rout[0] = 40.* fCm;
  
  z[1] = 10.* fCm;
  rin[1] = 20.* fCm;
  rout[1] = 20.* fCm;
  
  z[2] = 40.* fCm;
  rin[2] = 30.* fCm;
  rout[2] = 50.* fCm;
  

  ISolid* phedraS
    = fFactory->CreatePolyhedra("phedraS", sphi, dphi, 
                           nofSides, nofPlanes, z, rin, rout);

  return fFactory->CreateVolume("phedra", phedraS, "Basic");
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateSphere(double sphi, double dphi)
{
  ISolid* sphereS
    = fFactory->CreateSphere("sphereS", 20.* fCm, 60.* fCm,
                            sphi, dphi, sphi/2., dphi/2.); 
			    
  return fFactory->CreateVolume("sphere", sphereS, "Basic");
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateTorus(double sphi, double dphi)
{
  ISolid* torusS
    = fFactory->CreateTorus("torusS", 20.* fCm, 30.* fCm, 40.* fCm,
                            sphi, dphi);
			    
  return fFactory->CreateVolume("torus", torusS, "Basic");  
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateTrap()
{
  ISolid* trapS
    = fFactory->CreateTrap("trapS", 30.* fCm, 25.* fDeg, 35.* fDeg,
  		          20.* fCm, 10.* fCm, 15.* fCm, 0.* fDeg,
  		          20.* fCm, 10.* fCm, 15.* fCm, 0.* fDeg);

  return fFactory->CreateVolume("trap", trapS, "Basic");
}

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateTrd()
{
  ISolid* trdS
    = fFactory->CreateTrd("trdS", 20.* fCm, 30* fCm, 40.* fCm, 50.* fCm, 50.* fCm);

  return fFactory->CreateVolume("trd", trdS, "Basic");
}  

//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateTubs(double sphi, double dphi)
{
  ISolid* tubsS
    = fFactory->CreateTubs("tubsS", 20.* fCm, 40* fCm, 50.* fCm, sphi, dphi);

  return fFactory->CreateVolume("tubs", tubsS, "Basic");
}  
 
//_____________________________________________________________________________
IVolume* TstGeometryViaVGM::CreateCtubs(double /*sphi*/, double /*dphi*/)
{
  ISolid* ctubsS
    = fFactory->CreateCtubs("ctubsS", 20.* fCm, 30* fCm, 60.49* fCm, 
                           330.* fDeg, 280.*fDeg,
			   0.00, 0.64, -0.77, 0.00, 0.09, 0.87);

  return fFactory->CreateVolume("ctubs", ctubsS, "Basic");
}  
 
//_____________________________________________________________________________
void* TstGeometryViaVGM::PlaceSolids(IVolume* mother,
                                     bool fullPhi, bool reflect, double zpos)
{
  double sphi =   0.* fDeg;
  double dphi = 360.* fDeg;
  if (!fullPhi) {
    sphi = 45.* fDeg;
    dphi = 90.* fDeg;
  }  
 
  int counter = 0;
  double x0 = -450.*fCm;
  double dx = 150.*fCm;
  double dy = 150.*fCm;
  
  HepGeom::ReflectZ3D reflect3D;
 
  // Box
  //
  IVolume* boxV = CreateBox();
  fFactory->CreatePlacement("box", 0, boxV, mother, 
              ClhepVGM::Transform(
	        HepGeom::Translate3D(x0 + (counter)*dx,  -dy, zpos))); 
  if (reflect)
    fFactory->CreatePlacement("box", 0, boxV, mother, 
                ClhepVGM::Transform(
                  HepGeom::Translate3D(x0 + (counter)*dx,  -dy, -zpos) * reflect3D)); 

  // Cons 
  //
  IVolume* consV = CreateCons(sphi, dphi);
  fFactory->CreatePlacement("cons", 0, consV, mother, 
              ClhepVGM::Transform(
                HepGeom::Translate3D(x0 + (counter)*dx, dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("cons", 0, consV, mother, 
                ClhepVGM::Transform(
                  HepGeom::Translate3D(x0 + (counter)*dx, dy, -zpos) * reflect3D));

  // Elliptical tube 
  //
  IVolume* eltuV = CreateEllipticalTube();
  fFactory->CreatePlacement("eltu", 0, eltuV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
  fFactory->CreatePlacement("eltu", 0, eltuV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Para
  //
  IVolume* paraV = CreatePara();
  fFactory->CreatePlacement("para", 0, paraV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx,  dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("para", 0, paraV, mother, 
                ClhepVGM::Transform(
                  HepGeom::Translate3D(x0 + (counter)*dx,  dy, -zpos) * reflect3D));
  
  // Polycone
  //
  IVolume* pconeV = CreatePolycone(sphi, dphi);
  fFactory->CreatePlacement("pcone", 0, pconeV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("pcone", 0, pconeV, mother, 
                ClhepVGM::Transform(
                  HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Polyhedra
  //
  IVolume* phedraV = CreatePolyhedra(sphi, dphi);
  fFactory->CreatePlacement("phedra", 0, phedraV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx,  dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("phedra", 0, phedraV, mother, 
                ClhepVGM::Transform(
                  HepGeom::Translate3D(x0 + (counter)*dx,  dy, -zpos) * reflect3D));

  // Sphere 
  //
  IVolume* sphereV = CreateSphere(sphi, dphi);
  fFactory->CreatePlacement("sphere", 0, sphereV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("sphere", 0, sphereV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Torus
  //
  IVolume* torusV = CreateTorus(sphi, dphi);
  fFactory->CreatePlacement("torus", 0, torusV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx,  dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("torus", 0, torusV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx,  dy, -zpos) * reflect3D));

  // Trap 
  //
  IVolume* trapV = CreateTrap();
  fFactory->CreatePlacement("trap", 0, trapV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("trap", 0, trapV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Trd
  //
  IVolume* trdV = CreateTrd();
  fFactory->CreatePlacement("trd", 0, trdV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx,  dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("trd", 0, trdV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx,  dy, -zpos) * reflect3D));
 
  // Tube
  //
  IVolume* tubsV = CreateTubs(sphi, dphi);
  fFactory->CreatePlacement("tubs", 0, tubsV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("tubs", 0, tubsV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Ctubs
  //
  IVolume* ctubsV = CreateCtubs(sphi, dphi);
  fFactory->CreatePlacement("ctubs", 0, ctubsV, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx, dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("ctubs", 0, ctubsV, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, dy, -zpos) * reflect3D));

  // Xtru1
  //
  IVolume* xtru1V = CreateExtrudedSolid1();
  fFactory->CreatePlacement("xtru1", 0, xtru1V, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (++counter)*dx, -dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("xtru1", 0, xtru1V, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, -dy, -zpos) * reflect3D));

  // Xtru2
  //
  IVolume* xtru2V = CreateExtrudedSolid2();
  fFactory->CreatePlacement("xtru2", 0, xtru2V, mother, 
               ClhepVGM::Transform(
                 HepGeom::Translate3D(x0 + (counter)*dx, dy, zpos)));
  if (reflect)
    fFactory->CreatePlacement("xtru2", 0, xtru2V, mother, 
                 ClhepVGM::Transform(
                   HepGeom::Translate3D(x0 + (counter)*dx, dy, -zpos) * reflect3D));

  return (void*) fFactory->Top();
 }

//
// public methods
// 

//_____________________________________________________________________________
void  TstGeometryViaVGM::DefineMaterials()
{
  // Get material factory
  IMaterialFactory* materialFactory = fFactory->MaterialFactory();

  // predefined elements
  IElement* elH = materialFactory->CreateElement(1);
  IElement* elC = materialFactory->CreateElement(6);

  // create elements
  double z, a, density, radlen, intlen, temperature, pressure; 
  IElement* elVacuum
    = materialFactory->CreateElement("Vacuum",    "Vacuum_e",  z=1.,  a= 1.01 * fGmole);
  IElement* elN
    = materialFactory->CreateElement("Nitrogen",  "N",  z=7.,  a=14.01 * fGmole);
  IElement* elO
    = materialFactory->CreateElement("Oxygen",    "O",  z=8.,  a=16.00 * fGmole);
  IElement* elAl
    = materialFactory->CreateElement("Aluminium", "Al", z=13., a=26.98 * fGmole);

  // simple material (Al)
  //
  IMaterial* material1 
    = materialFactory
      ->CreateMaterial("Basic", density=2.700* fGcm3, elAl, radlen=0., intlen=0.);

  // compound/mixture material
  //
  ElementVector elements;
  elements.push_back(elN);
  elements.push_back(elO);

  MassFractionVector fractions;
  fractions.push_back(0.7);
  fractions.push_back(0.3);
    
  density = 1.290 * ClhepVGM::Units::MassDensity(mg/cm3);
  IMaterial* material2 
    = materialFactory
      ->CreateMaterial("Air", density, elements, fractions);

  // material from predefined elements
  //

  ElementVector elements2;
  elements2.push_back(elC);
  elements2.push_back(elH);

  AtomCountVector atomCounts;
  atomCounts.push_back(9);
  atomCounts.push_back(10);

  density = 1.032 * ClhepVGM::Units::MassDensity(g/cm3);
  IMaterial* material3
    = materialFactory
      ->CreateMaterial("Scintillator", density, elements2, atomCounts);

  // material using isotopes
  int iz, n;
  IIsotope* isoU5 
    = materialFactory->CreateIsotope("U235", iz=92, n=235, a=235.01*g/mole);
  IIsotope* isoU8 
    = materialFactory->CreateIsotope("U238", iz=92, n=238, a=238.03*g/mole);
 
  IsotopeVector isotopes;
  isotopes.push_back(isoU5);
  isotopes.push_back(isoU8);

  RelAbundanceVector relAbundances;
  relAbundances.push_back(0.90);
  relAbundances.push_back(0.10);
    
  IElement* elU  
    = materialFactory
      ->CreateElement("enriched Uranium", "U", isotopes, relAbundances);

  density = 13.61 * ClhepVGM::Units::MassDensity(g/cm3);
  IMaterial* material4
    = materialFactory
      ->CreateMaterial("Uranium", density, elU, radlen=0., intlen=0.);

  // vacuum
  //
  density = CLHEP::universe_mean_density / (g/cm3) * fGcm3;
  temperature = 2.73 * fKelvin;
  pressure = 3.e-18 * ClhepVGM::Units::Pressure(pascal);
  IMaterial* material5
    = materialFactory
      ->CreateMaterial("Vacuum", density, elVacuum, radlen=0., intlen=0.,
                       VGM::kGas, temperature, pressure);

  // define tracking media
  // with no parameters specified
  materialFactory->CreateMedium("Basic",        1, material1, 0, 0); 
  materialFactory->CreateMedium("Air",          2, material2, 0, 0); 
  materialFactory->CreateMedium("Scintillator", 3, material3, 0, 0); 
  materialFactory->CreateMedium("Uranium",      4, material4, 0, 0); 
  materialFactory->CreateMedium("Vacuum",       5, material5, 0, 0); 
}

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestSolids(bool fullPhi)
{
  IVolume* worldV = CreateWorld(600.*fCm, 300.*fCm, 200.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  PlaceSolids(worldV, fullPhi, false, 0.);

  return (void*) fFactory->Top();
 }

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestNewSolid()
{
  IVolume* worldV = CreateWorld(200.*fCm, 200.*fCm, 200.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  IVolume* newSolidV = CreateNewSolid();
  if ( newSolidV ) {
    fFactory->CreatePlacement(newSolidV->Name(), 0, newSolidV, worldV, 
                              ClhepVGM::Identity());
  }   

  return (void*) fFactory->Top();
 }

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestPlacements()
{
  // World
  //
  IVolume* worldV = CreateWorld(600.*fCm, 100.*fCm, 600.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());

  // Big box A
  //
  ISolid * boxA
    = fFactory->CreateBox("boxA", 20.* fCm, 60.* fCm, 50.* fCm);
  IVolume* volA
    = fFactory->CreateVolume("volA", boxA, "Air");
  
  // Thick layer B (in A)
  //
  ISolid * boxB
    = fFactory->CreateBox("boxB", 20.* fCm, 10.* fCm, 50.* fCm);
  IVolume * volB
    = fFactory->CreateVolume("volB", boxB, "Uranium");

  // Thin layer C (in B)
  //
  ISolid * boxC
    = fFactory->CreateBox("boxC", 20.* fCm, 0.2* fCm, 50.* fCm);
  IVolume * volC
    = fFactory->CreateVolume("volC", boxC, "Scintillator");

  // Place layers B   
  //
  //fFactory->CreateMultiplePlacement("layerB", volB, volA, 
  //                                 VGM::kYAxis, 6, 20.*mm, 0.);
             // division in the whole mother

  fFactory->CreateMultiplePlacement("layerB", volB, volA, 
                                   VGM::kYAxis, 3, 20.* fCm, 60.* fCm);
             // division with offset

	// If layers C placed first, they are not passed
	// in a new TGeo Volume if running with Root.
	// To be improved later.

  // Place layers C
  //
  fFactory->CreatePlacement("layerC", 0, volC, volB,  
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector(0.,  9.8* fCm, 0.)));

  fFactory->CreatePlacement("layerC", 1, volC, volB, 
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector(0., -9.8* fCm, 0.)));


  // Placements of A in a circle
  //
  for (int i=0; i<24; i++) {
   
     double x0 = 5. *m;
     double y0 = 0. *m;
     double dphi = 15.* deg;
         // use directly CLHEP units when using CLHEP rotations

     double phi = dphi*(i+1);
     double x = x0*cos(phi);
     double z = x0*sin(phi);

     CLHEP::HepRotation rot;
     rot.rotateY(-phi);
        // !!! Different meaning of rotation in VGM than in Geant4 
     
     fFactory->CreatePlacement("layerA", i, volA, worldV,
                               ClhepVGM::Transform(rot, CLHEP::Hep3Vector(x, y0, z)));
   }
   
  return (void*) fFactory->Top();
}

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestReflections(bool fullPhi)
{
  IVolume* worldV = CreateWorld(600.*fCm, 300.*fCm, 300.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  PlaceSolids(worldV, fullPhi, true, 100.* fCm);

  return (void*) fFactory->Top();
 }

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestAssemblies()
{
  std::cout << "TestAssemblies: not available via VGM" << std::endl;

  return 0;
 }

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestAssemblies2()
{
  std::cout << "TestAssemblies2: not available via VGM" << std::endl;

  return 0;
 }

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestBooleanSolids1()
{
// Only translation in solid displacement

  IVolume* worldV = CreateWorld(400.*fCm, 100.*fCm, 400.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  // Create solids
  ISolid* solid1 
    = fFactory->CreateBox("boxS", 50.* fCm, 50.* fCm, 50.* fCm);

  ISolid* solid2 
    = fFactory->CreateCons("consS", 
                          10.* fCm, 30.* fCm, 20.* fCm, 40.* fCm, 100.* fCm, 
			  0., 360.* fDeg) ;
    
  // Simple solids placed for a control
  //
  IVolume* volume1
    = fFactory->CreateVolume("solid1", solid1, "Basic");
  fFactory->CreatePlacement("solid1", 0, volume1, worldV, 
                   ClhepVGM::Transform( 
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector(-125.*fCm, 0., -200.* fCm)));

  IVolume* volume2
    = fFactory->CreateVolume("solid2", solid2, "Basic");
  fFactory->CreatePlacement("solid2", 0, volume2, worldV, 
                   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector( 125.*fCm, 0., -200.* fCm)));


  // Intersection
  //
  ISolid* intersectionS
    = fFactory->CreateIntersectionSolid(
                  "intersection_solid1_solid2_S", solid1, solid2, 
		   ClhepVGM::Transform(
		     CLHEP::HepRotation(),
		     CLHEP::Hep3Vector(20.* fCm, 0., 0.))); 

  IVolume* intersectionV
    = fFactory->CreateVolume("intersection_solid1_solid2", intersectionS, "Basic");

  fFactory->CreatePlacement("intersection_solid1_solid2", 0, intersectionV, worldV, 
		   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector(-250.*fCm, 0., 200.* fCm)));
  
  // Subtraction
  //
  ISolid* subtractionS
    = fFactory->CreateSubtractionSolid(
                  "subtraction_solid1_solid2_S", solid1, solid2, 
                   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector(20.* fCm, 0., 0.))); 
				       
  IVolume* subtractionV
    = fFactory->CreateVolume("subtraction_solid1_solid2", subtractionS, "Basic");

  fFactory->CreatePlacement("subtraction_solid1_solid2", 0, subtractionV, worldV, 
                   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector(0., 0., 200.* fCm)));
  
  // Union
  //
  ISolid* unionS
    = fFactory->CreateUnionSolid(
                  "union_solid1_solid2_S", solid1, solid2, 
                   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector(20.* fCm, 0., 0.))); 
  IVolume* unionV
    = fFactory->CreateVolume("union_solid1_solid2", unionS, "Basic");

  fFactory->CreatePlacement("union_solid1_solid2", 0, unionV, worldV, 
                   ClhepVGM::Transform(
		     CLHEP::HepRotation(), 
		     CLHEP::Hep3Vector( 250.*fCm, 0., 200.* fCm)));
  
  return (void*) fFactory->Top();
}

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestBooleanSolids2()
{
// Translation + rotation in solid displacement

  IVolume* worldV = CreateWorld(400.*fCm, 100.*fCm, 400.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  // Create solids
  ISolid* solid1 
    = fFactory->CreateBox("boxS", 50.* fCm, 50.* fCm, 50.* fCm);

  ISolid* solid2 
    = fFactory->CreateCons("consS", 
                         10.* fCm, 30.* fCm, 20.* fCm, 40.* fCm, 100.* fCm, 
			 0., 360.* fDeg) ;
    
  // Simple solids placed for a control
  //
  IVolume* volume1
    = fFactory->CreateVolume("solid1", solid1, "Basic");
  fFactory->CreatePlacement("solid1", 0, volume1, worldV,
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector(-125.*fCm, 0., -200.* fCm)));

  IVolume* volume2
    = fFactory->CreateVolume("solid2", solid2, "Basic");
  fFactory->CreatePlacement("solid2", 0, volume2, worldV, 
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector( 125.*fCm, 0., -200.* fCm)));


  // Define displacement transformations
  //
 
  // Rotate solid1  
  CLHEP::HepRotation rot1;
  rot1.rotateY(45.* deg);

  // Rotate + translate solid2
  //
  CLHEP::HepRotation rot2;
  rot2.rotateX( 30.* deg);
  rot2.rotateY(-45.* deg); 
  CLHEP::Hep3Vector tr2 = CLHEP::Hep3Vector(20.* fCm, 0., 0.);
  
  // Intersection
  //
  ISolid* intersectionS
    = fFactory->CreateIntersectionSolid(
                  "intersection_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(rot2,tr2)); 
  IVolume* intersectionV
    = fFactory->CreateVolume("intersection_solid1_solid2", intersectionS, "Basic");

  fFactory->CreatePlacement("intersection_solid1_solid2", 0, intersectionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector(-250.*fCm, 0., 200.* fCm)));
  
  // Subtraction
  //
  ISolid* subtractionS
    = fFactory->CreateSubtractionSolid(
                  "subtraction_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(rot2, tr2)); 
  IVolume* subtractionV
    = fFactory->CreateVolume("subtraction_solid1_solid2", subtractionS, "Basic");

  fFactory->CreatePlacement("subtraction_solid1_solid2", 0, subtractionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector(0., 0., 200.* fCm)));
  
  // Union
  //
  ISolid* unionS
    = fFactory->CreateUnionSolid(
                  "union_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(rot2, tr2)); 
  IVolume* unionV
    = fFactory->CreateVolume("union_solid1_solid2", unionS, "Basic");

  fFactory->CreatePlacement("union_solid1_solid2", 0, unionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector( 250.*fCm, 0., 200.* fCm)));
  
  return (void*) fFactory->Top();
}

//_____________________________________________________________________________
void* TstGeometryViaVGM::TestBooleanSolids3()
{
// Translation + rotation in solid displacement

  IVolume* worldV = CreateWorld(400.*fCm, 100.*fCm, 400.*fCm);
  fFactory->CreatePlacement("world", 0, worldV, 0, ClhepVGM::Identity());
  
  // Create solids
  ISolid* solid1 
    = fFactory->CreateBox("boxS", 50.* fCm, 50.* fCm, 50.* fCm);

  ISolid* solid2 
    = fFactory->CreateCons("consS", 
                         10.* fCm, 30.* fCm, 20.* fCm, 40.* fCm, 100.* fCm, 
			 0., 360.* fDeg) ;
    
  // Simple solids placed for a control
  //
  IVolume* volume1
    = fFactory->CreateVolume("solid1", solid1, "Basic");
  fFactory->CreatePlacement("solid1", 0, volume1, worldV, 
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector(-125.*fCm, 0., -200.* fCm)));

  IVolume* volume2
    = fFactory->CreateVolume("solid2", solid2, "Basic");
  fFactory->CreatePlacement("solid2", 0, volume2, worldV, 
                            ClhepVGM::Transform(
			      CLHEP::HepRotation(), 
			      CLHEP::Hep3Vector( 125.*fCm, 0., -200.* fCm)));


  // Define displacement transformations
  //
 
  // Rotate solid1  
  CLHEP::HepRotation rot1;
  rot1.rotateY( 45.* deg);

  // Rotate + translate solid2
  //
  HepGeom::ReflectZ3D reflect2 = HepGeom::ReflectZ3D();
  HepGeom::Translate3D translate2 = HepGeom::Translate3D(20.* fCm, 0., 0.);
  HepGeom::Rotate3D  rotInv1 =  HepGeom::RotateY3D( -45.* deg);
  HepGeom::Transform3D transform2 =  rotInv1 * translate2 * reflect2;
  
  // Intersection
  //
  ISolid* intersectionS
    = fFactory->CreateIntersectionSolid(
                  "intersection_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(transform2)); 
  IVolume* intersectionV
    = fFactory->CreateVolume("intersection_solid1_solid2", intersectionS, "Basic");

  fFactory->CreatePlacement("intersection_solid1_solid2", 0, intersectionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector(-250.*fCm, 0., 200.* fCm)));
  
  // Subtraction
  //
  ISolid* subtractionS
    = fFactory->CreateSubtractionSolid(
                  "subtraction_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(transform2)); 
  IVolume* subtractionV
    = fFactory->CreateVolume("subtraction_solid1_solid2", subtractionS, "Basic");

  fFactory->CreatePlacement("subtraction_solid1_solid2", 0, subtractionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector(0., 0., 200.* fCm)));
  
  // Union
  //
  ISolid* unionS
    = fFactory->CreateUnionSolid(
                  "union_solid1_solid2_S", solid1, solid2, 
		  ClhepVGM::Transform(transform2)); 

  IVolume* unionV
    = fFactory->CreateVolume("union_solid1_solid2", unionS, "Basic");

  fFactory->CreatePlacement("union_solid1_solid2", 0, unionV, worldV, 
                            ClhepVGM::Transform(
			      rot1, CLHEP::Hep3Vector( 250.*fCm, 0., 200.* fCm)));
  
  return (void*) fFactory->Top();
  return 0;
}
