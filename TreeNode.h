#pragma once
#include "ListNode.h"
#include <iostream>
class TreeNode {
  public:
    int value;
    int height;  
    int bf;
    TreeNode* left;  
    TreeNode* right;
    ListNode* listPtr;
    TreeNode(int val) {
      value = val;
      height = 0;
      bf = 0;
      left = NULL;
      right = NULL;
      listPtr = NULL;
      
    }


    
};