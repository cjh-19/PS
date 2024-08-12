import java.util.*;
import java.io.*;

public class Main {
    static int n; // 입력 받을 n
    static int[] dp;

    public static void main(String[] args) throws IOException {
        // 정수 n 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        dp = new int[n + 1];

        // 초기값 설정
        dp[0] = 0;
        dp[1] = 0;

        System.out.println(recurDp(n));
        br.close();
    }

    // 재귀를 통해 dp를 채워 나갈 함수
    static int recurDp(int N){
        if(N > 1 && dp[N] == 0) { // N이 1보다 크고, dp 값 저장이 안됐다면
            // 6으로 나눠지는 경우 - 3과 2와 1빼는 경우의 재귀함수를 모두 호출해서 최솟값을 dp[N]에 저장한다
            if (N % 6 == 0) {
                dp[N] = Math.min(Math.min(recurDp(N / 3), recurDp(N / 2)), recurDp(N - 1)) + 1;
            }
            // 3으로 나눠지는 경우
            else if (N % 3 == 0) {
                dp[N] = Math.min(recurDp(N - 1), recurDp(N / 3)) + 1;
            }
            // 2로 나눠지는 경우
            else if (N % 2 == 0) {
                dp[N] = Math.min(recurDp(N - 1), recurDp(N / 2)) + 1;
            }
            // 6으로 나눠지지 않는 경우(1빼기)
            else {
                dp[N] = recurDp(N - 1) + 1;
            }
        }

        return dp[N];
    }
}