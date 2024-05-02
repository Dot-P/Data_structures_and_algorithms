// 本来は、先頭や末尾で例外処理が発生するが学習のため、問わないものとする。
#include<iostream>
#include<stdio.h>

struct List {
    int key;
    List *next;
};

void list_pop(List *list, int delete_num){
    delete_num--;
    list[delete_num-1].next = &list[delete_num+1];
}

void list_insert(List *list, int insert_num, int tar){
    insert_num--;
    list[6] = {tar, &list[insert_num+1]};
    list[insert_num-1].next = &list[6];
}

int main(void){
    int A[7] = {10, 5, 2, 1, 7};
    List list[7]; 
    for(int i=0; i<5; i++){
        list[i] = {A[i], &list[i+1]};
        if(i==4) list[i].next = NULL;
    }

    list_pop(list, 3);

    List *p = &list[0];
    while(p != NULL){
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;

    list_insert(list, 3, 100);

    p = &list[0];
    while(p != NULL){
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;


}