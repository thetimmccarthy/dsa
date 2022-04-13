#pragma once

template <class T>
class ListNode {
  public:
    T value;
    ListNode<T>* next;
    ListNode<T>* prev;

    ListNode<T>(T val) {
      value = val;
    }
};