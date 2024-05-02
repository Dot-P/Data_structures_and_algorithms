#include<stdio.h>
#include<iostream>

int head = -1;

void stack_push(int* A, int num){
    head++;
    if(head >= 10){
        std::cout << "Overflow" << std::endl;
        return;
    }
    A[head] = num;
}

int stack_pop(int* A){
    if(head <= 0){
        std::cout << "Segmentation fault" << std::endl;
        return -1;
    }
    head--;
    return A[head+1];
}

int main(void){
    int A[10];

    stack_push(A, 3);
    stack_push(A, 2);
    stack_push(A, 5);

    for(int i=0; i<head+1; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "pop: " << stack_pop(A) << std::endl;

    return 0;
}