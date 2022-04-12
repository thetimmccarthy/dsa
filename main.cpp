#include <iostream>
#include "AVLTree.h"
#include "AVLTree.cpp"

int main () {
    AVLTree<int>* tree = new AVLTree<int>();
    
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->breadthFirstTraversal();

    delete tree;
    tree = NULL;
    return 0;
}