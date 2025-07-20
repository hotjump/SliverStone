#include <iostream>
#include <vector>

// 定义二叉树节点结构
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据给定数组构建二叉树
TreeNode* buildTree(const std::vector<int>& values, int index) {
  if (index >= values.size() || values[index] == -1) {
    return nullptr;
  }
  TreeNode* node = new TreeNode(values[index]);
  node->left = buildTree(values, 2 * index + 1);
  node->right = buildTree(values, 2 * index + 2);
  return node;
}

// 前序遍历二叉树
void preOrderTraversal(TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  std::cout << root->val << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// 释放二叉树的内存
void destroyTree(TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  destroyTree(root->left);
  destroyTree(root->right);
  delete root;
}