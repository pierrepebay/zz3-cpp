#ifndef TP4_USINE_HPP
#define TP4_USINE_HPP

#include <memory>
#include "carte.hpp"

class UsineCarte {
private:
  uint64_t compteurCartes_ = 0;
  uint64_t maxCartes_ = 52;
public:
  std::unique_ptr<Carte> getCarte() {
    if (compteurCartes_ < maxCartes_) {
      return std::unique_ptr<Carte>(new Carte(compteurCartes_++));
    } else {
      return nullptr;
    }
  }

  UsineCarte() {}
  UsineCarte(uint64_t n) : maxCartes_(n) {}

  // ban copy
  UsineCarte(const UsineCarte&) = delete;
  UsineCarte& operator=(const UsineCarte&) = delete;
};

#endif // TP4_USINE_HPP
