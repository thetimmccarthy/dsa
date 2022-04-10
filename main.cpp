#include <iostream>
#include "AVLTree.h"

int main () {
    AVLTree* tree = new AVLTree();
    
    tree->insert(4);
    // std::cout << tree->root->value <<std::endl;
    tree->insert(5);
    // std::cout << tree->root->right->value <<std::endl;
    tree->insert(6);
    
    tree->breadthFirstTraversal();

    // tree->root = new TreeNode(4);
    // tree->root->right = new TreeNode(6);
    // tree->root->left = new TreeNode(2);
    
    // TreeNode* tmp = tree->find(2);
    // std::cout << tmp->value << " " << tmp << std::endl;

    delete tree;
    tree = NULL;
    return 0;
}