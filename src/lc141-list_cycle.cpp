#include <gtest/gtest.h>

#include <memory>

#include "listnode.h"

class ListCycle {
 public:
  static bool method(ListNode *head) {
    auto slow = head;
    auto fast = head->next;
    while (slow != fast) {
      /* code */
      if (!fast && !fast->next) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
};

TEST(ListCycleTest, Test1) {
  ListNode list[] = {
      ListNode(0, &list[1]), ListNode(0, &list[2]), ListNode(0, &list[3]),
      ListNode(0, &list[4]), ListNode(0, &list[5]), ListNode(0, &list[6]),
      ListNode(0, &list[2]),
  };
  bool res = ListCycle::method(list);
  std::cout << res << std::endl;
}