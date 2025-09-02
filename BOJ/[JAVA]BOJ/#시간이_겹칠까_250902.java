import java.util.*;
import java.io.*;

public class Main {
	private static int N, Q;
	private static int[] diff;
	private static final int MAX_TIME = 1_000_002;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		diff = new int[MAX_TIME];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			
			diff[s] += 1;
			diff[e+1] -= 1;
		}
		
		int[] result = new int[MAX_TIME];
		for(int i=1; i<MAX_TIME; i++) {
			result[i] += diff[i] + result[i-1];
		}
		
		StringBuilder sb = new StringBuilder();
		Q = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<Q; i++) {
			sb.append(result[Integer.parseInt(st.nextToken())]).append("\n");
		}
		
		System.out.println(sb.toString());
	}
}
