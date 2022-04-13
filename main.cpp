#include <iostream>
#include "AVLTree.h"
#include "AVLTree.cpp"

int main () {
    AVLTree<int>* tree = new AVLTree<int>();
    
    tree->insert(1);
    
    tree->insert(2);
    
    tree->insert(3);
    
    tree->insert(4);
    
    tree->insert(5);
    
    tree->insert(6);
    
    tree->insert(7);
    tree->deleteNode(4);
    tree->deleteNode(2);
    tree->breadthFirstTraversal();
    std::cout << "------" << std::endl;
    tree->deleteNode(1);
    tree->breadthFirstTraversal();
    // std::cout <<tree->root->value << std::endl;
    delete tree;
    tree = NULL;
    return 0;
}