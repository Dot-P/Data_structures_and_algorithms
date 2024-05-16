#include<iostream>
#include<stdio.h>
#include<vector>

std::vector<int> G[6]={
    {1, 3},
    {0, 2, 3, 4, 5},
    {1, 5},
    {0, 1, 4},
    {1, 3},
    {1, 2}
};
int cnt=1;

void dfs(int v, bool *visited, int *num, int *low){
    visited[v] = true;
    num[v] = cnt++;
    low[v] = num[v];
    for(int i=0; i<G[v].size(); i++){
        if(visited[G[v][i]]!=true){
            dfs(G[v][i], visited, num, low);
            low[v] = std::min(low[v], low[G[v][i]]);
        }
        low[v] = std::min(low[v], num[G[v][i]]);
    }
}

int main(void){
    bool visited[6]; int num[6]; int low[6];
    for(int i=0; i<6; i++){
        visited[i] = false;
    }
    dfs(0, visited, num, low);

    for(int i=0; i<6; i++){
        for(int j=0; j<G[i].size(); j++){
            if(i!= 0 and num[i] < num[G[i][j]] and low[G[i][j]] >= num[i]){
                std::cout << "joint is " << i << std::endl; 
            }
        }
    }

    return 0;
}