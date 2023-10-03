#ifndef TP1_CARTESIAN_HPP
#define TP1_CARTESIAN_HPP

#include "point.hpp"

class Cartesian : Point
{
public:
  Cartesian() = default;
  Cartesian(
    double x,
    double y
  ) : x_coord_(x),
      y_coord_(y)
  { }

private:
  double x_coord_;
  double y_coord_;
};


#endif /*TP1_CARTESIAN_HPP*/