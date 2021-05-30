/*
    백준 2576번 홀수
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers(7);
    std::vector<int> odd;

    for(int i = 0; i < 7; i++) {

        std::cin >> numbers[i];
        
        if(numbers[i] % 2 == 1) {
            odd.push_back(numbers[i]);
        }
    }

    if(odd.empty()) {
        std::cout << -1 << '\n';
        return 0;

    }
    
    sort(odd.begin(), odd.end());

    int sum = 0;

    for(int i = 0; i < odd.size(); i++) {
        sum += odd[i];
    }

    std::cout << sum << '\n' << odd[0] << '\n';

}