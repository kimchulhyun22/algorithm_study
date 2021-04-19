/*
    백준 10422번 괄호
*/
#include <iostream>
#include <vector>
#include <algorithm>

long long dp[5001];
long long mod = 1000000007;

void Solve() {
    dp[0] = 1;
    dp[2] = 1;

    for(int i = 3; i <= 5000; i++) {
        
        for(int j = 2; j <= i; j++) {
            dp[i] += dp[j-2] * dp[i-j];
            dp[i] %= mod;

        }
        dp[i] %= mod;
    }
} 

int main() {
    int tc;

    std::cin >> tc;
    
    Solve();

    while(tc-- > 0) {
        int input;
        
        std::cin >> input;
        std::cout << dp[input] << '\n';
    }
}