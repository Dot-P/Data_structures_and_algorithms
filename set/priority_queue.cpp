#include<iostream>
#include<stdio.h>
#include<algorithm>

struct Heap{
    int data[100];
    int last = -1;
};

void insert(Heap *h, int obj){
    h->data[++h->last] = obj;
    int i = h->last;
    while(i > 0){
        if(h->data[i] < h->data[(i-1)/2]){
            std::swap(h->data[(i-1)/2], h->data[i]);
            i = (i-1)/2;
        }
        else return;
    }
}

int delete_min(Heap *h){
    int obj = h->data[0];
    h->data[0] = h->data[h->last];
    int i = 0;
    while(i < h->last/2){
        if(h->data[i] > h->data[2*i+1]){
            if(h->data[2*i+1] < h->data[2*i+2]){
                std::swap(h->data[2*i+1], h->data[i]);
                i = 2*i+1;
            }
            else{
                std::swap(h->data[2*i+2], h->data[i]);
                i = 2*i+2;
            }
        }
        else if(h->data[i] > h->data[2*i+2]){
            std::swap(h->data[i], h->data[2*i+2]);
            i = 2*i+2;
        }
        else return obj;
    }
    return obj;
}

int main(void){
    Heap p;

    insert(&p, 3);
    insert(&p, 10);
    insert(&p, 2);
    insert(&p, 100);
    insert(&p, 5);
    insert(&p, 1);

    for(int i = 0; i<6; i++){
        std::cout << p.data[i] << " ";
    }
    std::cout << std::endl;


    for(int i = 0; i<3; i++){
        std::cout << delete_min(&p) << " ";
    }
    std::cout << std::endl;

}