import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> s = new Stack();

        for(int i = 0; i < prices.length; i++) {

            // 현재 가격보다 스택에 있는 가격이 더 큰 경우는
            // 가격이 하락한 경우이므로 기간을 갱신

            while(!s.empty() && prices[i] < prices[s.peek()]) {
                answer[s.peek()] = i - s.peek();
                s.pop();
            }

            s.push(i);
        }

        // 스택에 남아있는 경우는 끝까지 가격이 떨어지지 않은 경우
        while(!s.empty()) {
            answer[s.peek()] = (prices.length - 1) - s.peek();
            s.pop();
        }

        return answer;
    }
}