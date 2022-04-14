#pragma once
#include "TreeNode.h"
#include "ListNode.h"
#include <iostream>
template <class T>
class AVLTree {
  public:
    TreeNode<T>* root;
    TreeNode<T>* find(T val);
    TreeNode<T>* _find(T val, TreeNode<T>* node);
    TreeNode<T>* findParent(T val);
    TreeNode<T>* _findParent(T val, TreeNode<T>* node);
    void insert(T val);
    TreeNode<T>* _insert(T val, TreeNode<T>* node);
    void insertIntoList(TreeNode<T>* newNode, TreeNode<T>* node);
    void deleteNode(T val);
    TreeNode<T>* _deleteNode(T val, TreeNode<T>* node);
    void update(TreeNode<T>* node);
    TreeNode<T>* balance(TreeNode<T>* node);
    TreeNode<T>* rightRotation(TreeNode<T>* node);
    TreeNode<T>* leftRotation(TreeNode<T>* node);
    TreeNode<T>* rightLeftRotation(TreeNode<T>* node);
    TreeNode<T>* leftRightRotation(TreeNode<T>* node);
    TreeNode<T>* iop(TreeNode<T>* node);
    void breadthFirstTraversal();
    
};
