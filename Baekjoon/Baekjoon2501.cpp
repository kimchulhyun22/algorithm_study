/*
    백준 2501번 약수 구하기
*/

#include <iostream>
#include <vector>

int main() {
    int N, K;

    std::cin >> N >> K;

    int index = 0;

    for(int i = 1; i <= N; i++) {
        if(N % i == 0) {
            index++;
            
            if(index == K) {
                std::cout << i << '\n';

                return 0; 
            }

            continue;
        }
        
    }    

    std::cout << 0 << '\n';

    
}

