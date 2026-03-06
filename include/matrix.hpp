#pragma once
#include <stdexcept>
#include <vector>
namespace Linalg {
template <typename T>
class Matrix {
  size_t rows_ = 0, cols_ = 0;
  T** data_ = nullptr;

 public:
  Matrix(const size_t& rows, const size_t& cols) : rows_(rows), cols_(cols) {}
  template <typename It>
  Matrix(const int& rows, const int& cols, It start, It finish)
      : rows_(rows), cols_(cols) {
    if (std::distance(start, finish) < rows_ * cols_)
      throw std::invalid_argument(
          "Not enough elements in container for matrix");
    data_ = new T*[rows_];
    It iterator = start;

    for (size_t i = 0; i < rows_; ++i) {
      data_[i] = new T[cols_];
      for (size_t j = 0; j < cols_; ++j) {
        data_[i][j] = *iterator++;
      }
    }
  }
  T determinant() const {
    if (rows_ != cols_)
      throw std::logic_error(
          "Impossible to count determinant for non square matrix");
    const double epsilon = 0.000001;
    T det = 1;
    Matrix matrix_copy = *this;
    for (size_t row = 0; row < rows_; ++row) {
      // The first index is column
      if (abs(matrix_copy.data_[row][row]) < epsilon) {
        bool swapped = false;
        for (size_t col = row + 1; col < rows_; ++col) {
          if (abs(matrix_copy.data_[col][row]) >= epsilon) {
            T* temp = matrix_copy.data_[row];
            matrix_copy.data_[row] = matrix_copy.data_[col];
            matrix_copy.data_[col] = temp;
            det *= -1;
            swapped = true;
            break;
          }
        }
        if (!swapped) return 0;
      }
      det *= matrix_copy.data_[row][row];
      for (size_t lower_row = row + 1; lower_row < rows_; ++lower_row) {
        for (size_t col = row + 1; col < rows_; ++col) {
          matrix_copy.data_[col][lower_row] -=
              matrix_copy.data_[col][row] * matrix_copy.data_[row][lower_row] /
              matrix_copy.data_[row][row];
        }
      }
    }
    return det;
  }
};

int result(const std::vector<int>& input);

}  // namespace Linalg