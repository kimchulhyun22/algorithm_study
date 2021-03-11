/*
    백준 1012번 유기농 배추
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void DFS(const std::vector<std::vector<int>>& map, std::vector<std::vector<int>>& checked, 
        int x, int y, const int& number, const int& N, const int& M) {
    
    checked[x][y] = number;
    int result = 0;

    // 4방향 탐색
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || checked[next_x][next_y] != -1) continue;

        DFS(map, checked, next_x, next_y, number, N, M);
    }   
}

void solution(const std::vector<std::vector<int>>& map, std::vector<std::vector<int>>& checked, const int& N, const int& M) {

    int number = 0;
    
    // 방문하지 않은 곳을 DFS로 탐색
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {

            if(checked[i][j] == -1) {
                DFS(map, checked, i, j, ++number, N, M);
            }
        }
    }

    std::cout << number << std::endl;
}

int main() {
    int test_case;


    std::cin >> test_case;
    
    for(int k = 0; k < test_case; k++) {
    
        int M, N, K;
        std::vector<std::vector<int>> map;
        std::vector<std::vector<int>> checked;

        std::cin >> M >> N >> K;

        map.resize(N);
        checked.resize(N);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                map[i].push_back(0);
                checked[i].push_back(0);
            }
        }

        for(int i = 0; i < K; i++) {
            int x, y;

            std::cin >> y >> x;

            map[x][y] = 1;
            checked[x][y] = -1;
        }

        solution(map, checked, N, M);

    }

    return 0;
}