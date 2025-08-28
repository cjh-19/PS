import java.util.*;
import java.io.*;

public class Main {
	private static int N, S;
	private static int[] numbers;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		
		numbers = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) numbers[i] = Integer.parseInt(st.nextToken());
		
		int s=0, e=0;
		int sum = numbers[0];
		int len = Integer.MAX_VALUE;
		while(s<=e) {
			if(sum < S && e<N-1) sum += numbers[++e];
			else if(sum >= S) {
				len = Math.min(len, e-s+1);
				sum -= numbers[s++];
			} else if(e == N-1) {
				sum -= numbers[s++];
			}
		}
		if(len == Integer.MAX_VALUE) System.out.println(0);
		else System.out.println(len);
	}
}