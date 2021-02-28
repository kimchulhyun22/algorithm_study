#include <string>
#include <vector>
#include <stack>

using namespace std;

int find_doll(vector<vector<int>>& board, int col) {
    for(int i = 0; i < board.size(); i++) {
        if(board[i][col] == 0) {
            continue;
        }
        
        // 가장 위에 있는 인형
        int doll = board[i][col];
        board[i][col] = 0;
        
        return doll;
    }
    
    return -1;
}

void move_doll(vector<vector<int>>& board, int col, stack<int>& s, int& count_of_removed_doll) {
    
    int doll = find_doll(board, col);
    
    // 스택이 비어있는 경우는 무조건 푸시
    if(s.empty()) {
        s.push(doll);
        return;
    }
    
    // 인형이 집어지지 않는 경우는 없겠으나 
    // 만약 발생하면 아무일도 발생하지 않는다
    if(doll == -1) {
        return;
    }
    
    // 없애는 경우
    if(s.top() == doll) {
        s.pop();
        count_of_removed_doll += 2;
    }
    // 안없애는 경우
    else {
        s.push(doll);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < moves.size(); i++) {
        move_doll(board, moves[i] - 1, s, answer);
    }
    
    return answer;
}