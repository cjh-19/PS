import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static long[] A, B, C, D, sum1, sum2;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		A = new long[N];
		B = new long[N];
		C = new long[N];
		D = new long[N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		sumCalc();
		Arrays.sort(sum1);
		Arrays.sort(sum2);
		System.out.print(sumZero());
	}
	
	private static void sumCalc() {
		sum1 = new long[N*N];
		sum2 = new long[N*N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				sum1[N*i + j] = A[i] + B[j];
				sum2[N*i + j] = C[i] + D[j];
			}
		}
	}
	
	private static long sumZero() {
		long cnt = 0;
		for(int i=0; i<N*N; i++) {
			cnt += (upper_bound(-1*sum1[i]) - lower_bound(-1*sum1[i]));
		}
		return cnt;
	}
	
	private static int upper_bound(long target) {
		int s = 0, e = N*N;
		while(s<e) {
			int mid = (s+e)/2;
			if(sum2[mid] <= target) {
				s = mid+1;
			} else e = mid;
		}
		return s;
	}
	
	private static int lower_bound(long target) {
		int s = 0, e = N*N;
		while(s<e) {
			int mid = (s+e)/2;
			if(sum2[mid] < target) {
				s = mid+1;
			} else e = mid;
		}
		return s;
	}
}
