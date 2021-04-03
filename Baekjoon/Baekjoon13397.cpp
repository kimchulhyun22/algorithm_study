/*
    백준 13397번 구간 나누기 2
*/

#include <iostream>
#include <vector>
#include <algorithm> 

int GetSectionScore(const std::vector<int>& numbers, const int& start, const int& end) {
    auto start_iter = numbers.begin() + start;
    auto end_iter = numbers.begin() + end;

    int min_value = *std::min_element(start_iter, end_iter);
    int max_value = *std::max_element(start_iter, end_iter);
    
    return max_value - min_value;
}

bool CheckAvailable(const std::vector<int>& numbers, const int& section, const int& M) {
    
    int section_count = 0;
    int start = 0;

    for(int i = 0; i < numbers.size(); i++) {
        int section_score = GetSectionScore(numbers, start, i+1);
        if(section_score > section) {
            section_count++;
            start = i;
        }
    }

    // 마지막 구간 
    section_count++;
    return section_count <= M;
}

int main() {
    int N, M;
    std::vector<int> numbers;

    std::cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int input;

        std::cin >> input;
        numbers.push_back(input);
    }
    
    int left = 0;
    int right = *std::max_element(numbers.begin(), numbers.end());
    int result = right;

    while(left <= right) {
        int mid = (left + right) / 2;

        bool is_available = CheckAvailable(numbers, mid, M);

        if(is_available) {
           
            right = mid - 1;
            result = std::min(result, mid);
        }
        else {
            
            left = mid + 1;
        }
    }

    std::cout << result << '\n';
}