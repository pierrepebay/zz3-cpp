#include "Cartesian.hpp"

Cartesian::Cartesian(const Polar & p) {
  p.convert(*this);
}

void Cartesian::convert(Cartesian & c) const {
  c = (*this);
}

void Cartesian::convert(Polar & p) const {
  p.setAngle(std::atan2(y_coord_, x_coord_) * 180 / M_PI);
  p.setDistance(std::sqrt(x_coord_ * x_coord_ + y_coord_ * y_coord_));
}