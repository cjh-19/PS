import java.util.*;
import java.io.*;

public class Main {
	private static int V, maxDist, startIdx;
	private static List<int[]>[] edgeList;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		V = Integer.parseInt(br.readLine());
		edgeList = new ArrayList[V+1];
		for(int i=0; i<=V; i++) edgeList[i] = new ArrayList<>();
		for(int i=0; i<V; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			while(true) {
				int n2 = Integer.parseInt(st.nextToken());
				if(n2==-1) break;
				int w = Integer.parseInt(st.nextToken());
				
				edgeList[n1].add(new int[] {n2, w});
			}
		}
		
		maxDist=0;
		startIdx=0;
		boolean[] v = new boolean[V+1];
		v[1]=true;
		dfs(1, v, 0);
		v[1]=false;
		maxDist=0;
		v[startIdx]=true;
		dfs(startIdx, v, 0);
		System.out.print(maxDist);
	}
	
	private static void dfs(int idx, boolean[] visited, int dist) {
		boolean flag = false;
		
		for(int[] e : edgeList[idx]) {
			if(!visited[e[0]]) {
				visited[e[0]] = true;
				dfs(e[0], visited, dist+e[1]);
				visited[e[0]] = false;
				flag = true;
			}
		}
		if(!flag) {
			if(maxDist<dist) {
				maxDist = dist;
				startIdx = idx;
			}
			return;
		}
	}
}
