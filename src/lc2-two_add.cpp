#include <gtest/gtest.h>

#include <memory>

#include "listnode.h"

class TwoAdd {
 public:
  static ListNode *method(ListNode *list1, ListNode *list2) {
    auto dummy = std::make_unique<ListNode>(0);
    auto res = dummy.get();
    auto cur_l1 = list1;
    auto cur_l2 = list2;
    auto and_one = false;
    while (cur_l1 || cur_l2 || and_one) {
      auto num = 0;
      for (auto &l : {cur_l1, cur_l2}) {
        if (l) {
          num += l->val;
        }
      }
      if (and_one) {
        ++num;
      }
      for (auto &l : {&cur_l1, &cur_l2}) {
        if (*l) {
          *l = (*l)->next;
        }
      }
      res->next = new ListNode(num % 10);
      res = res->next;
      and_one = (num >= 10);
    }
    return dummy->next;
  }
};

TEST(TwoAddTest, Test1) {
  std::vector<int> array1 = {1, 5, 2};
  auto list1 = CreateList(array1);
  PrintList(list1);

  std::vector<int> array2 = {1, 5, 9};
  auto list2 = CreateList(array2);
  PrintList(list2);

  auto res = TwoAdd::method(list1, list2);
  PrintList(res);
}