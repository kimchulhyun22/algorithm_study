/*
    백준 2606번 바이러스
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


int N;
std::vector<std::vector<int>> graph;

int BFS(int start) {

    std::vector<bool> checked(N+1);
    std::queue<int> q;
    int count = 0;

    checked[start] = true;
    q.push(start);

    while(!q.empty()) {
        int current = q.front();

        q.pop();

        count++;

        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];

            if(checked[next]) continue;

            checked[next] = true;
            q.push(next);
            
        }

    }

    return count - 1;

}

int main() {
    std::cin >> N;

    graph.resize(N + 1);

    int E;

    std::cin >> E;

    for(int i = 0; i < E; i++) {
        int from, to;
        std::cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    std::cout << BFS(1) << '\n';

}