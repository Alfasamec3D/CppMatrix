#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>

#include "matrix.hpp"

struct TestCase {
  std::vector<int> input;
  int expected;
};

std::vector<TestCase> load_tests(const std::string& directory) {
  namespace fs = std::filesystem;

  std::vector<TestCase> tests;

  for (const auto& entry : fs::directory_iterator(directory)) {
    if (entry.path().extension() == ".dat") {
      std::string base = entry.path().stem().string();
      fs::path ans_path = entry.path().parent_path() / (base + ".ans");

      if (!fs::exists(ans_path)) continue;

      std::ifstream dat(entry.path());
      std::ifstream ans(ans_path);

      std::vector<int> input;
      int x;
      while (dat >> x) input.push_back(x);

      int expected;
      ans >> expected;

      tests.push_back({input, expected});
    }
  }

  return tests;
}

class ResultTest : public ::testing::TestWithParam<TestCase> {};

TEST_P(ResultTest, WorksCorrectly) {
  const TestCase& t = GetParam();
  EXPECT_EQ(Linalg::result(t.input), t.expected);
}

INSTANTIATE_TEST_SUITE_P(FileTests, ResultTest,
                         ::testing::ValuesIn(load_tests("test/tests")));