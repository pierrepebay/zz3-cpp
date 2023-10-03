#ifndef TP1_POINT_HPP
#define TP1_POINT_HPP

#include <cstdint>
#include <iostream>
#include <cmath>

class Point
{
public:
  virtual void display(std::ostream & stream) const = 0;
  // virtual void convert(Point & p) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Point& p) {
  p.display(os);
  return os;
}

#endif /*TP1_POINT_HPP*/