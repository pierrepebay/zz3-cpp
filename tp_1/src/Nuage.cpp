#include "Nuage.hpp"

#include <algorithm>

Point& Nuage::operator[](size_t i) {
  return *points_[i];
}

const Point& Nuage::operator[](size_t i) const {
  return *points_[i];
}

size_t Nuage::size() const {
  return points_.size();
}

void Nuage::ajouter(const Point& p) {
  points_.push_back(p.clone());
}

void Nuage::ajouter(Point&& p) {
  points_.push_back(p.clone());
}

Nuage::~Nuage() {
  std::for_each(points_.begin(), points_.end(), [](Point* p) { delete p; });
}

// Function to compute barycenter of cloud of points
Cartesian barycentre(const Nuage& n) {
  Cartesian barycenter(0.0, 0.0);
  Cartesian tmpPoint(0.0, 0.0);
  for (size_t i = 0; i < n.size(); ++i) {
    n[i].convert(tmpPoint);
    barycenter.setX(barycenter.getX() + tmpPoint.getX());
    barycenter.setY(barycenter.getY() + tmpPoint.getY());
  }
  barycenter.setX(barycenter.getX() / n.size());
  barycenter.setY(barycenter.getY() / n.size());
  return barycenter;
}
