import java.util.*;
import java.io.*;

public class Main {
	private static long A, B;
	private static long[] dp;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		A = Long.parseLong(st.nextToken());
		B = Long.parseLong(st.nextToken());
		
		dp = new long[59];
		
		long idx = 1;
		for(int i=1; i<59; i++) {
			dp[i]=i*idx;
			idx*=2;
		}
		System.out.print(oneCalc(B) - oneCalc(A-1));
	}
	
	private static long oneCalc(long num) {
		if (num <= 0) return 0;
        if (num == 1) return 1;
		
        int high = bitCalc(num);
        if ((1L << high) > num) high--;
		long p = 1L << high;
		return dp[high] + (num-p+1) + oneCalc(num-p);
	}
	
	private static int bitCalc(long num) {
		int s=0, e=63;
		while(s<e) {
			int mid = (s+e)/2;
			if((1L << mid) < num) s = mid+1;
			else e = mid;
		}
		return s;
	}
}