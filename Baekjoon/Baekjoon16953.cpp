/*
    백준 16953번 A->B
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

long long BFS(const long long& A, const long long& B) {
    long long result = LLONG_MAX;
    std::queue<std::pair<long long, long long>> q;

    q.push(std::make_pair(A, 0));
    
    while(!q.empty()) {
        long long number = q.front().first;
        long long count = q.front().second;

        q.pop();
        
        if(number > B) continue;

        if(number == B) {
            result = std::min(result, count);
            break;
        }

        q.push(std::make_pair(number*2, count+1));
        q.push(std::make_pair(number*10 + 1, count+1));
    }

    return result == LLONG_MAX ? -1 : result + 1;
}

int main() {
    long long A, B;

    std::cin >> A >> B;

    std::cout << BFS(A, B) << '\n';

}