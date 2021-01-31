
import java.util.*;

/**
 *  백준 1339번 단어 수학
 */

public class Baekjoon1339 {
    static int[] alphabet = new int[26];

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);
        int testCase = scanner_.nextInt();

        for(int i = 0; i < testCase; i++) {
            String input = scanner_.next();
            int size = input.length();

            for(int j = 0; j < size; j++) {
                alphabet[input.charAt(j)-'A'] += Math.pow(10, size -1 - j);
            }
        }

        Arrays.sort(alphabet);
        int number = 9;
        int result = 0;

        for(int j = 25; j >= 0; j--) {
            if(alphabet[j] == 0) break;

            result += alphabet[j] * number--;
        }

        System.out.println(result);


    }


}
