import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int K;
    static int[][] dp;
    static int mod = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        dp = new int[N + 1][K + 1]; // 값 0으로 초기화
        // 점화식: dp[N][K] = dp[N-1][K] + dp[N][K-1]
        // K가 0일때 만들 수 있는 경우의 수: 0개, K가 1일때 만들 수 있는 경우의 수 1개(N값)
        for(int i=0; i<=N; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        // N이 1일때 만들 수 있는 경우의 수 K개 : 1 + 0 + 0 ...
        for(int i=0; i<=K; i++){
            dp[1][i] = i;
        }

        // bottom-up으로 dp 채우기
        for(int i=2; i<=N; i++){
            for(int j=2; j<=K; j++){
                // (x+y)%mod = x%mod + y%mod : 덧셈법칙에 근거해 나눈 값을 저장해도 됨
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }

        System.out.println(dp[N][K]);
        br.close();
    }
}