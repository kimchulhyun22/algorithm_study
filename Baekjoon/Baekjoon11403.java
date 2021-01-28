
import java.util.*;

/**
 *  백준 11403번 경로 찾기
 */

public class Baekjoon11403 {
    static int[][] arry;
    static int N;

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        N = scanner_.nextInt();
        arry = new int[N][N];

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                arry[i][j] = scanner_.nextInt();
            }
        }

        for(int i = 0; i < N; i++) {
            int[] checked = new int[N];

            // 시작점부터 갈 수 있는 정점을 dfs로 체크
            dfs(i, checked);

            for(int j = 0; j < N; j++) {
                System.out.print(checked[j] + " ");
            }

            System.out.println();
        }

    }

    public static void dfs(int start, int[] checked) {
        for(int i = 0; i < N; i++) {
            if(arry[start][i] == 1 && checked[i] == 0) {
                checked[i] = 1;
                dfs(i, checked);
            }
        }
    }
}
