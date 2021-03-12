/*
    백준 11049번 행렬 곱셈 순서
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999999


void Solution(const std::vector<std::pair<int, int>>& matrix,
                std::vector<std::vector<int>>& dp, const int& N) {
    
    // 두 개씩 묶는 경우 초기화
    for(int i = 0; i < N-1; i++) {
        dp[i][i+1] = matrix[i].first * matrix[i].second * matrix[i+1].second;
    }

    
    for(int j = 1; j < N; j++) { 
        for(int i = j - 1 ; i >= 0; i--) {
            for(int k = i; k < j; k++) {
                int tmp = dp[i][k] + dp[k+1][j] + matrix[i].first * matrix[k].second * matrix[j].second;
                if(!dp[i][j] || dp[i][j] > tmp) {
                    dp[i][j] = tmp;
                }
            }
        }
    }

    std::cout << dp[0][N-1] << std::endl;
}

int main() {
    int N;
    std::vector<std::pair<int, int>> matrix;
    std::vector<std::vector<int>> dp;

    std::cin >> N;

    dp.resize(N);

    for(int i = 0; i < N; i++) {
        int A, B;
        std::cin >> A >> B;

        matrix.push_back(std::make_pair(A, B));
        
        for(int j = 0; j < N; j++) {
            dp[i].push_back(0);
        }
    }

    Solution(matrix, dp, N);

}