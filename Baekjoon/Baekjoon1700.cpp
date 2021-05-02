/*
    백준 1700번 멀티탭 스케쥴링
*/

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

std::map<int, int> number_count;


int main() {
    int N, K;

    std::cin >> N >> K;
    
    std::vector<int> use_count(K);
    std::vector<int> multitab;

    for(int i = 0; i < K; i++) {
        std::cin >> use_count[i];

        if(number_count.find(use_count[i]) == number_count.end()) {
            number_count[use_count[i]] = 0;
        }
        else {
            number_count[use_count[i]] += 1;
        }
    }

    int result = 0;
    
    for(int i = 0; i < K; i++) {

        //이미 꽂혀 있는 경우
        if(find(multitab.begin(), multitab.end(), use_count[i]) != multitab.end()) {
            continue;
        }
        // 멀티탭이 안 차있는 경우
        if(multitab.size() < N) {
            multitab.push_back(use_count[i]);
            number_count[use_count[i]] -= 1;
            continue;
        }

        // 빼야하는 경우
        // 앞으로 가장 늦게 사용될 걸 뺀다
        int idx = -1, erase_idx = -1;

        for(int j = 0; j < multitab.size(); j++) {
            int last_idx = 0;

            for(int k = i + 1; k < K; k++) {
                
                if(multitab[j] == use_count[k]) {
                    break;
                }   
                last_idx++;
            }

            if(last_idx > idx) {
                erase_idx = j;
                idx = last_idx;
            }
        }

        multitab.erase(multitab.begin() + erase_idx);

        multitab.push_back(use_count[i]);
        number_count[use_count[i]] -= 1;
        
        result++;
    }   

    std::cout << result << '\n';
}
