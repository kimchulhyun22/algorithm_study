/*
    백준 2579번 계단 오르기
*/

#include <iostream>
#include <vector>
#include <algorithm>


void solution(const std::vector<int>& stairs, std::vector<int>& dp, const int& N) {

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for(int i = 3; i <= N; i++) {
        dp[i] = std::max(dp[i-2], stairs[i-1] + dp[i-3]) + stairs[i];
    }

    std::cout << dp[N] << std::endl;
}

int main() {
    int N;
    std::vector<int> stairs;
    std::vector<int> dp;

    std::cin >> N;

    stairs.push_back(0);
    dp.push_back(0);

    for(int i = 1; i <= N; i++) {
        int input;

        std::cin >> input;

        stairs.push_back(input);
        dp.push_back(0);
    }

    // 런타임에러를 방지하기 위한 여유 인덱스
    stairs.push_back(0);
    dp.push_back(0);

    solution(stairs, dp, N);
}