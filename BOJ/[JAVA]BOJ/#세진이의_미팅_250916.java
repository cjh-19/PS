import java.util.*;
import java.io.*;

public class Main {
	private static int N, K;
	private static final int MOD = 1_000_000_007;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		long result = factorial(N);
		long powValue = (factorial(N-K) * factorial(K)) % MOD;
		powValue = pow(powValue, MOD-2);
		
		System.out.println((result * powValue) % MOD);
	}
	
	private static long factorial(int n) {
		long fac = 1;
		for(int i=n; i>=1; i--) {
			fac = (fac * i) % MOD;
		}
		return fac;
	}
	
	private static long pow(long num, long p) {
		if(p==0) return 1;
		
		long res = pow(num, p/2) % MOD;
		
		if(p%2==0) return (res * res) % MOD;
		else return (((res * res) % MOD) * num) % MOD;
	}
}
