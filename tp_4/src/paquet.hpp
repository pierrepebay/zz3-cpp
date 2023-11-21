#include <vector>
#include <memory>
#include <iostream>

#include "carte.hpp"
#include "usine.hpp"

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t& paquet, UsineCarte& usine) {
  std::unique_ptr<Carte> carte;
  while ((carte = usine.getCarte()) != nullptr) {
    paquet.push_back(std::move(carte));
  }
}

std::ostream& operator<<(std::ostream& flux, const paquet_t& paquet) {
  for (const auto& carte : paquet) {
    flux << carte->getValeur() << " ";
  }
  return flux;
}