/*
    백준 2839번 설탕 배달
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;

    std::cin >> N;

    int five_count = N / 5;

    for(int i = five_count; i >= 0; i--) {
        int sum = i * 5;

        if((N - sum) % 3 == 0) {
            std::cout << i + (N - sum) / 3 << '\n';
            return 0;
        }  
    }
    
    std::cout << -1 << '\n';
}