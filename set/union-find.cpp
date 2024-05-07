#include<stdio.h>
#include<iostream>

int root(int *par, int x){
    while(par[x] != -1){
        x = par[x];
    }
    return x;
}

void unite(int *par, int *siz, int x, int y){
    int rootx = root(par, x); int rooty = root(par, y);
    if(rootx == rooty) return;
    if(siz[x] > siz[y]){
        par[rooty] = rootx;
        siz[rootx] += siz[rooty];
    }
    else{
        par[rootx] = rooty;
        siz[rooty] += siz[rootx];
    }
}

bool same(int *par, int x, int y){
    return root(par, x) == root(par, y);
}

int main(void){
    int par[100];
    int siz[100];
    for(int i=0; i<100; i++){
        par[i] = -1;
        siz[i] = 1;
    }
    unite(par, siz, 1, 2);
    unite(par, siz, 3, 2);
    unite(par, siz, 0, 5);    
    unite(par, siz, 5, 10);

    std::cout <<  same(par, 1, 2)  << std::endl;
    std::cout <<  same(par, 0, 1)  << std::endl;
    std::cout <<  same(par, 0, 5)  << std::endl;
    std::cout <<  same(par, 1, 3)  << std::endl;


}