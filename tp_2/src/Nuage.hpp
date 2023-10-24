#ifndef TP2_NUAGE_HPP
#define TP2_NUAGE_HPP

#include "Point.hpp"
#include "Cartesian.hpp"
#include "Polar.hpp"

#include <vector>
#include <memory> // for std::unique_ptr

template <typename T>
class Nuage {
public:
  using iterator = typename std::vector<std::unique_ptr<T>>::iterator;
  using const_iterator = typename std::vector<std::unique_ptr<T>>::const_iterator;

  iterator begin() { return points_.begin(); }
  const_iterator begin() const { return points_.begin(); }
  const_iterator cbegin() const { return points_.cbegin(); }

  iterator end() { return points_.end(); }
  const_iterator end() const { return points_.end(); }
  const_iterator cend() const { return points_.cend(); }

  size_t size() const { return points_.size(); }

  void ajouter(const T& p) {
    points_.push_back(std::make_unique<T>(p));
  }

  void ajouter(T&& p) {
    points_.push_back(std::make_unique<T>(std::move(p)));
  }

  T& operator[](size_t i) {
    return *points_[i];
  }

  const T& operator[](size_t i) const {
    return *points_[i];
  }

private:
  std::vector<std::unique_ptr<T>> points_;
};

#endif /* TP2_NUAGE_HPP */
