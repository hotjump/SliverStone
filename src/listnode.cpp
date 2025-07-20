#include "listnode.h"
#include <iostream>

ListNode *CreateList(std::vector<int> arr) {
  if (arr.size() == 0) {
    return nullptr;
  }
  auto head = new ListNode(arr[0]);
  auto tail = head;

  for (size_t i = 1; i < arr.size(); i++) {
    auto node = new ListNode(arr[i]);
    tail->next = node;
    tail = node;
  }
  return head;
}

ListNode *Tail(ListNode *head) {
  auto cur = head;
  while (cur) {
    if (cur->next) {
      cur = cur->next;
    } else {
      return cur;
    }
  }
  return nullptr;
}

void DestroyList(ListNode *head) {
  auto cur = head;
  while (cur) {
    auto tmp = cur;
    cur = cur->next;
    delete tmp;
  }
}

// 遍历链表
void PrintList(ListNode *head) {
  ListNode *cur = head;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;
}

ListNode *Reverse(ListNode *head) {
  ListNode *temp = nullptr, *Phead = nullptr;
  while (head != nullptr) {
    temp = head;
    head = head->next;
    temp->next = Phead;
    Phead = temp;
  }
  return Phead;
}