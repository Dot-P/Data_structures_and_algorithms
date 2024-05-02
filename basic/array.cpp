#include <stdio.h>
#include <iostream>

// O(N)
void array_pop(int *A, int n, int b){
    for(int i=b-1; i<n-1; i++){
        A[i] = A[i+1];
    }
    A[n-1] = -1;
}

// O(N)
void array_insert(int *A, int n, int b, int num){
    for(int i=n-1; i>=b-1; i--){
        A[i+1] = A[i];
    }
    A[b-1] = num;
}

int main(void){
    int A[5] = {10, 5, 2, 1, 7};
    array_pop(A, 5, 2);
    
    for(int i=0; i<5; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    array_insert(A, 5, 2, 20);

    for(int i=0; i<5; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // O(1)
    std::cout << A[2-1] << std::endl;

    

    return 0;
}