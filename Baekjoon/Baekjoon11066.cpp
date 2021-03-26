/*
    백준 11066번 파일 합치기
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int GetSum(const std::vector<int>& sum, int start, int end) {
    
    // start ~ end 까지의 합을 반환
    if(start == 0) {
        return sum[end];
    }
    else {
        return sum[end] - sum[start-1];
    }
}

int Solution(std::vector<std::vector<int>>& dp, const std::vector<int>& sum, const int& count) {

    for(int j = 1; j < count; j++) {
        for(int i = j-1; i >= 0; i--) {
            
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j]);

            }

            dp[i][j] += GetSum(sum, i, j);
        }
    }

    return dp[0][count-1];
}

void CalculateSum(const std::vector<int>& files, std::vector<int>& sum) {
    
    sum[0] = files[0];

    // 0 ~ N 까지의 합을 저장
    for(int i = 1; i < sum.size(); i++) {
        sum[i] = sum[i-1] + files[i];
    }
}

int main() {
    int test_case;

    std::cin >> test_case;

    while(test_case-- > 0) {
        int count;
    
        std::vector<int> files;
        std::vector<int> sum;
        std::vector<std::vector<int>> dp;

        std::cin >> count;
        
        dp.resize(count);

        for(int i = 0; i < count; i++) {
            int file;

            std::cin >> file;

            files.push_back(file);
            sum.push_back(0);

            for(int j = 0; j < count; j++) {
                dp[i].push_back(0);
            }
        }        

        CalculateSum(files, sum);
        
        std::cout << Solution(dp, sum, count) << std::endl;

    }
}