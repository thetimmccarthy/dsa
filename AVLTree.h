#pragma once
#include "TreeNode.h"
#include <iostream>

class AVLTree {
  public:
    TreeNode* root;
    TreeNode* find(int val);
    TreeNode* _find(int val, TreeNode* head);
    void insert(int val);
    TreeNode* _insert(int val, TreeNode* node);
    void update(TreeNode* node);
    TreeNode* balance(TreeNode* node);
    TreeNode* rightRotation(TreeNode* node);
    TreeNode* leftRotation(TreeNode* node);
    TreeNode* rightLeftRotation(TreeNode* node);
    TreeNode* leftRightRotation(TreeNode* node);

    void breadthFirstTraversal();
    
};
