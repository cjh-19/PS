import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int[][] dp = new int[N+1][N+1];
		
		for(int i=0; i<=N; i++) {
			// 각 행의 시작과 끝은 1
			dp[i][0] = 1;
			dp[i][i] = 1;
			
			// 사의의 값 넣기
			for(int j=1; j<i; j++) {
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
			}
		}
		
		System.out.print(dp[N][K]);
	}
}
