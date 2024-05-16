#include<stdio.h>
#include<string>
#include<iostream>
#include<map>

bool kmp(std::string text, std::string pattern){
    int skip[7] = {1, 1, 3, 2, 5, 6, 4};

    for(int i=0; i<text.size(); i++){
        for(int j=0; j<pattern.size(); j++){
            if(i+j>=text.size()) return false;
            if(text[i+j]!=pattern[j]){
                i += skip[j] - 1;
                break;
            }
            if(j == pattern.size()-1) return true;
        }
    }
    return false;
}

int main(void){
    std::string text = "abccbcbddbcbcbdbcdc";
    std::string pattern = "bcbdbcd";

    std::cout << kmp(text, pattern) << std::endl;

}