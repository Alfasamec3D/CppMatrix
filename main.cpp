#include <cmath>
#include <iostream>

#include "matrix.hpp"
int main() {
  int x;
  std::vector<int> input;
  std::cin >> x;
  input.push_back(x);

  for (int i = 1; i <= std::pow(input[0], 2); ++i) {
    std::cin >> x;
    input.push_back(x);
  }
  std::cout << Linalg::result(input) << std::endl;
  return 0;
}