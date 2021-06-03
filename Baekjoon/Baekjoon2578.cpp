/*
    백준 2578번 빙고
*/

#include <iostream>
#include <vector>
#include <algorithm>

int board[5][5];
int bingo[5][5];
bool check[5][5];

std::vector<bool> current(12);

void print() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << check[i][j] << " ";
        }
        std::cout << '\n';
    }
}
void Check(int number) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == number) {
                check[i][j] = true;
                break;
            }
        }
    }
}

int Bingo() {
    //0 1행 
    //1 2행
    //2 3행
    //3 4행
    //4 5행
    //5 1열
    //6 2열
    //7 3열
    //8 4열
    //9 5열
    //10 왼대각
    //11 오른대각
    
    
    int bingo_count = 0;

    // 행체크
    for(int i = 0; i < 5; i++) {
        
        if(current[i] == true) {
            continue;
        }

        int j;
        
        for(j = 0; j < 5; j++) {
            if(check[i][j] == false) {
                break;
            }    
        }

        if(j == 5) {
            current[i] = true;
        }
    }

    // 열 체크
    for(int i = 0; i < 5; i++) {
        
        if(current[i + 5] == true) {
            continue;
        }

        int j;
        
        for(j = 0; j < 5; j++) {
            if(check[j][i] == false) {
                break;
            }    
        }

        if(j == 5) {
            current[i + 5] = true;
        }
    }

    // 왼대각
    if(current[10] == false) {
        for(int i = 0; i < 5; i++) {
            if(check[i][i] == false) {
                break;
            }

            if(i == 4) {
                current[10] = true;
            }
        }
    }
    
    // 오른대각
    if(current[11] == false) {
        for(int i = 0; i < 5; i++) {
            if(check[i][4-i] == false) {
                break;
            }

            if(i == 4) {
                current[11] = true;
            }
        }
    }

    for(int i = 0; i < 12; i++) {
        if(current[i]) bingo_count++;

    }
    return bingo_count;
}

void Solution() {
    int result = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            
            
            
            // 빙고 숫자 찾아서 체크
            Check(bingo[i][j]);

            // 빙고 숫자 세기
            int current_bingo = Bingo();
            
            result++;

            if(current_bingo >= 3) {
                std::cout << result << '\n';
                return;
            }

        }
    }
    
    return;

}

int main() {

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> board[i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> bingo[i][j];
            check[i][j] = false;
        }
    }

    Solution();
}