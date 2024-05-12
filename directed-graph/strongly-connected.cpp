#include<iostream>
#include<vector>
#include<algorithm>

void dfs(std::vector<int> *G, int v, std::vector<bool> &visited, std::vector<int> &sorted){
    if(visited[v]) return;
    visited[v] = true;
    for(int i=0; i<G[v].size(); i++){
        dfs(G, G[v][i], visited, sorted);
    }
    sorted.push_back(v);
}

void dfs_all(std::vector<int> *G, int numVertices, std::vector<int> &sorted){
    std::vector<bool> visited(numVertices, false);
    for(int i=0; i<numVertices; i++){
        if (!visited[i]) dfs(G, i, visited, sorted);
    }
    std::reverse(sorted.begin(), sorted.end());
}

void dfs_rev(std::vector<int> *Gr, int start, std::vector<bool> &visited){
    std::vector<int> component;
    std::vector<int> stack{start};
    visited[start] = true;
    while (!stack.empty()) {
        int v = stack.back();
        stack.pop_back();
        component.push_back(v);
        for (int nei : Gr[v]) {
            if (!visited[nei]) {
                visited[nei] = true;
                stack.push_back(nei);
            }
        }
    }

    for (int v : component) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numVertices = 5;
    std::vector<int> G[5] = {
        {1},       // 0 -> 1
        {2, 4},    // 1 -> 2, 4
        {},        // 2
        {0, 4},    // 3 -> 0, 4
        {0, 2}     // 4 -> 0, 2
    };
    std::vector<int> sorted;
    dfs_all(G, numVertices, sorted);

    std::vector<int> Gr[5];
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<G[i].size(); j++){
            Gr[G[i][j]].push_back(i);
        }
    }

    std::vector<bool> visited(numVertices, false);
    for (int v : sorted) {
        if (!visited[v]) {
            dfs_rev(Gr, v, visited);
        }
    }
}
