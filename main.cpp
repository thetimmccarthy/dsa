#include <iostream>
#include "AVLTree.h"

int main () {
    AVLTree* tree = new AVLTree();
    
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->breadthFirstTraversal();

    delete tree;
    tree = NULL;
    return 0;
}