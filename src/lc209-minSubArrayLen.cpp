#include <gtest/gtest.h>

#include <iostream>
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

  static int method2(std::vector<int> &nums, int target) {
    int min_len = nums.size() + 1;
    std::vector<int> prefix_sum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); i++) {
      prefix_sum[i] += prefix_sum[i - 1] + nums[i - 1];
      std::cout << prefix_sum[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < nums.size(); i++) {
      int target_sum = prefix_sum[i] + target;
      auto it = std::lower_bound(prefix_sum.begin() + i + 1, prefix_sum.end(),
                                 target_sum);
      if (it != prefix_sum.end()) {
        int j = it - prefix_sum.begin();
        min_len = std::min(min_len, j - i);
      }
    }
    return min_len > nums.size() ? 0 : min_len;
  }
};

TEST(MinSubArrayLenTest, Test1) {
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  EXPECT_EQ(2, MinSubArrayLen::method(nums, 7));
  EXPECT_EQ(2, MinSubArrayLen::method2(nums, 7));
}

TEST(MinSubArrayLenTest, Test2) {
  std::vector<int> nums = {1, 4, 4};
  EXPECT_EQ(1, MinSubArrayLen::method(nums, 4));
  EXPECT_EQ(1, MinSubArrayLen::method2(nums, 4));
}

TEST(MinSubArrayLenTest, Test3) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(0, MinSubArrayLen::method(nums, 11));
  EXPECT_EQ(0, MinSubArrayLen::method2(nums, 11));
}