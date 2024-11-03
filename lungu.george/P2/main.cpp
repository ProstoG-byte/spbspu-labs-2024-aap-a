#include <iostream>
#include <iomanip>
#include <cmath>
#include "Tylor.h"

int main() {
  const double absError = 0.001;
  int numberMax;
  double start = 0.0;
  double end = 0.0;
  const double step = 0.05;

  std::cin >> start >> end >> numberMax;

  if (!std::cin) {
    std::cerr << "Worst possible input" << "\n";
    return 1;
  } if (step <= 0) {
    std::cerr << "Step must be positive." << "\n";
    return 2;
  } if (end < start) {
    std::cerr << "Logic error" << "\n";
    return 3;
  }

  std::cout << std::fixed << std::setprecision(6);
  std::cout << std::string(10, ' ') << "X    SUMM        STDfunctionn" << "\n";

  for (double x = start; x <= end; x += step) {
    try {
      double calculatedValue = lungu::TylorFunc(x, absError, numberMax);
      double standardValue = std::exp(-x * x);

      std::cout << std::string(10, ' ') << x << "   "
                << calculatedValue << "   "
                << standardValue << "\n";
    } catch (const std::exception& e) {
      std::cout << std::string(10, ' ') << x << "   MathError" << "\n";
    }
  }

  return 0;
}