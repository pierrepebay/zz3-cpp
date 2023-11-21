#ifndef TP4_RESSOURCE_HPP
#define TP4_RESSOURCE_HPP

#include <cstdint>
#include <memory>
#include <iostream>
#include <vector>

class Ressource {
private:
  uint64_t stock_ = 0;
public:
  Ressource(uint64_t stock) : stock_(stock) {}
  void consommer(uint64_t quantite) {
    if (quantite <= stock_) {
      stock_ -= quantite;
    } else {
      stock_ = 0;
    }
  }
  uint64_t getStock() const { return stock_; }
};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream& operator<<(std::ostream& flux, const ressources_t& ressources) {
  for (const auto& ressource : ressources) {
    if (auto r = ressource.lock()) {
      flux << r->getStock() << " ";
    } else {
      flux << "- ";
    }
  }
  return flux;
}

#endif // TP4_RESSOURCE_HPP