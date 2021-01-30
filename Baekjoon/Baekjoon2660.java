
import java.util.*;
import java.awt.Point;

/**
 *  백준 2660번 회장 뽑기
 */

public class Baekjoon2660 {
    static int[][] arry;
    static int[] score;
    static int N;

    public static int bfs(int start) {
        boolean[] checked = new boolean[N+1];
        int depth = 0;

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(start, depth));

        checked[start] = true;
        int result = 0;

        while(!q.isEmpty()) {
            Point current = q.poll();

            for(int i = 1; i <= N; i++) {

                if(checked[i] || arry[current.x][i] != 1) continue;

                checked[i] = true;
                q.add(new Point(i, current.y + 1));
                result = Math.max(result, current.y + 1);

            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        N = scanner_.nextInt();
        arry = new int[N+1][N+1];
        score = new int[N+1];

        while(true) {
            int start = scanner_.nextInt();
            int end = scanner_.nextInt();

            if(start == -1 && end == -1) break;

            arry[start][end] = 1;
            arry[end][start] = 1;
        }

        int[] result = new int[N+1];
        int maxScore = Integer.MAX_VALUE;
        int maxCount = 0;

        // 각 회장번호마다 bfs를 통해 탐색
        // 모든 정점은 연결되어 있으므로 연결되지 않은 경우는 제외
        for(int i = 1; i <= N ;i++) {
            result[i] = bfs(i);
            maxScore = Math.min(maxScore, result[i]);
        }

        ArrayList<Integer> maxNumber = new ArrayList<>();

        for(int i = 1; i <= N ;i++) {
            if(result[i] == maxScore) {
                maxNumber.add(i);
                maxCount++;
            }
        }

        System.out.println(maxScore + " " + maxCount);
        for(Integer i : maxNumber) {
            System.out.print(i + " ");
        }
    }


}
