/*
    백준 2490번 윷놀이
*/

#include <iostream>
#include <map>

int yut[3][4];

int PlayYut(int* arry) {
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        if(arry[i] == 0) {
            cnt++;
        }
    }

    return cnt;
} 

int main() {
    std::map<int, char> m;
    m[0] = 'E'; m[1] = 'A'; m[2] = 'B'; m[3] = 'C'; m[4] = 'D';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> yut[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        std::cout << m[PlayYut(yut[i])] << '\n';
    }



}