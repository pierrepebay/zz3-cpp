#include "Point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& p) {
  p.display(os);
  return os;
}