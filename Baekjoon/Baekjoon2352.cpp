/*
    백준 2352번 반도체 설계
*/

#include <iostream>
#include <vector>
#include <algorithm>

int findLIS(std::vector<int> v) {
    std::vector<int> lis;
    lis.push_back(v[0]);
    
    for(int i = 1; i < v.size(); i++) {
        if(lis.back() < v[i]) {
            lis.push_back(v[i]);
        }    
        else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }
    
    for(int i = 0; i < lis.size(); i++) {
        std::cout << lis[i] << ' ';
    }
    std::cout << '\n';
    
    return lis.size();
}

int main() {
    int n;
    std::vector<int> v;

    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int input;

        std::cin >> input;

        v.push_back(input);
    }

    std::cout << findLIS(v) << '\n';

}