/*
    백준 2533번 사회망 서비스(SNS)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> dir_graph;
std::vector<std::vector<int>> early_state;

void MakeTree(std::vector<int>& checked, int node_number) {
    
    checked[node_number] = 1;

    for(int i = 0; i < graph[node_number].size(); i++) {
        int next = graph[node_number][i];

        if(checked[next] == 1) continue;

        dir_graph[node_number].push_back(next);
        MakeTree(checked, next);
    }
}

int SearchEarlyAdapter(const int& node, const int& early) {
    
    if(early_state[node][early] != -1) {
        return early_state[node][early];
    }

    if(early == 1) {
        early_state[node][early] = 1;

        for(int i = 0; i < dir_graph[node].size(); i++) {
            int next = dir_graph[node][i];
            early_state[node][early] += std::min(SearchEarlyAdapter(next, 0),
                                                SearchEarlyAdapter(next, 1));
        }

    }
    else {
        early_state[node][early] = 0;

        for(int i = 0; i < dir_graph[node].size(); i++) {
            int next = dir_graph[node][i];
            early_state[node][early] += SearchEarlyAdapter(next, 1);
                                                
        }
    }

    return early_state[node][early];
}

int main() {
    
    std::cin >> N;

    graph.resize(N);
    dir_graph.resize(N);
    early_state.resize(N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            early_state[i].push_back(-1);
        }
    }
    
    std::vector<int> checked(N);

    for(int i = 0; i < N-1; i++) {
        int u, v;

        std::cin >> u >> v;

        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    MakeTree(checked, 0);

    std::cout << std::min(SearchEarlyAdapter(0, 0), SearchEarlyAdapter(0, 1))
            << '\n';
}