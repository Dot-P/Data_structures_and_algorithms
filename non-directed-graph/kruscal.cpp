#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

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

int kruscal(std::vector<std::pair<int, int>> *G, int *par, int *siz){
    int cost = 0;
    // 重み順にしたキューを作成する。
    std::priority_queue<std::pair<int, std::pair<int, int>>> Q;
    for(int i=0; i<6; i++){
        for(int j=0; j<G[i].size(); j++){
            Q.push(std::make_pair(-1*G[i][j].second, std::make_pair(G[i][j].first, i)));
        }
    }
    // 可能であれば連結する。
    while(!Q.empty()){
        std::pair<int, std::pair<int, int>> x = Q.top(); Q.pop();
        if(same(par, x.second.first, x.second.second)) continue;
        cost += -1 * x.first;
        unite(par, siz, x.second.first, x.second.second);
    }
    return cost;
}

int main(void){
    int par[6]; int siz[6];
    for(int i=0; i<6; i++){
        par[i] = -1; siz[i] = 1;
    }

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

    std::cout << kruscal(G, par, siz) << std::endl;

    return 0;
}