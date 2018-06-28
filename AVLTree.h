//
// Created by dushan on 26.06.18.
//

#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H


class AVLTree {

    struct Node{

        int data;
        int height;
        Node *left, *right;
        Node(){
            data = 0;
            height = 1;
            left = right = nullptr;
        }
        explicit Node(const int& data){
            this->data = data;
            height = 1;
            left = right = nullptr;
        }
    };

    Node *root;

    Node* insertUtil(Node *p, const int& data);

    Node* removeUtil(Node *p, const int& data);

    int get_height(Node *p);

    int get_balance(Node *p);

    Node* left_rotate(Node *y);

    Node* right_rotate(Node *y);

    Node* get_minval_node(Node* p);

    Node* balance_node(Node* p, const int& data);

    void in_order(Node *p);

public:

    AVLTree();

    void insert(const int& data);

    void remove(const int& data);

    void in_order();
};


#endif //AVL_AVLTREE_H
