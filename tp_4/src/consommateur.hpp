#ifndef TP4_CONSOMMATEUR_HPP
#define TP4_CONSOMMATEUR_HPP

#include <memory>
#include "ressource.hpp"

class Consommateur {
private:
  std::shared_ptr<Ressource> ressource_;
  uint64_t besoin_;
public:
  Consommateur(uint64_t besoin, std::shared_ptr<Ressource> ressource) : besoin_(besoin), ressource_(ressource) {}

  void puiser() {
    if (ressource_->getStock() >= besoin_) {
      ressource_->consommer(besoin_);
    } else {
      ressource_->consommer(ressource_->getStock());
      ressource_ = nullptr;
    }
  }
};

#endif // TP4_CONSOMMATEUR_HPP
