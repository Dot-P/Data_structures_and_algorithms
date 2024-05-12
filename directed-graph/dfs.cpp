#include<stdio.h>
#include<iostream>
#include<vector>

void dfs(std::vector<int> *G, int v, std::vector<bool> &visited, std::vector<int> &sorted){
    if(visited[v] == true) return;
    visited[v] = true;
    for(int i=0; i<G[v].size(); i++){
        dfs(G, G[v][i], visited, sorted);
    }
    sorted.push_back(v);
}

void dfs_all(std::vector<int> *G, std::vector<bool> &visited, std::vector<int> &sorted){
    for(int i=0; i<6; i++){
        dfs(G, i , visited, sorted);
    }
}

// トポロジカルソート
int main(void){
    std::vector<int> G[6];
    std::vector<int> sorted;
    std::vector<bool>visited(6, false);
    G[0].push_back(1);
    G[0].push_back(3);
    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(4);
    G[3].push_back(5);
    G[4].push_back(5);

    dfs_all(G, visited, sorted);

    for(int i=sorted.size()-1; i>=0; i--){
        std::cout << sorted[i] << std::endl;
    }
}