// $Id$
//
// Class Cons
// ---------------
// VGM implementation for Root cons solid.
//
// Author: Ivana Hrivnacova; IPN Orsay

#ifndef ROOT_GM_CONS_H
#define ROOT_GM_CONS_H

#include <string>

#include "TGeoCone.h"

#include "BaseVGM/solids/VCons.h"

namespace RootGM {

  class Cons : public BaseVGM::VCons
  {
    public:
      Cons(const std::string& name, 
           double rin1, double rout1, double rin2, double rout2,
	   double hz, double sphi, double dphi);
      Cons(TGeoCone* cons);
      virtual ~Cons();

      // methods
      virtual std::string Name() const;
      virtual double InnerRadiusMinusZ() const ;
      virtual double OuterRadiusMinusZ() const;
      virtual double InnerRadiusPlusZ() const;
      virtual double OuterRadiusPlusZ() const;
      virtual double ZHalfLength() const;
      virtual double StartPhi() const;
      virtual double DeltaPhi() const;

    protected:
      Cons() : BaseVGM::VCons() {}
      Cons(const Cons& rhs) : BaseVGM::VCons(rhs) {}

    private:
      TGeoCone* fCons;
  };

}

#endif //ROOT_GM_CONS_H
