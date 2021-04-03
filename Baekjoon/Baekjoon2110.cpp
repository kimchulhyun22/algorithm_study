/*
    백준 2110번 공유기 설치
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

bool CheckAvailable(const std::vector<int>& houst_list, const int& interval, const int& router) {

    int start = houst_list[0];
    int cnt = 1;

    for(int i = 1; i < houst_list.size(); i++) {
        if(houst_list[i] - start >= interval) {
            start = houst_list[i];
            cnt++;
        }
    }
    if(cnt >= router) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int house, router;
    std::vector<int> house_list;

    std::cin >> house >> router;

    for(int i = 0; i < house; i++) {
        int input;

        std::cin >> input;

        house_list.push_back(input);
    }
    
    sort(house_list.begin(), house_list.end());

    int left = 1;
    int right = *(house_list.end() - 1);
    int result = 0;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        bool is_available = CheckAvailable(house_list, mid, router);

        if(is_available) {
            left = mid + 1;
            result = std::max(result, mid);
        }
        else {
            right = mid - 1;
        }

    }

    std::cout << result << "\n";
}