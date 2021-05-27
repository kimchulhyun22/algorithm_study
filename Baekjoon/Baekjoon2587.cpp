/*
    백준 2587번 대표값2
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers(5);

    for(int i = 0; i < 5; i++) {
        std::cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    std::cout << sum / 5 << '\n' << numbers[2];


}