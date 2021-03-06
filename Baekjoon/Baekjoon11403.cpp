/*
    백준 11403번 경로 찾기
*/

#include <iostream>
#include <vector>

#define INF 10001

std::vector<std::vector<int>> DoFloydwarshall(const int& N, const std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> dist;

    dist.resize(N);
    
    // dist 벡터 생성
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == 0) {
                dist[i].push_back(INF);
            }
            else {
                dist[i].push_back(graph[i][j]);
            }
        }
    }
    

    // 플로이드 워셜 알고리즘
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 업데이트되지 않는 점은 갈 수 없는 길
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] == INF ? dist[i][j] = 0 : dist[i][j] = 1; 
        }
    }

    return dist;
}

int main() {
    int N;
    std::vector<std::vector<int>> graph;

    std::cin >> N;

    graph.resize(N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            
            std::cin >> input;

            graph[i].push_back(input);
        }
    }

    std::vector<std::vector<int>> result = DoFloydwarshall(N, graph);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}