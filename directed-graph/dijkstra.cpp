#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

int main(void){
    std::vector<std::vector<int>> G(4, std::vector<int>(4, 100000000));
    std::vector<int> cur(4, 100000000);
    std::vector<int> end(4, false);
    G[0][1] = 6;
    G[0][2] = 1;
    G[1][3] = 1;
    G[2][1] = 2;
    G[2][3] = 4;

    // curとindexを格納
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> Q;
    cur[0] = 0;
    Q.push(std::make_pair(0,0));
    while(!Q.empty()){
        std::pair<int, int> x = Q.top();
        Q.pop();
        if(end[x.second] == true) continue;
        end[x.second] = true;
        for(int i=0; i<G[x.second].size(); i++){
            if (x.first + G[x.second][i] < cur[i]){
                cur[i] = x.first + G[x.second][i];
                Q.push(std::make_pair(cur[i], i));
            }
        }
    }

    for(int i=0; i<4; i++){
        std::cout << cur[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
