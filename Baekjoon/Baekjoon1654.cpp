/*
    백준 1654번 랜선 자르기
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

long long CutTree(const std::vector<int>& v, const int& cut_length) {
    long long tree_count = 0;

    for(int i = 0; i < v.size(); i++) {
        tree_count += v[i] / cut_length;
    }

    return tree_count;
}

void Solution(const std::vector<int>& v, const int& N) {
    long long left = 1;
    long long right = INT_MAX;
    long long result = 0;

    while(left <= right) {
        long long mid = (left + right) / 2;

        long long tree_count = CutTree(v, mid);
        
        if(tree_count >= N) {
            left = mid + 1;
            result = std::max(result, mid);
        }
        else if(tree_count < N) {
            right = mid - 1;
        }

    }    

    std::cout << result << std::endl;
}

int main() {
    int K, N;
    std::vector<int> v;

    std::cin >> K >> N;

    for(int i = 0; i < K; i++) {
        int input;

        std::cin >> input;

        v.push_back(input);
    }

    
    Solution(v, N);
}