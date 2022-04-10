#include "AVLTree.h"
#include <iostream>
#include <queue>

TreeNode* AVLTree::find(int val) {
    TreeNode* head = root;
    return AVLTree::_find(val, head);
  }

TreeNode* AVLTree::_find(int val, TreeNode* head) {
  
    if (head == NULL) {
      return head;
    }
    if (head->value == val) {
      return head;
    } else if (head->value >= val) {
      return AVLTree::_find(val, head->left);
    } else {
      return AVLTree::_find(val, head->right);
    }
  }

void AVLTree::insert(int val) {

    if (find(val) == NULL) {
        
        root = AVLTree::_insert(val, root);
        // std::cout << "head val: " << root->value << std::endl;
    }
}
TreeNode* AVLTree::_insert(int val, TreeNode* node) {
    
    if (node == NULL) {
        TreeNode* x = new TreeNode(val);
        return x;
    } else if (val < node->value) {
        node->left = _insert(val, node->left);
    } else {
        node->right = _insert(val, node->right);
    }

    AVLTree::update(node);
    node = AVLTree::balance(node);
    return node;
    

}

void AVLTree::update(TreeNode* node) {
    int rh = -1;
    int lh = -1;
    
    if (node->right != NULL) {
        
        rh = node->right->height;
    }

    if (node->left != NULL) {
        rh = node->left->height;
    }

    node->height = 1 + std::max(rh, lh);
    node->bf = rh - lh;
    
    

}

 TreeNode* AVLTree::balance(TreeNode* node) {
    int bal = node->bf;
    if (bal == -2) {
        
        if (node->left->bf < 0) {
            node = AVLTree::rightRotation(node);
        } else {
            node = AVLTree::leftRightRotation(node);
        }
    } else if (bal == 2) {
        if(node->right->bf > 0) {
            node = AVLTree::leftRotation(node);
        } else {
            node = AVLTree::rightLeftRotation(node);
        }
    } 
    return node;
}

TreeNode* AVLTree::rightRotation(TreeNode* node) {
    TreeNode* left = node->left;
    node->left = left->right;
    left->right = node;
    update(node);
    update(left);
    
    return left;
}

TreeNode* AVLTree::leftRotation(TreeNode* node) {
    TreeNode* right = node->right;
    node->right = right->left;
    right->left = node;
    
    update(node);
    update(right);
    
    return right;
}

TreeNode* AVLTree::leftRightRotation(TreeNode* node) {
    node->left = AVLTree::leftRotation(node->left);
    return AVLTree::rightRotation(node);
}

TreeNode* AVLTree::rightLeftRotation(TreeNode* node) {
    node->right = AVLTree::rightRotation(node->right);
    return AVLTree::leftRotation(node);
}

void AVLTree::breadthFirstTraversal() {
    std::queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
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
