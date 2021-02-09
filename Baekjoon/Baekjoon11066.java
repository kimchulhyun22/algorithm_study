
import java.util.*;
import java.awt.Point;

/**
 *  백준 11066번 파일 합치기
 */

public class Baekjoon11066 {

    static int testCase;
    static int n;
    static int[] files;
    static int[] sum;
    static int[][] dp;

    static int sumStartToEnd(int start, int end) {
        if (start == 0) {
            return sum[end];
        } else {
            return sum[end] - sum[start - 1];
        }
    }

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        testCase = scanner_.nextInt();

        while(testCase-- > 0) {
            n = scanner_.nextInt();
            files = new int[n];
            sum = new int[n];
            dp = new int[n][n];

            for(int i = 0; i < n; i++) {
                files[i] = scanner_.nextInt();
            }

            // 초기 배열값 셋팅
            sum[0] = files[0];

            for(int i = 1; i < n; i++) {
                sum[i] = sum[i-1] + files[i];
            }

            for(int j = 1; j < n; j++) { //열
                for(int i = j -1 ; i >= 0; i--) { //행

                    dp[i][j] = Integer.MAX_VALUE;

                    // i~j까지 파일을 합치는 최소 비용
                    for(int k = i; k < j; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }

                    dp[i][j] += sumStartToEnd(i, j);
                }
            }

            System.out.println(dp[0][n - 1]);
        }

    }

}
