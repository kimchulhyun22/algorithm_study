
import java.awt.*;
import java.util.*;

/**
 *  백준 1039번 교환
 */

public class Main {
    static int N, M, K;
    static boolean checked[][] = new boolean[1000001][11];

    /**
     *  각 정수 N의 자릿수 구하는 메소드
     * @param N 자릿수 구하려는 정수
     * @return
     */
    public static int[] getParseNumber(int N) {
        int[] parseNumber = new int[M];

        for(int i = M - 1; i >= 0; i--) {
            parseNumber[i] = N % 10;
            N /= 10;
        }

        return parseNumber;
    }

    /**
     * 각 자릿수를 통해 정수를 구하는 메소드
     * @param parseNumber 자릿수 배열
     * @return
     */
    public static int getCalculatedNumber(int[] parseNumber) {
        int index = 1;
        int sum = 0;

        for(int i = M - 1; i >= 0; i--) {
            sum += parseNumber[i] * index;
            index *= 10;
        }

        return sum;
    }

    /**
     * 자릿수 i와 j의 값을 교체한 정수를 구하는 메소드
     * @param number 정수
     * @param i 자릿수
     * @param j 자릿수
     * @return
     */
    public static int doChange(int number, int i, int j) {
        int[] parseNumber = getParseNumber(number);

        if(i == 0 && parseNumber[j] == 0)
            return -1;

        int tmp = parseNumber[i];
        parseNumber[i] = parseNumber[j];
        parseNumber[j] = tmp;

        return getCalculatedNumber(parseNumber);
    }

    /**
     * 너비우선 탐색을 통해 계산한다
     */
    public static void bfs() {
        Queue<Point> q = new LinkedList<>();

        checked[N][0] = true;
        q.add(new Point(N,0));

        int result = -1;

        while(!q.isEmpty()) {
            Point currentNumber = q.poll();

            // K번 연산 수행 끝
            if(currentNumber.y == K) {
                result = Math.max(result, currentNumber.x);
                continue;
            }

            for(int i = 0; i < M; i++) {
                for(int j = i + 1; j < M; j++) {
                    int nextNumber = doChange(currentNumber.x, i, j);

                    if(nextNumber != -1 && !checked[nextNumber][currentNumber.y + 1]) {
                        q.add(new Point(nextNumber, currentNumber.y + 1));
                        checked[nextNumber][currentNumber.y + 1] = true;
                    }
                }
            }

        }

        System.out.println(result);
    }

    public static void main(String[] args) {
        Scanner scanner_ = new Scanner(System.in);

        N = scanner_.nextInt();
        K = scanner_.nextInt();
        M = 0;

        int tempNum = N;

        while(tempNum > 0) {
            M++;
            tempNum /= 10;
        }

        bfs();

    }



}
