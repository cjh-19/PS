import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static long[] A;
	private static long[] memo;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		
		A = new long[N];
		memo = new long[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		
		lis();
	}
	
	private static void lis() {
		memo[0] = A[0];
		
		int idx = 0;
		for(int i=1; i<N; i++) {
			if(memo[idx] < A[i]) {
				memo[++idx] = A[i];
			} else if (memo[0] < A[i]) {
				binarySearch(A[i]);
			}
		}
		
		System.out.print(idx + 1);
	}
	
	private static void binarySearch(long num) {
		int midIdx = N/2, startIdx = 0, endIdx = N-1;
		
		while(startIdx < endIdx) {
			if(memo[midIdx] == num) return;
			
			else if((midIdx - 1 >= 0) && memo[midIdx - 1] < num) {
				if(memo[midIdx] > num) {
					memo[midIdx-1] = num;
					return;
				} else {
					startIdx = midIdx;
					midIdx = (startIdx + endIdx) / 2;
				}
			} else {
				endIdx = midIdx;
				midIdx = (startIdx + endIdx) / 2;
			}
		}
	}
}
