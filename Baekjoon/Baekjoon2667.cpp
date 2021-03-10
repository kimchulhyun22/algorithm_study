/*
    백준 2667번 단지번호붙이기
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void DFS(const std::vector<std::vector<int>>& map, std::vector<std::vector<int>>& checked, 
        int x, int y, int& count_of_house, const int& number) {
    
    checked[x][y] = number;
    int result = 0;
    count_of_house++;

    // 4방향 탐색
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_x >= map[0].size() || next_y < 0 || next_y >= map[0].size() || checked[next_x][next_y] != -1) continue;

        DFS(map, checked, next_x, next_y, count_of_house, number);
    }   
}

void solution(const std::vector<std::vector<int>>& map, std::vector<std::vector<int>>& checked, const int& N) {

    std::vector<int> answer;
    int number = 0;
    
    // 방문하지 않은 곳을 DFS로 탐색
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            if(checked[i][j] == -1) {
                int count_of_house = 0;
                DFS(map, checked, i, j, count_of_house, ++number);
                answer.push_back(count_of_house);
            }
        }
    }

    sort(answer.begin(), answer.end());

    std::cout << answer.size() << std::endl;

    for(int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << std::endl;
    }
}

int main() {
    int N;
    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> checked;

    std::string input;

    std::cin >> N;

    map.resize(N);
    checked.resize(N);

    for(int i = 0; i < N; i++) {
        std::cin >> input;

        for(int j = 0; j < N; j++) {
            map[i].push_back(input[j]-'0');
            
            if(input[j] == '0') {
                checked[i].push_back(0);
            }
            else {
                checked[i].push_back(-1);
            }
        }
    }

    solution(map, checked, N);


    return 0;
}