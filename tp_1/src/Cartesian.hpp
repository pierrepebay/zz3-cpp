#ifndef TP1_CARTESIAN_HPP
#define TP1_CARTESIAN_HPP

#include "Point.hpp"
#include "Polar.hpp"
class Polar;

class Cartesian : public Point
{
public:
  Cartesian()
  : x_coord_(0.0),
    y_coord_(0.0)
  { }
  Cartesian(
    double x,
    double y
  ) : x_coord_(x),
      y_coord_(y)
  { }
  Cartesian(const Polar & p);

  double getX() const { return x_coord_; }
  double getY() const { return y_coord_; }
  void setX(double x) { x_coord_ = x; }
  void setY(double y) { y_coord_ = y; }

  void convert(Cartesian&) const override;
  void convert(Polar&) const override;

  void display(std::ostream & stream) const override {
    stream << "(x=" << x_coord_ << ";y=" << y_coord_ << ")";
  }

private:
  double x_coord_;
  double y_coord_;
};


#endif /*TP1_CARTESIAN_HPP*/
