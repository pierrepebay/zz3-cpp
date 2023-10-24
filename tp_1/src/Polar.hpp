#ifndef TP1_POLAR_HPP
#define TP1_POLAR_HPP

#include "Point.hpp"
#include "Cartesian.hpp"
class Cartesian;

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
  Polar(const Cartesian & c);
  // copy constructor
  Polar(const Polar&) = default;
  // move constructor
  Polar(Polar&&) = default;
  // copy assignment
  Polar& operator=(const Polar&) = default;
  // move assignment
  Polar& operator=(Polar&&) = default;
  // destructor
  ~Polar() = default;

  // override clone function
  Point* clone() const override {
    return new Polar(*this);
  }

  double getAngle() const { return phi_coord_; }
  double getDistance() const { return r_coord_; }
  void setAngle(double phi) { phi_coord_ = phi; }
  void setDistance(double r) { r_coord_ = r; }

  void display(std::ostream & stream) const override {
    stream << "(a=" << phi_coord_ << ";d=" << r_coord_ << ")";
  }

  void convert(Polar&) const override;

  void convert(Cartesian&) const override;

private:
  double phi_coord_;
  double r_coord_;
};

#endif /*TP1_POLAR_HPP*/
