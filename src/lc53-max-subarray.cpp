#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

class MaxSubArray {
 public:
  static int method(const std::vector<int> &nums) {
    int max_sum = 0;
    int cur_sum = 0;
    for (const auto &num : nums) {
      cur_sum += num;
      cur_sum = std::max(cur_sum, num);
      max_sum = std::max(max_sum, cur_sum);
    }
    return max_sum;
  }
};

TEST(MaxSubArrayTest, Test1) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(6, MaxSubArray::method(nums));
}

TEST(MaxSubArrayTest, Test2) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, MaxSubArray::method(nums));
}

TEST(MaxSubArrayTest, Test3) {
  std::vector<int> nums = {5, 4, -1, 7, 8};
  EXPECT_EQ(23, MaxSubArray::method(nums));
}