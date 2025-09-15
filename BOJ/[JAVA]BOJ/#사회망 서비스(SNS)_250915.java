import java.util.*;
import java.io.*;

public class Main {
	private static int N, count;
	private static List<Integer>[] nodeList;
	private static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		nodeList = new ArrayList[N+1];
		for(int i=0; i<=N; i++) nodeList[i] = new ArrayList<>();
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			nodeList[n1].add(n2);
			nodeList[n2].add(n1);
		}
		
		count = 0;
		visited = new boolean[N+1];
		dfs(1);
		System.out.println(count);
	}
	
	private static boolean dfs(int idx) {
		visited[idx] = true;
		int subCnt = 0;
		int cnt = 0;
		for(int n : nodeList[idx]) {
			if(visited[n]) continue;
			if(dfs(n)) cnt++;
			subCnt++;
		}
		if(subCnt == cnt) return false;
		count++;
		return true;
	}
}
