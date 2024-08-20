import java.util.*;
import java.io.*;

public class Main {
    static int N; // 집의 수
    static int[][] RGB; // 각 집의 빨 초 파 비용
    static int[][] dp;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException  {
        /*
        문제
        1. 1번 집부터 N번집
        2. 집은 R, G, B 중 하나의 색으로 칠해야 하며, 각 집마다 색의 비용이 다르다
        3. 규칙을 만족 하면서 모든 집을 칠하는 비용의 최솟값

        규칙
        1. 1번 집의 색은 2번 집, N번 집의 색과 같지 않아야 한다
        2. N번 집의 색은 N-1번 집, 1번 집의 색과 같지 않아야 한다
        3. i(2<=i<=N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다
        => 근접한 집의 색은 서로 달라야 한다. 집은 원의 형태다. 1번 집과 N번 집이 이어져 있다.
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

        // 0~2번 집 각 경우의 수로 dp값 계산
        for(int start=0; start<3; start++){
            // 0번 집 고정
            for(int j=0; j<3; j++){
                if(start == j) dp[0][j] = RGB[0][j];
                else dp[0][j] = 1001 * 1001;
            }

            // 1번 집부터 N-1번 집까지
            for(int i=1; i<N; i++){
                dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + RGB[i][0];
                dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + RGB[i][1];
                dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + RGB[i][2];
            }

            // start번을 제외하고 min값 업데이트
            for(int j=0; j<3; j++){
                if(start != j) min = Math.min(dp[N-1][j], min);
            }
        }

        System.out.println(min);
        br.close();
    }
}