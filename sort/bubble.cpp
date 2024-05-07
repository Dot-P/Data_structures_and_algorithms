#include<stdio.h>
#include<iostream>

void bubble_sort(int *array){
    for(int i=0; i<8; i++){
        for(int j=0; j<8-i-1; j++){
            if(array[j] >= array[j+1]) std::swap(array[j], array[j+1]);
        }
    }
}

int main(void){
    int array[8] = {2, 5, 9, 4, 2, 1, 7, 8};
    bubble_sort(array);
    for(int i=0; i<8; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}