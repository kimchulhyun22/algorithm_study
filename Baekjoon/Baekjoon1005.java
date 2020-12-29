
import java.util.*;

/**
 *  백준 1005번 ACM Craft
 */
public class Baekjoon1005 {
    static int testCase;
    static int N, K;
    static int[] buildTime;
    static int[] checked;
    static ArrayList<ArrayList<Integer>> graph;
    static int target;

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        testCase = scanner_.nextInt();

        while(testCase-- > 0) {
            N = scanner_.nextInt();
            K = scanner_.nextInt();

            // 각 건물을 짓는데 걸리는 시간
            buildTime = new int[N+1];

            // 이전의 지어져야 하는 건물의 수
            checked = new int[N+1];

            graph = new ArrayList<ArrayList<Integer> >();

            graph.add(new ArrayList<Integer>());

            for(int i = 1; i <= N; i++) {
                graph.add(new ArrayList<Integer>());
                buildTime[i] = scanner_.nextInt();
            }

            for(int i = 0; i < K; i++) {
                int u = scanner_.nextInt();
                int v = scanner_.nextInt();

                graph.get(u).add(v);
                checked[v]++;
            }

            target = scanner_.nextInt();

            System.out.println(buildCraft());
        }

    }

    public static int buildCraft() {
        int[] dist = new int[N+1];
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= N; i++) {
            dist[i] = buildTime[i];
                if(checked[i] == 0) {
                q.add(i);
            }
        }

        while(!q.isEmpty()) {
            int vertex = q.poll();

            for(Integer i : graph.get(vertex)) {
                dist[i] = Math.max(dist[i], dist[vertex] + buildTime[i]);
                checked[i]--;

                // 이전의 지어져야할 건물들이 모두 지어진 경우
                if(checked[i] == 0) {
                    q.add(i);
                }

            }
        }


        return dist[target];
    }

}
