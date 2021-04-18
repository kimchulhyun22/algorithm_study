/*
    백준 10942번 팰린드롬?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using pii = std::pair<int, int>;

int N, M;
std::vector<int> numbers;
std::vector<pii> questions;
std::vector<std::vector<bool>> dp;

void printDP() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void CheckPalindrome() {

    // 홀수인 경우
    for(int i = 1; i < N - 1; i++) {
        int start = i - 1;
        int end = i + 1;

        while(numbers[start] == numbers[end] && start >= 0 && end <= N - 1) {
            dp[start--][end++] = true;
        }

    }
    
    // 짝수인 경우
    for(int i = 0; i < N - 1; i++) {
        int start = i;
        int end = i + 1;

        while(numbers[start] == numbers[end] && start >= 0 && end <= N - 1) {
            dp[start--][end++] = true;
        }
    }
    
}



int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

    std::cin >> N;
    numbers.resize(N);
    dp.resize(N);

    for(int i = 0; i < N; i++) {
        std::cin >> numbers[i];    
        
        for(int j = 0; j < N; j++) {
            if(i == j) {
                dp[i].push_back(true);
            }
            else {
                dp[i].push_back(false);
            }
        }
    }

    std::cin >> M;
    
    for(int i = 0; i < M; i++) {
        int s,e;
        std::cin >> s >> e;

        questions.push_back(std::make_pair(s-1, e-1));
    }

    CheckPalindrome();

    for(int i = 0; i < M; i++) {
        std::cout << dp[questions[i].first][questions[i].second] << '\n';
    }

}