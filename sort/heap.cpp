#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

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
    h->data[0] = h->data[h->last--];
    int i = 0;
    while(i <= h->last/2){
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

std::vector<int> heap_sort(std::vector<int> array){
    std::vector<int> res;
    Heap p;

    for(int i=0; i<array.size(); i++){
        insert(&p, array[i]);
    }

    for(int i=0; i<array.size(); i++){
        res.push_back(delete_min(&p));
    }

    return res;
}

int main(void){
    std::vector<int> array = {2, 5, 9, 4, 2, 1, 7, 8};
    std::vector<int> res = heap_sort(array);
    for(int i=0; i<res.size(); i++){
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}