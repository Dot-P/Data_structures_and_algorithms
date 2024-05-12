#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

void bfs(std::vector<int> *G, int v, std::vector<bool> &visited){
    std::queue<int> Q;
    Q.push(v);
    while(!(Q.empty())){
        int f = Q.front(); Q.pop();
        if(visited[f] == true) continue;
        visited[f] = true;
        std::cout << "visit: " << f << std::endl;
        for(int i=0; i<G[f].size(); i++){
            Q.push(G[f][i]);
        }
    }
}

void bfs_all(std::vector<int> *G, std::vector<bool> &visited, std::vector<int> &parent){
    for(int i=0; i<6; i++){
        bfs(G, i , visited);
    }
}

int main(void){
    std::vector<int> G[6];
    std::vector<int> parent;
    std::vector<bool>visited(6, false);
    G[0].push_back(1);
    G[0].push_back(3);
    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(4);
    G[3].push_back(5);
    G[4].push_back(5);

    bfs_all(G, visited, parent);

    for(int i=parent.size()-1; i>=0; i--){
        std::cout << parent[i] << std::endl;
    }
}