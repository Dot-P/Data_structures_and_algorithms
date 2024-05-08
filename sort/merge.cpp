#include<stdio.h>
#include<iostream>
#include<vector>

std::vector<int> merge(std::vector<int> array0, std::vector<int> array1){
    std::vector<int> res;
    int i=0, j=0;
    while(!(i == array0.size() and j == array1.size())){
        if(i < array0.size() and (j >= array1.size() or array0[i] < array1[j])){
            res.push_back(array0[i]);
            i++;
        }
        if(j < array1.size() and (i >= array0.size() or array0[i] >= array1[j])){
            res.push_back(array1[j]);
            j++;
        }
    }
    return res;
}

std::vector<int> merge_sort(std::vector<int> array){
    if(array.size()<=1) return array;
    std::vector<int> array0(array.begin(), array.begin()+array.size()/2);
    std::vector<int> array1(array.begin() + array.size() / 2 , array.end());
    array0 = merge_sort(array0);
    array1 = merge_sort(array1);
    return merge(array0, array1);
}

int main(void){
    std::vector<int> array = {2, 5, 9, 4, 2, 1, 7, 8};
    std::vector<int> res = merge_sort(array);
    for(int i=0; i<res.size(); i++){
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}