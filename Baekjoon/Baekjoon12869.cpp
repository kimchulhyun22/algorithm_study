/*
    백준 12869번 뮤탈리스크
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N;
std::vector<int> scv(3);

int checked[61][61][61];

int result = INT_MAX;

void DFS(int scv1, int scv2, int scv3, int num) {
    // 모든 scv 체력이 0 이하인 경우 종료
    if(scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
        result = std::min(result, num);
        return;
    }

    // 인덱스 접근을 위해 0으로 변환
    if(scv1 < 0) scv1 = 0;
    if(scv2 < 0) scv2 = 0;
    if(scv3 < 0) scv3 = 0;
    
    if(checked[scv1][scv2][scv3] != INT_MAX && checked[scv1][scv2][scv3] <= num) return;

    checked[scv1][scv2][scv3] = num;
    
    // 9 3 1
    DFS(scv1 - 9, scv2 - 3, scv3 - 1, num + 1);

    // 9 1 3
    DFS(scv1 - 9, scv2 - 1, scv3 - 3, num + 1);
    
    // 3 9 1
    DFS(scv1 - 3, scv2 - 9, scv3 - 1, num + 1);
    
    // 3 1 9
    DFS(scv1 - 3, scv2 - 1, scv3 - 9, num + 1);
    
    // 1 9 3
    DFS(scv1 - 1, scv2 - 9, scv3 - 3, num + 1);
    
    // 1 3 9
    DFS(scv1 - 1, scv2 - 3, scv3 - 9, num + 1);
}

int main() {
    std::cin >> N;
    scv.resize(N);

    for(int i = 0; i < N; i++) {
        std::cin >> scv[i];
    }

    for(int i = 0; i < 61; i++)
        for(int j = 0; j < 61; j++)
            for(int k = 0; k < 61; k++)
                checked[i][j][k] = INT_MAX;

    DFS(scv[0], scv[1], scv[2], 0);

    std::cout << result << '\n';
}