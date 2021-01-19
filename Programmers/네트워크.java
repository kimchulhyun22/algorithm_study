class Solution {

    static boolean[] checked;

    public void dfs(int n, int[][] computers, int v) {
        checked[v] = true;

        for(int i = 0; i < n; i++) {
            if(computers[v][i] == 1 && !checked[i]) {
                dfs(n, computers, i);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        checked = new boolean[n];

        for(int i = 0; i < n; i++) {
            // 이미 방문한 노드는 무시
            if(checked[i]) continue;

            answer++;

            dfs(n, computers, i);

        }

        return answer;
    }
}