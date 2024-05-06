#include<stdio.h>
#include<iostream>

struct Node {
    int key;
    Node *right;
    Node *left;
};

void insert_node(Node *node, int obj){
    if(obj < node->key){
        if(node->left == NULL){
            node->left = new Node({obj, NULL, NULL});
        }
        else insert_node(node->left, obj);
    }
    else{
        if(node->right == NULL){
            node->right = new Node({obj, NULL, NULL});
        }
        else insert_node(node->right, obj);
    }
}

// 実装の理解不能
Node *delete_node(Node *node, int obj){
    if(node == NULL) return NULL;
    if(obj < node->key){
        node->left = delete_node(node->left, obj);
        return node;
    }
}

int main(void){

}