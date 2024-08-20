import java.util.*;
import java.io.*;

public class Main {
    static int N; // 집의 수
    static int[] R, G, B; // 각 집의 빨 초 파 비용
    static int[][] dp;

    public static void main(String[] args) throws IOException  {
        /*
        문제
        1. 1번 집부터 N번집
        2. 집은 R, G, B 중 하나의 색으로 칠해야 하며, 각 집마다 색의 비용이 다르다
        3. 규칙을 만족 하면서 모든 집을 칠하는 비용의 최솟값

        규칙
        1. 1번 집의 색은 2번 집의 색과 같지 않아야 한다
        2. N번 집의 색은 N-1번 집의 색과 같지 않아야 한다
        3. i(2<=i<=N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다
        => 근접한 집의 색은 서로 달라야 한다.
        */

        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = new int[N];
        G = new int[N];
        B = new int[N];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            R[i] = Integer.parseInt(st.nextToken());
            G[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
        }

        // dp 계산
        // dp[i][j] += min(dp[i-1][1], dp[i-1][2]) ...

        dp = new int[N][3];

        // 첫번째 집 각 색 비용
        dp[0][0] = R[0];
        dp[0][1] = G[0];
        dp[0][2] = B[0];

        // 1번 집부터 N-1번 집까지
        for(int i=1; i<N; i++){
            for(int j=0; j<3; j++){
                if(j == 0){ // R 색상 선택
                    dp[i][j] += Math.min(dp[i-1][1], dp[i-1][2]) + R[i];
                }
                else if(j == 1){ // G 색상 선택
                    dp[i][j] += Math.min(dp[i-1][0], dp[i-1][2]) + G[i];
                }
                else{ // B 색상 선택
                    dp[i][j] += Math.min(dp[i-1][0], dp[i-1][1]) + B[i];
                }
            }
        }
        System.out.println(Math.min(Math.min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]));
        br.close();
    }
}