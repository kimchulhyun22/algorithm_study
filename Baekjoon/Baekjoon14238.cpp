/*
    백준 14238번 출근 기록
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
char result[51];

int last_index[3];
bool checked[51][51][51][3][3];

int A = 0;
int B = 0;
int C = 0;

int size;

bool DFS(int a, int b, int c, int pre, int pre_pre) {
    if(a == A && b == B && c == C) {
        return true;
    }

    // 이미 점검한 케이스는 스킵
    // 되는 스트링 아무거나 출력해도 되니까
    if(checked[a][b][c][pre][pre_pre] == true) {
        return false;
    }
    checked[a][b][c][pre][pre_pre] = true;

    int current_idx = a + b + c;

    // A 추가
    if(a < A) {
        result[current_idx] = 'A';        
        if(DFS(a + 1, b, c, 0, pre)) {
            return true;
        }
        
        
    }
    
    if(b < B && pre != 1) {
        result[current_idx] = 'B';
        if(DFS(a, b + 1, c, 1, pre)) {
            return true;
        }
    }

    
    // C 추가
    if(c < C && pre != 2 && pre_pre != 2) {
        result[current_idx] = 'C';
    
        if(DFS(a, b, c + 1, 2, pre)) {
            return true;
        }
    }    

    return false;

}

int main() {
    std::string record;

    std::cin >> record;
    
    for(int i = 0; i < 3; i++) last_index[i] = -3;

    size = record.size();

    for(int i = 0; i < size; i++) {
        if(record[i] == 'A') A++;
        if(record[i] == 'B') B++;
        if(record[i] == 'C') C++;   
    }

    if(DFS(0,0,0,0,0)) {
        std::cout << result << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}