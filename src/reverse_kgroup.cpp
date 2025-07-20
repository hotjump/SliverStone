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

#include "listnode.h"

class ReverseKGroup {
 public:
  static ListNode *method(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }
    int count = 0;
    auto cur = head;
    ListNode *new_head = nullptr;
    ListNode *new_tail = nullptr;
    ListNode *cur_head = nullptr;
    ListNode *cur_tail = nullptr;
    while (cur) {
      auto next = cur->next;
      if (++count == 1) {
        cur_head = cur;
      }

      if (count == k) {
        cur_tail = cur;
        cur_tail->next = nullptr;  // 断链
        auto res = Reverse(cur_head);  // 反转链表
        if (!new_head) {
          new_head = res;
        } else {
          new_tail->next = res;
        }
        new_tail = cur_head;
        new_tail->next = next;  // 重新接上
        count = 0;
      }
      cur = next;
    }

    return new_head;
  }
};

TEST(ReverseKGroupTest, Test1) {
  std::vector<int> test_array = {1, 2, 3, 4, 5};
  auto head = CreateList(test_array);
  PrintList(head);
  auto res = ReverseKGroup::method(head, 3);
  PrintList(res);
}