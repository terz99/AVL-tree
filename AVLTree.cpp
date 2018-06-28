//
// Created by dushan on 26.06.18.
//

#include "AVLTree.h"
#include <bits/stdc++.h>

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::insert(const int &data) {
    root = insertUtil(root, data);
}

AVLTree::Node *AVLTree::insertUtil(AVLTree::Node *p, const int &data) {

    if(!p){
        return p = new Node(data);
    }

    if(data < p->data){
        p->left = insertUtil(p->left, data);
    } else if(data > p->data){
        p->right = insertUtil(p->right, data);
    } else {
        return p;
    }

    p->height = std::max(get_height(p->left), get_height(p->right)) + 1;

    return balance_node(p, data);
}

int AVLTree::get_height(AVLTree::Node *p) {
    if(!p) return 0;
    return p->height;
}

int AVLTree::get_balance(AVLTree::Node *p) {
    if(!p) return 0;
    return get_height(p->left) - get_height(p->right);
}

AVLTree::Node *AVLTree::left_rotate(AVLTree::Node *y) {

    Node *x = y->right;
    Node *z = x->left;

    x->left = y;
    y->right = z;

    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

    return x;
}

AVLTree::Node *AVLTree::right_rotate(AVLTree::Node *y) {

    Node *x = y->left;
    Node *z = x->right;


    x->right = y;
    y->left = z;

    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

    return x;
}

void AVLTree::in_order() {
    if(!root) return;
    in_order(root);
}

void AVLTree::in_order(AVLTree::Node *p) {
    std::cout << p->data << "\n";
    if(p->left) {
        std::cout << "Going left\n";
        in_order(p->left);
        std::cout << "Going up\n";
    }
    if(p->right){
        std::cout << "Going right\n";
        in_order(p->right);
        std::cout << "Going up\n";
    }
}

AVLTree::Node *AVLTree::removeUtil(AVLTree::Node *p, const int &data) {

    if(p == nullptr){
        return p;
    }

    if(data < p->data){
        p->left = removeUtil(p->left, data);
    } else if(data > p->data){
        p->right = removeUtil(p->right, data);
    } else {

        if(p->left == nullptr || p->right == nullptr){
            // one or no child cases
            Node* tmp = p->left ? p->left : p->right;
            if(tmp == nullptr){
                tmp = p;
                p = nullptr;
            } else {
                *p = *tmp;
            }

            delete tmp;
        } else {
            // two child cases
            Node* tmp = get_minval_node(p->right);
            p->data = tmp->data;
            p->right = removeUtil(p->right, tmp->data);
        }
    }

    if(p == nullptr){
        return p;
    }

    p->height = 1 + std::max(get_height(p->left), get_height(p->right));

    return balance_node(p, data);
}

void AVLTree::remove(const int &data) {
    root = removeUtil(root, data);
}

AVLTree::Node *AVLTree::get_minval_node(AVLTree::Node *p) {
    if(p->left == nullptr) return p;
    return get_minval_node(p->left);
}

AVLTree::Node *AVLTree::balance_node(AVLTree::Node *p, const int& data) {
    int balance = get_balance(p);

    if(balance > 1){

        /**
         * Left-left case, rotate right
         */
        if(data < p->left->data){
            return right_rotate(p);
        } else {
            /**
             * Left-right case, rotate left, then right
             */
            p->left = left_rotate(p->left);
            return right_rotate(p);
        }
    } else if(balance < -1){
        if(data < p->right->data){
            /**
             * Right-left case, rotate right, then left
             */
            p->right = right_rotate(p->right);
            return left_rotate(p);
        } else {
            /**
             * Right-right case, rotate left
             */
            return left_rotate(p);
        }
    }
    return p;
}


