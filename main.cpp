#include"matrix.hpp"
#include<iostream>
#include<cmath>
int main() { std::vector<int> input;
  std::cin >> input[0];
  for (int i = 1; i <= std::pow(input[0], 2); ++i) std::cin >> input[i];
  std::cout<< Linalg::result(input);
  return 0;
}