
import java.util.*;
import java.awt.Point;

/**
 *  백준 1967번 트리의 지름
 */

public class Baekjoon1967 {

    static ArrayList<Point>[] graph;
    static int n;
    static boolean[] checked;

    static int result = 0;
    static Point resultPoint = null;

    public static void dfs(Point start, int cost) {
        checked[start.x] = true;

        for(Point next : graph[start.x]) {
            if(checked[next.x]) continue;

            dfs(next, cost + next.y);
        }

        if(result < cost) {
            result = cost;
            resultPoint = start;
        }

    }

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        n = scanner_.nextInt();
        graph = new ArrayList[n+1];
        checked = new boolean[n+1];

        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        // 엣지가 없는 경우는 지름은 항상 0
        if(n == 1) {
            System.out.println(0);
            return;
        }

        for(int i = 0; i < n-1; i++) {
            int from = scanner_.nextInt();
            int to = scanner_.nextInt();
            int cost = scanner_.nextInt();

            graph[from].add(new Point(to, cost));
            graph[to].add(new Point(from, cost));
        }

        // 가장 지름이 긴 노드 탐색
        dfs(graph[1].get(0), 0);
        Point tmp = new Point(resultPoint);

        result = 0;
        resultPoint = null;
        checked = new boolean[n+1];

        dfs(tmp, 0);
        System.out.println(result);
    }

}
