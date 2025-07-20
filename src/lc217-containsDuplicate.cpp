#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

class ContainsDuplicate {
 public:
  static bool method(std::vector<int> &nums) {
    std::unordered_set<int> seen;
    for (const auto &num : nums) {
      if (seen.count(num) > 0) {
        return true;
      }
      seen.emplace(num);
    }
    return false;
  }
};

TEST(ContainsDuplicate, Test1) {
  std::vector<int> nums = {1, 2, 3, 1};
  EXPECT_TRUE(ContainsDuplicate::method(nums));
}

TEST(ContainsDuplicate, Test2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_FALSE(ContainsDuplicate::method(nums));
}