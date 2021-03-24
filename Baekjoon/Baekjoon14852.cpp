/*
    백준 14852번 타일 채우기3
*/

#include <iostream>
#include <vector>

int main() {
    int N;

    std::cin >> N;

    std::vector<long long> dp;
    std::vector<long long> sum;

    dp.resize(N+1);
    sum.resize(N+1);

    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 7;
    
    // 0~N-3까지 합을 저장하는 배열 
    sum[2] = 1;
    
    for(int i = 3; i <= N; i++) {
        sum[i] = (sum[i-1] + dp[i-3]) % 1000000007;

        dp[i] += (dp[i-1] * 2 + dp[i-2] * 3 + sum[i] * 2) % 1000000007;

    }

    std::cout << dp[N] << std::endl;
    
}