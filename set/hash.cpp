#include<iostream>
#include<stdio.h>

// チェイン法を用いたハッシュ法
struct Node{
    int key;
    Node *next;
};

int hash_function(int obj){
    return obj % 100;
}

void insert_node(Node *A[], int obj){
    int index = hash_function(obj);
    Node *new_node = new Node({obj, A[index]});
    A[index] = new_node;
}

void delete_node(Node *A[], int obj){
    int index = hash_function(obj);
    Node *node = A[index];
    Node *prev_node = NULL;

    while(node != NULL){
        if(node->key == obj){
            if(prev_node == NULL) {
                A[index] = node->next; // 先頭ノードの削除
                std::cout << "delete: " << node->key << std::endl;
            } else {
                prev_node->next = node->next;
                std::cout << "delete: " << node->key << std::endl;
            }
            delete node;
            return;
        }
        prev_node = node;
        node = node->next;
    }
}

int main(void){
    Node *Array[100];
    for(int i =0; i<100; i++){
        Array[i] = NULL;
    }

    insert_node(Array, 134);
    insert_node(Array, 245);
    insert_node(Array, 334);
    insert_node(Array, 1);
    insert_node(Array, 34);

    delete_node(Array, 334);
    delete_node(Array, 1);
    delete_node(Array, 34);

    return 0;
}