#include "matrix.hpp"

int Linalg::result(const std::vector<int>& input) {
  
  Linalg::Matrix<int> input_matrix{input[0], input[0], std::next(input.begin()),
                                   input.end()};
  return input_matrix.determinant();
}
