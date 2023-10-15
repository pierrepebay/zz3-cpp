#include <cstdlib>
#include <vector>
#include "Cartesian.hpp"
#include "Polar.hpp"

int main() {
  std::vector<Polar*> polars_with_pointer;
  std::vector<Cartesian*> cartesians_with_pointer;

  std::vector<Polar> polars;
  std::vector<Cartesian> cartesians;

  // initialize vectors
  for (int i = 0; i < 10; ++i) {
    polars_with_pointer.push_back(new Polar(i, i));
    cartesians_with_pointer.push_back(new Cartesian(i, i));
    polars.push_back(Polar(i, i));
    cartesians.push_back(Cartesian(i, i));
  }

  // print vectors
  std::cout << "polars_with_pointer:" << std::endl;
  for (auto p : polars_with_pointer) {
    p->display(std::cout);
    std::cout << std::endl;
  }
  std::cout << "cartesians_with_pointer:" << std::endl;
  for (auto c : cartesians_with_pointer) {
    c->display(std::cout);
    std::cout << std::endl;
  }
  std::cout << "polars:" << std::endl;
  for (auto p : polars) {
    p.display(std::cout);
    std::cout << std::endl;
  }
  std::cout << "cartesians:" << std::endl;
  for (auto c : cartesians) {
    c.display(std::cout);
    std::cout << std::endl;
  }
  // free memory
  for (auto p : polars_with_pointer) {
    delete p;
  }
  for (auto c : cartesians_with_pointer) {
    delete c;
  }
 return EXIT_SUCCESS;
}
