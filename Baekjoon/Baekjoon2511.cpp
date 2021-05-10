/*
    백준 2511번 카드놀이
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> A(10);
    std::vector<int> B(10);
    
    int result_a = 0;
    int result_b = 0;

    for(int i = 0; i < 10; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < 10; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < 10; i++) {
        if(A[i] > B[i]) {
            result_a += 3;
        }
        else if(A[i]< B[i]) {
            result_b += 3;
        }
        else {
            result_a++;
            result_b++;
        }
    }
    
    std::cout << result_a << " " << result_b << '\n';

    if(result_a > result_b) {
        std::cout << "A\n";
    }
    else if(result_a < result_b) {
        std::cout << "B\n";
    }
    else {
        // 총 승점이 같은 경우 마지막 게임을 이긴 케이스를 찾음
        for(int i = 9; i >= 0; i--) {
            if(A[i] > B[i]) {
                std::cout << "A\n";
                return 0;
            }
            else if(A[i] < B[i]) {
                std::cout << "B\n";
                return 0;
            }
        }
        std::cout << "D\n";
    }

    return 0;
}