/*
    백준 2605번 줄 세우기
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> students;

int main() {
    std::cin >> N;

    students.resize(N);
    
    std::vector<int> result;

    for(int i = 0; i < N; i++) {
        std::cin >> students[i];
    }    

    result.push_back(0);

    for(int i = 1; i < N; i++) {
        result.insert(result.begin() + students[i], i);
    }
    
    for(int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i] + 1 << " ";
    }
    

}