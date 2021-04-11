/*
    백준 15961번 회전 초밥
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int checked[3001] = {0, };
int n, d, k, c;
int sushi[3000000];

std::deque<int> dq;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> d >> k >> c;
    
    for(int i = 0; i < n; i++) {
        std::cin >> sushi[i];
    }

    int sushi_count = 0;
    int result = 0;

    for(int i = 0; i < k; i++) {
        dq.push_back(sushi[i]);
        
        if(checked[sushi[i]] == 0) {
            sushi_count++;
        }

        checked[sushi[i]]++;
        result = std::max(result, sushi_count);
    }

    for(int i = 0; i < n - 1; i++) {
        dq.pop_front();
        checked[sushi[i]]--;

        if(checked[sushi[i]] == 0) {
            sushi_count--;
        }

        // 다음 스시
        int next_sushi = sushi[(i+k) % n];
        dq.push_back(next_sushi);
        
        // 없던 스시인 경우
        if(checked[next_sushi] == 0) {
            sushi_count++;
        }
        
        checked[next_sushi]++;
        // 쿠폰 스시가 있는 경우 하나 더
        if(!checked[c])
            result = std::max(result, sushi_count + 1);
        else 
            result = std::max(result, sushi_count);
    }

    std::cout << result << '\n';

}