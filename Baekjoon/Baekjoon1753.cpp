#include <iostream>
#include <queue>

#define INF 999999999

std::vector<int> Dijkstra(std::vector<std::vector<std::pair<int,int>>> graph, const int& start, const int& V) {
    std::vector<int> dist(V+1, INF);

    std::priority_queue<std::pair<int, int>> pq;
    
    dist[start] = 0;
    pq.push(std::make_pair(0, start));

    while(!pq.empty()) {

        int cost = -pq.top().first;
        int vertex = pq.top().second;

        pq.pop();
        
        for(int i = 0; i < graph[vertex].size(); i++) {
            int next_cost = graph[vertex][i].second;
            int next_vertex = graph[vertex][i].first;

            if(dist[next_vertex] > dist[vertex] + next_cost) {
                dist[next_vertex] = dist[vertex] + next_cost;
                pq.push(std::make_pair(-dist[next_vertex], next_vertex));
            } 
        }
    }

    return dist;

}

void Solution(std::vector<std::vector<std::pair<int,int>>> graph, const int& start, const int& V) {
    std::vector<int> answer = Dijkstra(graph, start, V);

    for(int i = 1; i < answer.size(); i++) {
        if(answer[i] == INF) {
            std::cout << "INF\n";
        }
        else {
            std::cout << answer[i] << "\n";
        }
    }
}

int main() {
    int V, E;
    int start;

    std::vector<std::vector<std::pair<int,int>>> graph;

    std::cin >> V >> E >> start;

    graph.resize(V+1);

    for(int i = 0; i < E; i++) {
        int from, to, cost;

        std::cin >> from >> to >> cost;

        graph[from].push_back(std::make_pair(to, cost));

    }

    Solution(graph, start, V);
    
    return 0;
}