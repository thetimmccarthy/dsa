#pragma once
class ListNode {
  public:
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
      value = val;
    }
};