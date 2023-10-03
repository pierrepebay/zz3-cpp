#ifndef TP1_POLAR_HPP
#define TP1_POLAR_HPP

#include "point.hpp"

class Polar : Point
{
public:
  Polar(
    double phi,
    double r
  ) : phi_coord_(phi),
      r_coord_(r)
  { }
private:
  double phi_coord_;
  double r_coord_;
};

#endif /*TP1_POLAR_HPP*/