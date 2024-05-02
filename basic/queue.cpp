#include<stdio.h>
#include<iostream>

int head = -1;
int tail = -1;

void enqueue(int* A, int num){
    tail++;
    if(tail >= 10){
        std::cout << "Overflow" << std::endl;
        return;
    }
    A[tail] = num;
}

int dequeue(int* A){
    if(head < -1){
        std::cout << "Segmentation fault" << std::endl;
        return -1;
    }
    head++;
    return A[head];
}

int main(void){
    int A[10];

    enqueue(A, 10);
    enqueue(A, 5);
    enqueue(A, 3);
    enqueue(A, 50);

    for(int i=0; i<tail+1; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "dequeue: " << dequeue(A) << std::endl;
    std::cout << "dequeue: " << dequeue(A) << std::endl;
    std::cout << "dequeue: " << dequeue(A) << std::endl;

    return 0;
}