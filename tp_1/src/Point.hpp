#ifndef TP1_POINT_HPP
#define TP1_POINT_HPP

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
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif /*TP1_POINT_HPP*/
