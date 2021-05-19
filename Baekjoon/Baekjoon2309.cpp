/*
    백준 2309번 일곱 난쟁이
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> heights(9);

int main() {

    int sum = 0;

    for(int i = 0; i < 9; i++) {
        std::cin >> heights[i];
        
        sum += heights[i];
    }

    bool result = false;

    // 두 개를 찾아서 뺀다
    for(int i = 0; i < 8; i++) {
        for(int j = i + 1; j < 9; j++) {
            
            if(sum - heights[i] - heights[j] == 100) {
                heights[i] = -1;
                heights[j] = -1;
                
                result = true;

                break;
            }
        }

        if(result) break;
        
    }

    sort(heights.begin(), heights.end());

    for(int i = 2; i < 9; i++) {
        std::cout << heights[i] << '\n';
    }
    

}