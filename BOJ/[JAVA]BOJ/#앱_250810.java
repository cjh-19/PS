import java.io.*;
import java.util.*;

public class Main {
    static int N, M, sumCost;
    static int[] Memorys, Costs, dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Memorys = new int[N];
        Costs = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            Memorys[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            Costs[i] = Integer.parseInt(st.nextToken());
            sumCost += Costs[i];
        }

        dp = new int[sumCost + 1];

        solve();

        br.close();
    }

    private static void solve() {
        // dp[cost] = 주어진 총 비용으로 얻을 수 있는 최대 메모리
        // dp[cost] >= M 인 가장 작은 cost가 정답
        // 각 앱에 대해서 뒤에서부터 dp 갱신
        for(int i=0; i<N; i++) {
            // 최대 비용부터 i번째 앱의 비활성 비용까지 dp 갱신
            for(int c = sumCost; c>=Costs[i]; c--) {
                dp[c] = Math.max(dp[c], dp[c - Costs[i]] + Memorys[i]);
            }
        }

        for(int c=0; c<=sumCost; c++) {
            if(dp[c] >= M) {
                System.out.println(c);
                break;
            }
        }
    }
}