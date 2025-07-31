import java.util.*;
import java.io.*;

public class Solution {
	static StringBuilder sb = new StringBuilder();
	static int T, N, P;
	static int[] coin;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			P = Integer.parseInt(st.nextToken());
			
			coin = new int[P];
			
			for(int i=0; i<P; i++) {
				coin[i] = N / P;
			}
			
			int etc = N % P;
			
			int idx = 0;
			while(etc > 0) {
				coin[idx++] += 1;
				etc--;
			}
			
			long candy = 1;
			for(int i=0; i<P; i++) {
				candy *= coin[i];
			}
			
			sb.append("#").append(t).append(" ").append(candy).append("\n");
		}
		
		System.out.println(sb);
		br.close();
	}
}