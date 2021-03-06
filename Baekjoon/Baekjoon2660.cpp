/*
    백준 2660번 회장 뽑기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int bfs(const int& N, const std::vector<std::vector<int>>& graph, const int& start) {
    std::queue<std::pair<int, int>> q;
    std::vector<bool> checked;
    
    for(int i = 0; i < N; i++) {
        checked.push_back(false);
    }
    
    q.push(std::make_pair(start, 0));
    checked[start] = true;

    int result = 0;

    while(!q.empty()) {
        int vertex = q.front().first;
        int count = q.front().second;

        q.pop();

        for(size_t i = 0; i < graph[vertex].size(); i++) {
            int next = graph[vertex][i];

            if(checked[next]) continue;

            checked[next] = true;
            q.push(std::make_pair(next, count+1));
            result = std::max(result, count+1);
        }
    }

    return result;
}

int main() {

    int N;
    std::vector<std::vector<int>> graph;
    std::vector<int> count;

    std::cin >> N; 
    
    graph.resize(N);
    count.resize(N);

    while(true) {
        int from, to;
        std::cin >> from >> to;

        if(from == -1 && to == -1) {
            break;
        }

        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
        
    }

    std::vector<int> result;
    int result_score = INT_MAX;
    int result_count;

    // bfs를 통해 탐색하고 전부 탐색할 때까지 갯수를 리턴
    for(int i = 0; i < N; i++) {
        count[i] = bfs(N, graph, i);
        result_score = std::min(result_score, count[i]);
    }

    
    for(int i = 0; i < N; i++) {
        if(count[i] == result_score) {
            result.push_back(i);
        }
    }

    result_count = result.size();

    std::cout << result_score << " " << result_count << std::endl;
    
    for(int i = 0; i < result_count; i++) {
        std::cout << result[i] + 1 << " ";
    }

    return 0;
}