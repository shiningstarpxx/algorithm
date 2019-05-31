// Copyright (c) 2019, Pei Xingxin
// Filename:  divide_conquer.cc
// Description:
// Created:  05/25/2019 16:41:59
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
    if (lists.size() == 0) return nullptr;
    if (lists.size() == 1) return lists[0];
    if (lists.size() == 2)
      return mergeTwoLists(lists[0], lists[1]);

    int mid = lists.size() / 2;
    vector<ListNode*> t1(lists.begin(), lists.begin() + mid);
    vector<ListNode*> t2(lists.begin() + mid, lists.end());
    return mergeTwoLists(mergeKLists(t1), mergeKLists(t2));
  }

  ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    while (first != nullptr && second != nullptr) {
      if (first->val < second->val) {
        if (current != nullptr) current->next = first;
        current = first;
        first = first->next;
      } else {
        if (current != nullptr) current->next = second;
        current = second;
        second = second->next;
      }
      if (head == nullptr) head = current;
    }

    while (first) {
      if (current != nullptr) current->next = first;
      current = first;
      first = first->next;
      if (head == nullptr) head = current;
    }
    while (second) {
      if (current != nullptr) current->next = second;
      current = second;
      second = second->next;
      if (head == nullptr) head = current;
    }
    return head;
  }
};
