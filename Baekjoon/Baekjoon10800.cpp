/*
    백준 10800번 컬러볼
*/

#include <iostream>
#include <algorithm>
#include <vector>


struct Ball {
    int index;
    int color;
    int size;
};

int N;

Ball ball[200010];
int result[200010] = {0, };
int same_color[200010] = {0, };


bool CompSize(const Ball& a, const Ball& b) {
    return a.size < b.size; 
}

int main() {
   
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        int color, size;

        std::cin >> color >> size;
        
        ball[i].index = i;
        ball[i].color = color;
        ball[i].size = size;

    }

    std::sort(ball, ball + N, CompSize);
    
    int j = 0;
    int total = 0;

    for(int i = 0; i < N; i++) {
        
        // 자기 공을 찾음
        while(ball[j].size < ball[i].size) {
            total += ball[j].size;

            // 같은 색깔끼리는 제거할 수 없으므로 같은 색깔의 사이즈를 더함
            same_color[ball[j].color] += ball[j].size;
            j++;

        }

        result[ball[i].index] = total - same_color[ball[i].color];

    }

    for(int i = 0; i < N; i++) {
        std::cout << result[i] << '\n';    
    }
}