/*
    백준 2588번 곱셈
*/

#include <iostream>
#include <vector>


int main() {
    int A, B;

    std::cin >> A >> B;

    std::vector<int> parse(3);

    parse[0] = B % 10;
    parse[2] = B / 100;
    parse[1] = (B % 100) / 10;

    for(int i = 0; i < 3; i++) {
        std::cout << A * parse[i] << '\n';
    }

    std::cout << A*B << '\n';
}