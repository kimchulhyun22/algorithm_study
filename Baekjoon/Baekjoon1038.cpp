/*
    백준 1038번 감소하는 수
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

long long dp[1000001] = {0, };

void DecreasingNumber(long long N) {
    std::queue<long long> q;

    for(long long i = 0; i <= 9; i++) {
        dp[i] = i;
        q.push(i);
    }

    long long dp_idx = 10;
    long long result = -1;

    while(!q.empty()) {
        long long number = q.front();
        q.pop();

        long long last_digit = number % 10;

        for(long long i = 0; i < last_digit; i++) {
            long long next_number = number * 10 + i;
            
            q.push(next_number);
            dp[dp_idx++] = next_number;
        }

        if(dp_idx > N) {
            break;
        }

    }
    
    if(dp_idx >= N && dp[N] != 0) {
        std::cout << dp[N] << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }

}

int main() {
    long long N;
    
    std::cin >> N;

    if(N <= 9) {
        std::cout << N << '\n';
    }
    else {
        DecreasingNumber(N);
    }
}