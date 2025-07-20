#include <gtest/gtest.h>

#include <map>

#include "treenode.h"

class LastCommonRoot {
 public:
  static std::pair<TreeNode*, int> commonRoot(TreeNode* root) {
    if (!root) {
      return {root, 0};
    }

    auto left = commonRoot(root->left);
    auto right = commonRoot(root->right);

    std::cout << "root: " << root->val << std::endl;
    if (left.second > right.second) {
      std::cout << "left: " << left.first->val << "height: " << left.second << std::endl;
      std::cout << "right: " << right.first->val << "height: " << right.second << std::endl;
      return {left.first, left.second + 1};
    }
    if (left.second < right.second) {
      std::cout << "left: " << left.first->val << "height: " << left.second << std::endl;
      std::cout << "right: " << right.first->val << "height: " << right.second << std::endl;
      return {right.first, right.second + 1};
    }
    return {root, left.second + 1};
  }
  static TreeNode* lcaDeepestLeaves(TreeNode* root) {
    auto res = commonRoot(root);
    return res.first;
  }
};

TEST(LastCommonRootTest, Test1) {
  std::vector<int> a = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  auto root = buildTree(a, 0);
  preOrderTraversal(root);
  std::cout << std::endl;
  auto res = LastCommonRoot::lcaDeepestLeaves(root);
  std::cout << res->val << std::endl;
}