import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static List<Integer>[] nodeList;
	private static boolean[] visited;

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("Test3.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		nodeList = new ArrayList[N+1];
		for(int i=0; i<=N; i++) nodeList[i] = new ArrayList<>();
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			
			nodeList[n1].add(n2);
			nodeList[n2].add(n1);
		}
		
		visited = new boolean[N+1];
		int groupCnt = 0;
		for(int i=1; i<=N; i++) {
			if(!visited[i]) {
				bfs(i);
				groupCnt++;
			}
		}
		
		System.out.print(groupCnt);
	}
	
	private static void bfs(int node) {
		Queue<Integer> q = new ArrayDeque<>();
		q.offer(node);
		visited[node] = true;
		
		while(!q.isEmpty()) {
			int n = q.poll();
			
			for(int x : nodeList[n]) {
				if(!visited[x]) {
					visited[x] = true;
					q.offer(x);
				}
			}
		}
	}

}
