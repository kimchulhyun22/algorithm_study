/*
    백준 1744번 수 묶기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

int CalculateNegative(std::vector<int>& negative, const int& zero) {
    
    int sum_negative = 0;

    // 음수가 짝수인 경우는 묶을 경우 양수가 나오지만
    // 홀수인 경우는 마지막 남은 숫자가 음수가 되어야 한다
    // 0이 포함된 경우는 0과 묶어서 0이 되도록 한다
    if(negative.size() % 2 == 1) {
        if(zero == 0) {
            negative.push_back(-1);
        }
        else {
            negative.push_back(0);
        }
    }
  
    sort(negative.begin(), negative.end());

    for(int i = 0; i < negative.size(); i += 2) {
        sum_negative += negative[i] * negative[i+1];
    }

    return sum_negative;
}

int CalculatePositive(std::vector<int>& positive) {

    int sum_positive = 0;

    // 양수가 홀수인 경우는 편의성을 위해 1을 추가해서 짝수개로 만든다
    if(positive.size() % 2 == 1){
        positive.push_back(1);
    }
    
    sort(positive.begin(), positive.end());

    for(int i = 0; i < positive.size(); i += 2) {
        sum_positive += positive[i] * positive[i+1];
    }

    return sum_positive;
}

int main() {
    int N;
    std::vector<int> positive;
    std::vector<int> negative;
    int one = 0;
    int zero = 0;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        int number;
        std::cin >> number;

        if(number < 0) {
            negative.push_back(-number);
        }
        else if(number == 0) {
            zero++;
        }
        else if(number == 1) {
            one++;
        }
        else {
            positive.push_back(number);
        }
    }
    
    std::cout << CalculateNegative(negative, zero) + CalculatePositive(positive) + one << std::endl;    

    return 0;
}