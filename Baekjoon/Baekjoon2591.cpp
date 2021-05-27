/*
    백준 2591번 숫자카드
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string number;
    std::vector<int> dp(50);

    std::cin >> number;

    // 한자리는 무조건 1개
    dp[0] = 1;

    for(int i = 0; i < number.size(); i++) {
        
        if(number[i] - '0' == 0) continue;

        dp[i + 1] += dp[i];

        if((number[i]-'0') * 10 + (number[i+1]-'0') <= 34) {
            dp[i+2] += dp[i];
        }

    }

    std::cout << dp[number.size()] << '\n';
    
}