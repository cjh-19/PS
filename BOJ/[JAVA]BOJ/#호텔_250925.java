import java.util.*;
import java.io.*;

public class Main {
	private static int C, N;
	private static int[] dp;
	private static int maxCus;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		dp = new int[C+100];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		maxCus = 100;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int cost = Integer.parseInt(st.nextToken());
			int cusCnt = Integer.parseInt(st.nextToken());
			maxCus = Math.max(maxCus, cusCnt);
			costCalc(cost, cusCnt);
		}
		
		int minCost = Integer.MAX_VALUE;
		for(int i=C; i<C+maxCus; i++) {
			minCost = Math.min(minCost, dp[i]);
		}
		System.out.print(minCost);
	}
	
	private static void costCalc(int cost, int cusCnt) {
		for(int i=cusCnt; i<C+maxCus; i++) {
			if(dp[i-cusCnt] == Integer.MAX_VALUE) continue;
			dp[i] = Math.min(dp[i], dp[i-cusCnt] + cost);
		}
	}
}
