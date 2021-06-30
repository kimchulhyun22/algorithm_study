/*
    백준 7569번 토마토
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Position {
    int x;
    int y;
    int z;
};

int M, N, H;
int tomato[101][101][101];
// 동 서 남 북 위 아래
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

void print() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                std::cout << tomato[i][j][k] << " ";
            }
            std::cout << '\n';
        }
    }
    std::cout << '\n';

}

int main() {
   std::cin >> M >> N >> H;

    std::queue<Position> q;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                std::cin >> tomato[i][j][k];
                Position p;
                if(tomato[i][j][k] == 1) {
                        
                        p.x = k;
                        p.y = j;
                        p.z = i;
                        q.push(p);                
                }
            }
        }
    }

    int days = 0;

    // BFS 탐색
    while(!q.empty()) {

        int loop = q.size();

        for(int i = 0; i < loop; i++) {
            Position current = q.front();
            q.pop();

            //std::cout << current.x << " " << current.y << " " << current.z << '\n';

            for(int i = 0; i < 6; i++) {
                Position next;
                next.x = current.x + dx[i];
                next.y = current.y + dy[i];
                next.z = current.z + dz[i];

                if(next.x < 0 || next.y < 0 || next.z < 0 ||
                    next.x >= M  || next.y >= N  || next.z >= H ||
                    tomato[next.z][next.y][next.x] != 0 )  {
                    continue;
                }

                tomato[next.z][next.y][next.x] = 1;
                q.push(next);
            }

        }
        days++;

    }

    for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
                // 안 익은 토마토가 존재하는 경우
				if (tomato[i][j][k] == 0) {
					days = 0;
					break;
				}
			}
		}
	}

    std::cout << days - 1 << '\n';
}