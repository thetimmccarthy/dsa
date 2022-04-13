#pragma once
#include "ListNode.h"
#include <iostream>
template <class T>
class TreeNode {
  public:
    T value;
    int height;  
    int bf;
    TreeNode<T>* left;  
    TreeNode<T>* right;
    ListNode* listPtr;
    TreeNode(T val) {
      value = val;
      height = 0;
      bf = 0;
      left = NULL;
      right = NULL;
      listPtr = NULL;
      
    }
    TreeNode<T>& operator=(const TreeNode<T> & other) {
      value = other.value;
      height = other.height;
      bf = other.bf;
      left = other.left;
      right = other.right;
      listPtr = other.listPtr;
    }

    
};