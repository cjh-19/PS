import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        final int INF = 1_000_0004;
        int[] dp = new int[N+1];
        int[] parent = new int[N+1];
        Arrays.fill(dp, INF);
        dp[1] = 0;
        parent[1] = 0;

        for(int i=1; i<N; i++) {
            if(dp[i] == INF) continue;

            if(dp[i+1] > dp[i]+1) {
                dp[i+1] = dp[i]+1;
                parent[i+1] = i;
            }
            if(i*2 <= N && (dp[i*2] > dp[i]+1)) {
                dp[i*2] = dp[i]+1;
                parent[i*2] = i;
            }
            if(i*3 <= N && (dp[i*3] > dp[i]+1)) {
                dp[i*3] = dp[i]+1;
                parent[i*3] = i;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp[N]).append("\n");
        int idx = N;
        while(idx>=1) {
            sb.append(idx).append(" ");
            idx = parent[idx];
        }
        System.out.print(sb);
    }
}
