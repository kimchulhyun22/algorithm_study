/*
    백준 2748번 피보나치 수 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;

    std::cin >> N;

    if(N == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    N += 1;

    std::vector<long long> fibonacci;
    fibonacci.resize(N);

    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for(int i = 2; i < N; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    std::cout << fibonacci[N-1] << std::endl;

}