/*
    백준 12969번 ABC
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char result[31];
bool checked[31][31][31][450];

int N, K;


bool DFS(int n, int a, int b, int k) {

    if(n == N) {
        if(k == K) return true;
        else return false;
    }

    // 이미 구한 케이스는 또 구하지 말자
    if(checked[n][a][b][k]) return false;

    checked[n][a][b][k] = true;

    result[n] = 'A';
    if(DFS(n+1, a + 1, b, k)) return true;

    result[n] = 'B';
    if(DFS(n+1, a, b + 1, k + a)) return true;

    result[n] = 'C';
    if(DFS(n+1, a, b, k + a + b)) return true;

    return false;
}

int main() {
     
    std::cin >> N >> K;

    if(DFS(0, 0, 0, 0)) {
        std::cout << result << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
    
}