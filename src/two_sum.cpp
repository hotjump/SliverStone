#include <gtest/gtest.h>

#include <set>
#include <vector>

class TwoSum {
 public:
  static std::vector<int> two_sum(std::vector<int> &nums, int target) {
    std::map<int, int> num_map;
    for (int i = 0; i < nums.size(); i++) {
      if (num_map.count(target - nums[i])) {
        return {num_map[target - nums[i]], i};
      }
      num_map.emplace(nums[i], i);
    }
    return {};
  }
};

TEST(TwoSumTest, Test1) {
  std::vector<int> a = {2, 7, 11, 15};
  auto ret = TwoSum::two_sum(a, 9);
  for (auto &&i : ret) {
    std::cout << i << std::endl;
  }
  std::cout << std::endl;
}