/*
    백준 2176번 합리적인 이동경로
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using pii = std::pair<int, int>;

std::vector<int> dp;
std::vector<int> dist;

int N, M;
std::vector<std::vector<pii>> graph;

void DijkStra(int start) {
    std::priority_queue<pii> pq;

    dp[start] = 1;
    dist[start] = 0;

    pq.push(std::make_pair(0, start));

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        int node = cur.second;
        int cost = -cur.first;

        // 이미 최단경로 계산
        if(cost > dist[node]) continue;
        
        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_dist = cost + graph[node][i].second;

            if(next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push(std::make_pair(-next_dist, next_node));
            }
            
            // 현재 노드까지의 최단 경로보다 다음 노드까지의 최단 경로가 더 짧으면
            // 둘 사이에 합리적인 이동경로가 존재한다 
            if(cost > dist[next_node]) {
                dp[node] += dp[next_node];
            }
        }
    }

    std::cout << dp[0] << '\n';
}

int main() {
    
    std::cin >> N >> M;
    graph.resize(N);

    for(int i = 0; i < N; i++) {
        dp.push_back(0);
        dist.push_back(INT_MAX);
        
    }

    for(int i = 0; i < M; i++) {
        int u, v, c;

        std::cin >> u >> v >> c;

        graph[u-1].push_back(std::make_pair(v-1, c));
        graph[v-1].push_back(std::make_pair(u-1, c));    
    }

    DijkStra(1);   
}