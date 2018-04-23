/* Uses the Wallis product to calculate PI */

#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char **argv) {
  unsigned long precision = 0;
  double half_pi = 1;
  unsigned long long numerator_factor = 2;
  unsigned long long base_factor = 1;
  bool inc = false;

  if (argc == 1) {
    std::cout << "Precision: ";
    std::cin >> precision;
  }
  else {
    precision = atoi(argv[1]);
  }
  if (precision == 0) {
    std::cout << "Invalid Precision: "
              << "Precision must be a whole integer greater or equal to 1"
              << std::endl;
    return 1;
  }

  for (unsigned long i = 0; i < precision; ++i) {
    half_pi = half_pi * numerator_factor;
    half_pi = (double) half_pi / base_factor;

    numerator_factor += 2 & -inc;
    inc ^= 1;
    base_factor += 2 & -inc;
  }

  std::cout << std::setprecision(20) << 2 * half_pi << std::endl;

  return 0;
}
