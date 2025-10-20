import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[] post, idx;
	private static StringBuilder sb;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		post = new int[N];
		idx = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			idx[Integer.parseInt(st.nextToken())] = i;
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			post[i] = Integer.parseInt(st.nextToken());
		}
		
		sb = new StringBuilder();
		dfs(0, N-1, 0, N-1);
		System.out.println(sb);
	}
	
	private static void dfs(int s, int e, int ss, int ee) {
		if(s>e || ss>ee) return;
		
		int root = post[ee];
		int rootIdx = idx[root];
		sb.append(root).append(" ");
		
		int tsize = rootIdx-s-1;
		dfs(s, rootIdx-1, ss, ss+tsize);
		dfs(rootIdx+1, e, ss+tsize+1, ee-1);
	}
}
