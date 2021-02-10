import java.util.*;

class Solution {
    static ArrayList<String> answerList = new ArrayList<>();
    static String route = "";
    static boolean[] checked;

    public void dfs(String[][] tickets, String start, int count) {
        route += start + ",";

        // 모든 항공권을 사용했는지 체크
        if(count == tickets.length) {
            answerList.add(route);
            return;
        }

        for(int i = 0; i < tickets.length; i++) {
            String from = tickets[i][0];
            String to = tickets[i][1];

            if(!checked[i] && from.equals(start)) {
                // 다른 경로도 체크하기 위한 백트래킹
                checked[i] = true;

                dfs(tickets, to, count + 1);

                checked[i] = false;

                route = route.substring(0, route.length() - 4);
            }
        }
    }

    public String[] solution(String[][] tickets) {
        String[] answer = {};
        checked = new boolean[tickets.length];

        dfs(tickets, "ICN", 0);
        Collections.sort(answerList);

        answer = answerList.get(0).split(",");

        return answer;
    }
}