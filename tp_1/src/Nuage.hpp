#ifndef TP1_NUAGE_HPP
#define TP1_NUAGE_HPP

#include "Point.hpp"
#include "Cartesian.hpp"
#include "Polar.hpp"

#include <vector>
#include <iterator>

class Nuage {
public:
  Point& operator[](size_t i);
  const Point& operator[](size_t i) const;
  size_t size() const;
  void ajouter(const Point& p);
  void ajouter(Point&& p);

  using iterator = std::vector<Point*>::iterator;
  using const_iterator = std::vector<Point*>::const_iterator;
  iterator begin() { return points_.begin(); }
  const_iterator begin() const { return points_.begin(); }
  const_iterator cbegin() const { return points_.cbegin(); }

  iterator end() { return points_.end(); }
  const_iterator end() const { return points_.end(); }
  const_iterator cend() const { return points_.cend(); }

  // constructors & destructors
  Nuage() = default;
  Nuage(const Nuage&) = default;
  Nuage(Nuage&&) = default;
  Nuage& operator=(const Nuage&) = default;
  Nuage& operator=(Nuage&&) = default;
  ~Nuage();

private:
  std::vector<Point*> points_;
};

Cartesian barycentre(const Nuage& n);

// Create functor version of barycenter function, one for each type of point
class BarycentreCartesian {
public:
  Cartesian operator()(const Nuage& n) {
    return barycentre(n);
  }
};

class BarycentrePolar {
public:
  Polar operator()(const Nuage& n) {
    return barycentre(n);
  }
};

#endif /* TP1_NUAGE_HPP */
