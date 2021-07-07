/*
    백준 2493번 탑
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int N;
std::vector<int> top;

int main() {
    std::cin >> N;
    top.resize(N + 1);

    for(int i = 1; i <= N; i++) {
        std::cin >> top[i];
    }

    std::stack<std::pair<int, int>> s;

    for(int i = 1; i <= N; i++) {
        if(s.empty()) {
            std::cout << 0 << ' ';
            s.push({i, top[i]});
        }
        else {
            while(!s.empty() && s.top().second < top[i]) {
                s.pop();
            }

            if(s.empty()) {
                std::cout << 0 << ' ';
            }
            else{
                std::cout << s.top().first << ' ';
            }

            s.push({i, top[i]});
        }
    }    

}