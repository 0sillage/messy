#define debug false

#include <iostream>
#include <iomanip>

int main(void) {
  unsigned long precision = 0;
  double half_pi = 1;
  unsigned long long numerator_factor = 2;
  unsigned long long base_factor = 1;
  bool inc = false;

  std::cout << "Precision: ";
  std::cin >> precision;

  for (unsigned long i = 0; i < precision; ++i) {
    half_pi = half_pi * numerator_factor;
    half_pi = (double) half_pi / base_factor;

    numerator_factor += 2 & -inc;
    inc ^= 1;
    base_factor += 2 & -inc;
  }

  std::cout << std::setprecision(20) << 2 * half_pi << std::endl;

  // debug:
  #if debug
  std::cout << numerator_factor << std::endl;
  std::cout << base_factor << std::endl;
  #endif

  return 0;
}
