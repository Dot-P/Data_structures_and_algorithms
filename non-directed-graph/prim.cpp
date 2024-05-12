#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#define INT_MAX 1e8

int prim(std::vector<std::pair<int, int>> *G, int n) {
    int cost = 0;
    std::vector<int> cur(n, INT_MAX);
    std::vector<bool> included(n, false);

    cur[0] = 0;  

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!included[i] && (u == -1 || cur[i] < cur[u])) {
                u = i;
            }
        }

        included[u] = true;  
        cost += cur[u];  

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!included[v] && cur[v] > weight) {
                cur[v] = weight;
            }
        }
    }
    return cost;
}

int main(void){

    std::vector<std::pair<int, int>> G[6];
    G[0].push_back(std::make_pair(1, 1));
    G[0].push_back(std::make_pair(2, 3));
    G[0].push_back(std::make_pair(3, 8));
    G[1].push_back(std::make_pair(0, 1));
    G[1].push_back(std::make_pair(2, 4));
    G[1].push_back(std::make_pair(4, 5));
    G[2].push_back(std::make_pair(0, 3));
    G[2].push_back(std::make_pair(1, 4));
    G[2].push_back(std::make_pair(3, 9));
    G[2].push_back(std::make_pair(4, 6));
    G[2].push_back(std::make_pair(5, 7));
    G[3].push_back(std::make_pair(0, 8));
    G[3].push_back(std::make_pair(2, 9));
    G[3].push_back(std::make_pair(5, 7));
    G[4].push_back(std::make_pair(1, 5));
    G[4].push_back(std::make_pair(2, 6));
    G[4].push_back(std::make_pair(5, 10));
    G[5].push_back(std::make_pair(2, 7));
    G[5].push_back(std::make_pair(3, 2));
    G[5].push_back(std::make_pair(4, 10));

    std::cout << prim(G, 6) << std::endl;

    return 0;
}