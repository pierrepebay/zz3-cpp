#ifndef TP2_POINT_HPP
#define TP2_POINT_HPP

#include <cstdint>
#include <iostream>
#include <cmath>

class Cartesian;
class Polar;

class Point
{
public:
  virtual void display(std::ostream & stream) const = 0;
  virtual void convert(Cartesian&) const = 0;
  virtual void convert(Polar&) const = 0;

  // clone function
  virtual Point* clone() const = 0;

  virtual ~Point() = default;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif /*TP2_POINT_HPP*/
