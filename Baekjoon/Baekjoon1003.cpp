/*
    백준 1003번 피보나치 함수
*/

#include <iostream>
#include <vector>

struct Fibonacci {
    int one;
    int zero;
    int sum;
};

int main() {
    int test_case;


    std::cin >> test_case;
    
    while(test_case-- > 0) {
        int N;
        std::vector<Fibonacci> dp(41);
        
        std::cin >> N;

        dp[0].one = 0;
        dp[0].zero = 1;
        dp[0].sum = 0;

        dp[1].one = 1;
        dp[1].zero = 0;
        dp[1].sum = 1;

        if(N == 0) {
            std::cout << 1 << " " << 0 << '\n';
            
        }
        else if(N == 1) {
            std::cout << 0 << " " << 1 << '\n';
        }
        else {
            for(int i = 2; i <= N; i++) {
                dp[i].one = dp[i-1].one + dp[i-2].one;
                dp[i].zero = dp[i-1].zero + dp[i-2].zero;
                dp[i].sum = dp[i-1].sum + dp[i-2].sum;
            }

            std::cout << dp[N].zero << " " << dp[N].one << '\n';
        }

    }
}