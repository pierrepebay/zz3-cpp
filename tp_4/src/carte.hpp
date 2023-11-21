#ifndef TP4_CARTE_HPP
#define TP4_CARTE_HPP

#include <memory>

class Carte
{
private:
  uint64_t valeur_;
  inline static uint64_t compteurCartes_ = 0;
  Carte(uint64_t valeur) : valeur_(valeur) { ++compteurCartes_; }

  // remove unwanted constructors and assignment operators
  Carte(const Carte&) = delete;
  Carte& operator=(const Carte&) = delete;

  friend class UsineCarte;
public:
  ~Carte() { --compteurCartes_; }

  uint64_t getValeur() const { return valeur_; }
  static uint64_t getCompteur() { return compteurCartes_; }
};

#endif // TP4_CARTE_HPP
