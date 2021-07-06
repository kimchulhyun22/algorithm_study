/*
    백준 2456번 나는 학급회장이다
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Candidate {
    int number;
    int count[3];
    int score;
};

Candidate candidate[3];

bool Comp(const Candidate& a, const Candidate& b) {
    if(a.score == b.score) {
        if(a.count[2] == b.count[2]) {
            if(a.count[1] == b.count[1]) {
                return a.count[0] > b.count[0]; 
            }   
            else {
                return a.count[1] > b.count[1];    
            } 
        }
        else {
            return a.count[2] > b.count[2];
        }
    }
    else {
        return a.score > b.score;
    }
}

int main() {
    int N;
    
    candidate[0].number = 1;
    candidate[1].number = 2;
    candidate[2].number = 3;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            int input;
            std::cin >> input;

            candidate[j].score += input;
            candidate[j].count[input-1]++;
        }
    }
    
    std::sort(candidate, candidate + 3, Comp);
    
    int max_value = candidate[0].score;
    int result = 0;

    bool flag = false;

    for(int i = 1; i < 3; i++) {
        if(max_value < candidate[i].score) {
            max_value = candidate[i].score;
            result = i;
        }
        else if(max_value == candidate[i].score) {
            int j = 0;
            
            for( ; j < 3; j++) {
                if(candidate[i].count[j] < candidate[result].count[j]) break;
                else if(candidate[i].count[j] > candidate[result].count[j]) {
                    max_value = candidate[i].score;
                    result = i;
                    break;        
                }
                else if(candidate[i].count[j] == candidate[result].count[j] && j == 2) {
                    flag = true;
                    break;
                }
            }

            if(flag) break;

        }
    }

    if(flag) {
        std::cout << 0 << " " << max_value << '\n';
    }
    else {
        std::cout << candidate[result].number << " " << max_value << '\n';
    }
    
}