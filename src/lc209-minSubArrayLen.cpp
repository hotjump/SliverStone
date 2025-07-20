#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

class MinSubArrayLen {
 public:
  static int method(std::vector<int> &nums, int target) {
    int len = 0;
    int min_len = nums.size() + 1;
    int left = 0;
    int cur_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur_sum += nums[i];
      while (cur_sum >= target) {
        len = i - left + 1;
        min_len = std::min(min_len, len);
        cur_sum -= nums[left];
        left++;
      }
    }
    return len;
  }
};

TEST(MinSubArrayLenTest, Test1) {
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  EXPECT_EQ(2, MinSubArrayLen::method(nums, 7));
}

TEST(MinSubArrayLenTest, Test2) {
  std::vector<int> nums = {1, 4, 4};
  EXPECT_EQ(1, MinSubArrayLen::method(nums, 4));
}

TEST(MinSubArrayLenTest, Test3) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(0, MinSubArrayLen::method(nums, 11));
}