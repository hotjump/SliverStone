
#ifndef  __LISTNODE_H__
#define  __LISTNODE_H__

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

ListNode *CreateList(std::vector<int> arr);

ListNode *Tail(ListNode *head);

void DestroyList(ListNode *head);

// 遍历链表
void PrintList(ListNode *head);

ListNode *Reverse(ListNode *head);

#endif