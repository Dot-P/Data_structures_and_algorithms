#include<stdio.h>
#include<iostream>
#include<vector>

bool linear_search (std::vector<int> arr, int b){
    for(int i=0; i<arr.size(); i++){
        if( arr[i] == b ) return true;
    }
    return false;
}

bool binary_search (std::vector<int> arr, int b){
    int n = arr.size() / 2;
    if(arr.size() == 0) return false;
    else if(arr[n] == b) return true;
    else if(arr[n] > b){
        arr.assign(arr.begin(), arr.begin() + n);
        return binary_search(arr, b);
    }
    else{
        arr.assign(arr.begin()+n+1, arr.end());
        return binary_search(arr, b);
    }
}

struct test{
    int n;
    bool want;
};

int main(void){
    
    std::vector<int> Arr = {1, 2, 3, 5, 6, 8, 10};
    test test1 = {3, true}; test test2 = {7, false};

    bool got = linear_search(Arr, test1.n);
    if(got != test1.want){
        std::cout << "L: Wrong Answer in Test1" << std::endl;
        return 1;
    }
    got = linear_search(Arr, test2.n);
    if(got != test2.want){
        std::cout << "L: Wrong Answer in Test2" << std::endl;
        return 1;
    }
    got = binary_search(Arr, test1.n);
    if(got != test1.want){
        std::cout << "B: Wrong Answer in Test1" << std::endl;
        return 1;
    }
    got = binary_search(Arr, test2.n);
    if(got != test2.want){
        std::cout << "B: Wrong Answer in Test2" << std::endl;
        return 1;
    }

    std::cout << "Test Successfull!" << std::endl;
    return 0;
}