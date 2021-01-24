
import java.util.*;

/**
 *  백준 1806번 부분합
 */

public class Baekjoon1806 {

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        int N = scanner_.nextInt();
        int S = scanner_.nextInt();
        int[] numbers = new int[N+1];

        for(int i = 0; i < N; i++) {
            numbers[i] = scanner_.nextInt();
        }

        int left = 0;
        int right = 0;
        long result = Long.MAX_VALUE;

        long sum = numbers[left];

        while(left <= right && right < N) {

            if(sum < S) {
                sum += numbers[++right];
            }
            else {
                result = Math.min(result, right-left+1);
                sum -= numbers[left++];
            }
        }

        System.out.println(result == Long.MAX_VALUE ? 0 : result);

    }

}
