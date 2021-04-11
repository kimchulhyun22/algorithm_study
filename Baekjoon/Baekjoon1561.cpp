/*
    백준 1561번 놀이 공원
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long DoRide(const std::vector<int>& rides, 
                    const int& N,
                    const int& M,
                    const long long& time) {
    long long sum = M;

    for(int i = 0; i < M; i++) {
        sum += (time / rides[i]);
    }

    return sum;
}

int main() {
    int N, M;
    std::vector<int> rides;

    std::cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int input;
        std::cin >> input;

        rides.push_back(input);
    }

    if(N <= M) {
        std::cout << N << '\n';
        return 0;
    }

    long long left = 0;
    long long right = 2000000000LL * 30LL;
    long long time = 0;

    while(left <= right) {
        long long mid = (left + right) / 2;

        long long children_count = DoRide(rides, N, M, mid);
        
        if(children_count < N) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            time = mid;
        }
    }

    long long children_count = DoRide(rides, N, M, time-1);

    for(int i = 0; i < M; i++) {
        if(!(time % rides[i])) {
            children_count++;
        }

        if(children_count == N) {
            std::cout << i + 1 << '\n';
            break;
        }
    } 

}