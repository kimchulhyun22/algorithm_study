/*
    백준 3079번 입국 심사
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

long long getEntrancePeople(const std::vector<int> entrance, const long long time) {
    long long people = 0;

    for(int i = 0; i < entrance.size(); i++) {
        people += (time / entrance[i]);
    }

    return people;
}

int main() {
    int N, M;
    std::vector<int> entrance;

    std::cin >> N >> M;

    long long max_time = 0;

    for(int i = 0; i < N; i++) {
        long long input;
        std::cin >> input;

        max_time = std::max(input, max_time);

        entrance.push_back(input);
    }

    long long left = 1;
    long long right = max_time * M;
    long long result = LLONG_MAX;

    while(left <= right) {
        long long mid = (left + right) / 2;

        long long people = getEntrancePeople(entrance, mid);

        if(people >= M) {
            right = mid - 1;
            result = std::min(result, mid);
        }
        else {
            left = mid + 1;
        }
    }

    std::cout << result << std::endl;

}