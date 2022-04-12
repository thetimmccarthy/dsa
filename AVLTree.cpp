#include "AVLTree.h"
#include <iostream>
#include <queue>

template <class T>
TreeNode<T>* AVLTree<T>::find(T val) {
    TreeNode<T>* head = root;
    return AVLTree<T>::_find(val, head);
  }

template <class T>
TreeNode<T>* AVLTree<T>::_find(T val, TreeNode<T>* head) {
  
    if (head == NULL) {
      return head;
    }
    if (head->value == val) {
      return head;
    } else if (head->value >= val) {
      return AVLTree<T>::_find(val, head->left);
    } else {
      return AVLTree<T>::_find(val, head->right);
    }
  }

template <class T>
void AVLTree<T>::insert(T val) {

    if (find(val) == NULL) {
        
        root = AVLTree<T>::_insert(val, root);
        // std::cout << "head val: " << root->value << std::endl;
    }
}

template <class T>
TreeNode<T>* AVLTree<T>::_insert(T val, TreeNode<T>* node) {
    
    if (node == NULL) {
        TreeNode<T>* x = new TreeNode<T>(val);
        return x;
    } else if (val < node->value) {
        node->left = _insert(val, node->left);
    } else {
        node->right = _insert(val, node->right);
    }

    AVLTree<T>::update(node);
    node = AVLTree<T>::balance(node);
    return node;
    

}

template <class T>
void AVLTree<T>::update(TreeNode<T>* node) {
    T rh = -1;
    T lh = -1;
    
    if (node->right != NULL) {
        
        rh = node->right->height;
    }

    if (node->left != NULL) {
        rh = node->left->height;
    }

    node->height = 1 + std::max(rh, lh);
    node->bf = rh - lh;
    
    

}

template <class T>
TreeNode<T>* AVLTree<T>::balance(TreeNode<T>* node) {
    T bal = node->bf;
    if (bal == -2) {
        
        if (node->left->bf < 0) {
            node = AVLTree<T>::rightRotation(node);
        } else {
            node = AVLTree<T>::leftRightRotation(node);
        }
    } else if (bal == 2) {
        if(node->right->bf > 0) {
            node = AVLTree<T>::leftRotation(node);
        } else {
            node = AVLTree<T>::rightLeftRotation(node);
        }
    } 
        return node;
}

template <class T>
TreeNode<T>* AVLTree<T>::rightRotation(TreeNode<T>* node) {
    TreeNode<T>* left = node->left;
    node->left = left->right;
    left->right = node;
    update(node);
    update(left);

    return left;
}

template <class T>
TreeNode<T>* AVLTree<T>::leftRotation(TreeNode<T>* node) {
    TreeNode<T>* right = node->right;
    node->right = right->left;
    right->left = node;

    update(node);
    update(right);

    return right;
}

template <class T>
TreeNode<T>* AVLTree<T>::leftRightRotation(TreeNode<T>* node) {
    node->left = AVLTree<T>::leftRotation(node->left);
    return AVLTree<T>::rightRotation(node);
}

template <class T>
TreeNode<T>* AVLTree<T>::rightLeftRotation(TreeNode<T>* node) {
    node->right = AVLTree<T>::rightRotation(node->right);
    return AVLTree<T>::leftRotation(node);
}

template <class T>
void AVLTree<T>::breadthFirstTraversal() {
    std::queue<TreeNode<T>*> q;

    q.push(root);

    while(!q.empty()) {
        TreeNode<T>* node = q.front();
        q.pop();
        if (node->left){
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }

        std::cout << node->value << std::endl;
    }


}
