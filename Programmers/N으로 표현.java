class Solution {
    static int[] numbers = new int[8];
    static int answer = -1;

    public void dfs(int number, int count,
                    int currentNumber) {
        if(count > 8) {
            return;
        }

        if(number == currentNumber) {
            if(answer == -1 || answer > count) {
                answer = count;
            }
            return;
        }

        for(int i = 0; i < 8; i++) {
            dfs(number, count + i + 1, currentNumber + numbers[i]);
            dfs(number, count + i + 1, currentNumber - numbers[i]);
            dfs(number, count + i + 1, currentNumber * numbers[i]);
            dfs(number, count + i + 1, currentNumber / numbers[i]);
        }

    }

    public int solution(int N, int number) {
        numbers[0] = N;

        // 8자리 N으로 표현된 수를 미리 계산
        for(int i = 1; i < 8; i++) {
            numbers[i] = numbers[i-1] * 10 + N;
        }

        dfs(number, 0, 0);

        return answer;
    }
}