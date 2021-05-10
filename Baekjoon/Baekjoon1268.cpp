/*
    백준 1268번 임시 반장 정하기
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int Solution(const std::vector<std::vector<int>>& table, std::vector<std::vector<bool>>& student_check, const int& N) {
    
    // 1번 학생부터 시작
    for(int i = 0; i < N; i++) {
        
        // 1학년부터 시작
        for(int j = 0; j < 5; j++) {
            
            // 같은 반이었던 학생이 있는 경우 찾음
            for(int k = 0; k < N; k++) {
                if(i == k) continue;

                if(table[i][j] == table[k][j]) {
                    student_check[i][k] = true;
                    student_check[k][i] = true;
                }
            }
        }
    }

    int max_value = 0;
    int index = 0;

    for(int i = 0; i < N; i++) {
        int cnt = 0;

        for(int j = 0; j < N; j++) {
            if(student_check[i][j]) {
                cnt++;
            }
        }

        if(cnt > max_value) {
            max_value = cnt;
            index = i;
        }

    }


    return index + 1;
}

int main() {

    int N;

    std::cin >> N;

    std::vector<std::vector<int>> table;
    std::vector<std::vector<bool>> student_check;

    table.resize(N);
    student_check.resize(N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            int input;

            std::cin >> input;

            table[i].push_back(input);
        }

        for(int j = 0; j < N; j++) {
            student_check[i].push_back(false);
        }
    }

    std::cout << Solution(table, student_check, N) << '\n';

}   
