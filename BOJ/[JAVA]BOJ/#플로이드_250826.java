import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static int[][] fw;
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		fw = new int[N][N];
		for(int i=0; i<N; i++) {
			Arrays.fill(fw[i], Integer.MAX_VALUE);
			fw[i][i]=0;
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken())-1;
			int n2 = Integer.parseInt(st.nextToken())-1;
			int w = Integer.parseInt(st.nextToken());
			
			fw[n1][n2] = Math.min(fw[n1][n2], w);
		}
		
		for(int k=0; k<N; k++) {
			for(int j=0; j<N; j++) {
				for(int i=0; i<N; i++) {
					if((fw[i][k] == Integer.MAX_VALUE) || (fw[k][j] == Integer.MAX_VALUE)) continue;
					
					fw[i][j] = Math.min(fw[i][j], fw[i][k] + fw[k][j]);
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(fw[i][j] == Integer.MAX_VALUE) fw[i][j] = 0;
				sb.append(fw[i][j]).append(" ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb.toString());
	}
}
