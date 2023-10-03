#ifndef TP1_POLAR_HPP
#define TP1_POLAR_HPP

#include "point.hpp"
// #include "cartesian.hpp"

class Polar : public Point
{
public:
  Polar()
  : phi_coord_(0.0),
    r_coord_(0.0)
  { }
  Polar(
    double phi,
    double r
  ) : phi_coord_(phi),
      r_coord_(r)
  { }

  double getAngle() const { return phi_coord_; }
  double getDistance() const { return r_coord_; }
  void setAngle(double phi) { phi_coord_ = phi; }
  void setDistance(double r) { r_coord_ = r; }

  void display(std::ostream & stream) const override {
    stream << "(a=" << phi_coord_ << ";d=" << r_coord_ << ")";
  }

  // void convert(Cartesian & c) const {
  //   c.setX(r_coord_ * std::cos(phi_coord_ * M_PI / 180));
  //   c.setY(r_coord_ * std::sin(phi_coord_ * M_PI / 180));
  // }
private:
  double phi_coord_;
  double r_coord_;
};

#endif /*TP1_POLAR_HPP*/