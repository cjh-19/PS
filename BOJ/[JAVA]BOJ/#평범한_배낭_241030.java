import java.io.*;
import java.util.*;

public class Main {
    private static int N, K; // 물품 수, 배낭 무게
    private static int[][] metal; // 금속 무게, 가격
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        input(br, st);
        knapsack();

        br.close();
    }

    // 입력 메소드
    private static void input(BufferedReader br, StringTokenizer st) throws IOException {
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        metal = new int[N][2];
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            metal[i][0] = Integer.parseInt(st.nextToken());
            metal[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    // 배낭에 담기 메소드
    private static void knapsack(){
        dp = new int[N+1][K+1]; // N번째 보석을 탐색하고, 배낭의 크기를 모두 추가한 경우

        // i번째 보석이 들어갈 수 없는 경우 vs i번째 보석이 들어갈 수 있는 경우
        for(int i=0; i<=N; i++){
            // 담을 수 있는 무게 전체 순회
            for(int j=0; j<=K; j++){
                if(i==0 || j==0){ // 보석을 담지 않거나 무게가 없는 경우
                    dp[i][j] = 0;
                }
                else if(metal[i-1][0] <= j) { // j무게를 담을 건데, 현재 보석 무게가 j 이하라면
                    // [현재 보석 가격 + j-현재보석무게 대비 i-1개 보석까지의 최대 가격 vs j무게 대비 i-1개 보석]의 최대값
                    dp[i][j] = Math.max(metal[i-1][1] + dp[i-1][j-metal[i-1][0]], dp[i-1][j]);
                }
                else { // 보석 무게가 초과인 경우
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        System.out.println(dp[N][K]);
    }
}
