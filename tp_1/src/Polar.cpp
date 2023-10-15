#include "Polar.hpp"

Polar::Polar(const Cartesian & c) {
  c.convert(*this);
}

void Polar::convert(Polar & p) const {
  p = (*this);
}

void Polar::convert(Cartesian & c) const {
  c.setX(r_coord_ * std::cos(phi_coord_ * M_PI / 180));
  c.setY(r_coord_ * std::sin(phi_coord_ * M_PI / 180));
}