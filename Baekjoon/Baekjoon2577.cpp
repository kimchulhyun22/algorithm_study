/*
    백준 2577번 숫자의 개수
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> count(10);

    int A, B, C;

    std::cin >> A >> B >> C;

    long long mul = A * B * C;

    while(mul > 0) {
        count[mul % 10] += 1;

        mul /= 10;
    } 

    for(int i = 0; i < 10; i++) {
        std::cout << count[i] << '\n';
    }
    
}