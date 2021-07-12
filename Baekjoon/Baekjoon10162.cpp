/*
    백준 10162번 전자레인지
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N;
int A = 300;
int B = 60;
int C = 10;

int main() {
    
    std::cin >> N;

    int result[3] = {0, };

    // 300으로 나눔
    int cnt = 0;

    cnt = N / A;
    N -=  cnt * A;
    result[0] += cnt;
    // 60으로 나눔
    
    cnt = N / B;
    N -= cnt * B;
    
    result[1] += cnt;
    
    // 10으로 나눔
    cnt = N / C;
    N -= cnt * C;
    result[2] += cnt;

    if(N == 0) {
        std::cout << result[0] << " " << result[1] << " " << result[2] << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}