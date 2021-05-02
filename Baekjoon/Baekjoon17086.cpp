/*
    백준 17086번 아기 상어 2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

int N, M;
int map[50][50];
bool checked[50][50];

void InitChecked() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            checked[i][j] = false;
        }
    }
}



int BFS(int x, int y) {
    std::queue<std::pair<int, std::pair<int, int>>> q;
    int distance = INT_MAX;

    InitChecked();

    q.push(std::make_pair(x, std::make_pair(y, 0)));

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second.first;
        int depth = q.front().second.second;

        q.pop();

        if(map[cur_x][cur_y] == 1) {
            distance = std::min(distance, depth);
            break;
        }
        
        for(int i = 0; i < 8; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(checked[next_x][next_y] || next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;

            checked[next_x][next_y] = true;
            q.push(std::make_pair(next_x, std::make_pair(next_y, depth + 1)));

        }

    }

    return distance;
}

int main() {
   std::cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
           std::cin >> map[i][j];
        }
    }

    int result = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            result = std::max(result, BFS(i, j));
        }
    }

    std::cout << result << '\n';
    
}
