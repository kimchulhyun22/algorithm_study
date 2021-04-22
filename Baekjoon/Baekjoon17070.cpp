/*
    백준 17070번 파이프 옮기기 1
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N;
int house[16][16];
int result = 0;

struct Point {
    int x;
    int y;
};

// 보내려는 방향 충돌 체크
bool CheckCollision(Point to, int dir) {
    // 가로인 경우 충돌 체크
    if(dir == 0) {
        if(to.y >= N-1) {
            return true;
        }

        // 벽인 경우
        if(house[to.x][to.y + 1] == 1) {
            return true;
        }

    }
    // 세로인 경우 충돌 체크
    else if(dir == 1) {
        // 범위 벗어난 경우
        if(to.x >= N-1) {
            return true;
        }
        
        // 벽인 경우
        if(house[to.x + 1][to.y] == 1){
            return true;
        }

    }
    else {
        if(to.x >= N-1 || to.y >= N-1) {
            return true;
        }
        
        // 벽인 경우
        if(house[to.x + 1][to.y] == 1 || house[to.x][to.y + 1] == 1 || house[to.x + 1][to.y + 1] == 1){
            return true;
        }
    }
    
    return false;
}

void DFS(Point from, Point to, int dir) {

    if(to.x == N-1 && to.y == N-1) {
        result++;
        return;
    }

    // 가로일 때
    if(dir == 0) {

        // 가로로 보내는 경우
        if(!CheckCollision(to, 0)) {
            DFS(to, Point{to.x, to.y + 1}, 0);
        }
        // 대각선으로 보내는 경우

        if(!CheckCollision(to, 2)) {
            DFS(to, Point{to.x + 1, to.y + 1}, 2);
        }
    }
    // 세로일 때
    else if(dir == 1) {
        // 세로로 보내는 경우
        if(!CheckCollision(to, 1)) {
            DFS(to, Point{to.x + 1, to.y}, 1);
        }

        // 대각선으로 보내는 경우
        if(!CheckCollision(to, 2)) {
            DFS(to, Point{to.x + 1, to.y + 1}, 2);
        }
    }   
    // 대각선일 때
    else if(dir == 2) {

        // 가로로 보내는 경우
        if(!CheckCollision(to, 0)) {
            DFS(to, Point{to.x, to.y + 1}, 0);
        }

        // 세로로 보내는 경우
        if(!CheckCollision(to, 1)) {
            DFS(to, Point{to.x + 1, to.y}, 1);
        }
        
        // 대각선으로 보내는 경우
        if(!CheckCollision(to, 2)) {
            DFS(to, Point{to.x + 1, to.y + 1}, 2);
        }
    }
}

int main() {
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> house[i][j];
        }
    }

    DFS(Point{0,0}, Point{0, 1}, 0);
    
    std::cout << result << '\n';
}