// Copyright (c) 2019, Pei Xingxin
// Filename:  deque.cc
// Description:
// Created:  05/25/2019 16:33:50
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) -> bool {
      return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) q.push(lists[i]);
    }
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    while (!q.empty()) {
      ListNode* t = q.top();
      q.pop();
      if (current != nullptr) {
        current->next = t;
      }
      current = t;
      if (head == nullptr) head = current;
      if (t->next != nullptr) q.push(t->next);
    }
    return head;
  }
};
