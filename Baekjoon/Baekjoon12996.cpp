/*
    백준 12996번 Acka
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int mod = 1000000007;
int dp[51][51][51][51];
int S, A, B, C;

int DFS(int n, int a, int b, int c) {
    if(n == S) {
        if(a == A && b == B && c == C) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(a > A || b > B || c > C) return 0;
    
    if(dp[n][a][b][c] != -1) {
        return dp[n][a][b][c];
    }

    int sum = 0;
    
    // 한곡씩 부르는 경우
    sum += DFS(n + 1, a + 1, b, c); sum %= mod;
    sum += DFS(n + 1, a, b + 1, c); sum %= mod;
    sum += DFS(n + 1, a, b, c + 1); sum %= mod;

    // 두곡씩 부르는 경우
    sum += DFS(n + 1, a + 1, b + 1, c); sum %= mod;
    sum += DFS(n + 1, a + 1, b, c + 1); sum %= mod;
    sum += DFS(n + 1, a, b + 1, c + 1); sum %= mod;

    // 세곡 부르는 경우
    sum += DFS(n + 1, a + 1, b + 1, c + 1); sum %= mod;
    
    return dp[n][a][b][c] = sum;
}

int main() {
    std::vector<int> acka(3);

    std::cin >> S;
    std::cin >> A >> B >> C;
    
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
            for(int k = 0; k < 51; k++)
                for(int l = 0; l < 51; l++)
                    dp[i][j][k][l] = -1;

    std::cout << DFS(0, 0, 0, 0) << '\n';

}