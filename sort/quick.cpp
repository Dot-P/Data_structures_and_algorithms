#include<stdio.h>
#include<iostream>

int find_pivot(int *arr, int i, int j){
    while(i<j){
        if(arr[j]!=arr[i]){
            return std::max(arr[i], arr[j]);
        }
        i++;
    }
    return -1;
}

int partition(int *arr, int l, int r, int pivot){
    while(true){
        while(arr[l]<pivot) l++;
        while(arr[r]>=pivot) r--;
        if(l > r) return l;
        std::swap(arr[l], arr[r]);
    }
}

void quick_sort(int *array, int i, int j){
    if(i>=j) return;
    int pivot = find_pivot(array, i, j);
    if(pivot == -1) return;
    int k = partition(array, i, j, pivot);
    quick_sort(array, i, k-1);
    quick_sort(array, k, j);
}

int main(void){
    int array[8] = {2, 5, 9, 4, 2, 1, 7, 8};
    quick_sort(array, 0, 7);
    for(int i=0; i<8; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}