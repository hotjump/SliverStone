/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <gtest/gtest.h>

#include <memory>

#include "listnode.h"

class PartitionList {
 public:
  static ListNode *method(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }
    auto cur = head;
    auto less_dummy = std::make_unique<ListNode>(0);
    auto large_dummy = std::make_unique<ListNode>(0);
    auto less = less_dummy.get();
    auto large = large_dummy.get();
    while (cur) {
      auto next = cur->next;
      if (cur->val < k) {
        less->next = cur;
        less = cur;
      } else {
        large->next = cur;
        large = cur;
      }
      cur = next;
    }
    less->next = large_dummy->next;
    large->next = nullptr;
    return less_dummy->next;
  }
};

TEST(PartitionListTest, Test1) {
  std::vector<int> test_array = {1, 5, 2, 3, 6, 4};
  auto head = CreateList(test_array);
  PrintList(head);
  auto res = PartitionList::method(head, 3);
  PrintList(res);

  test_array = {1, 5, 2, 3, 6, 4};
  head = CreateList(test_array);
  PrintList(head);
  res = PartitionList::method(head, 10);
  PrintList(res);
}