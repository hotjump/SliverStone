#include <gtest/gtest.h>

#include <vector>

class MoveZero {
 public:
  static void method(std::vector<int>& nums) {
    int zero_count = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zero_count++;
      } else if (zero_count > 0) {
        nums[i - zero_count] = nums[i];
      }
    }
    for (size_t i = nums.size() - zero_count; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};

TEST(MoveZeroTest, Test1) {
  std::vector<int> test_array = {0, 1, 0, 3, 12};
  MoveZero::method(test_array);
  for (auto&& i : test_array) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}