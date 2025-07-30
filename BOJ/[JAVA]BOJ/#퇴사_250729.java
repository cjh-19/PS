import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static int[] T, P, dp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		T = new int[N];
		P = new int[N];
		dp = new int[N+1];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken());
			P[i] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.print(dp[N]);
		
		br.close();
	}
	
	static void solve() {
		for(int i=0; i<N; i++) {
			// i + T[i] 날짜에 max(기존 i+T[i]날의 값, i번째 이익 추가)
			if(i + T[i] <= N) {
				dp[i + T[i]] = Math.max(dp[i + T[i]], dp[i] + P[i]);
			}
			/*
			 * 위의 코드로만 진행하면 예제 input에 대해서
			 * [0, 0, 0, 10, 30, 0, 45, 0]
			 * 라는 dp 값이 나옴
			 * => (i + T[i]) 날에 i번째 날의 상담 이익이 들어가 있지만,
			 * => 해당 날 이전까지의 이익이 반영되지 않은 구간도 있음
			 * => 즉, 상담을 하지 않은 날(dp[i+1])에도 이전까지의 최대 이익(dp[i])을 갱신해줘야 함
			 * => 그래야 상담을 건너뛰고 다음 날로 넘어갈 경우의 최댓값이 유지됨
			 */
			dp[i+1] = Math.max(dp[i], dp[i+1]);
		}
	}
}