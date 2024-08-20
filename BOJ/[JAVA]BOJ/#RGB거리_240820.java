import java.util.*;
import java.io.*;

public class Main {
    static int N; // 집의 수
    static int[][] RGB; // 각 집의 빨 초 파 비용
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
        RGB = new int[N][3];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            RGB[i][0] = Integer.parseInt(st.nextToken());
            RGB[i][1] = Integer.parseInt(st.nextToken());
            RGB[i][2] = Integer.parseInt(st.nextToken());
        }

        // dp 계산
        // dp[i][0] += min(dp[i-1][1], dp[i-1][2]) + RGB[i][0] ...

        dp = new int[N][3];

        // 첫번째 집 각 색 비용
        dp[0][0] = RGB[0][0];
        dp[0][1] = RGB[0][1];
        dp[0][2] = RGB[0][2];

        // 1번 집부터 N-1번 집까지
        for(int i=1; i<N; i++){
            dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + RGB[i][0];
            dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + RGB[i][1];
            dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + RGB[i][2];
        }

        System.out.println(Math.min(Math.min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]));
        br.close();
    }
}