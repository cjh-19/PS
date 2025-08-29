/* dfs 재귀 처리 - 실행 속도 1등 */
import java.util.*;
import java.io.*;

public class Main {
	private static int N, R, Q;
	private static List<Integer>[] nodeList;
	private static int[] subSize;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		nodeList = new ArrayList[N+1];
		subSize = new int[N+1];
		for(int i=0; i<N+1; i++) nodeList[i] = new ArrayList<>();
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			nodeList[u].add(v);
			nodeList[v].add(u);
		}
		
		dfs(R, 0); // 현재 노드, 부모 노드
		
		StringBuilder sb = new StringBuilder();
		for(int q=0; q<Q; q++) {
			int u = Integer.parseInt(br.readLine());
			sb.append(subSize[u]).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void dfs(int u, int p) {
		subSize[u] = 1;
		for(int v : nodeList[u]) {
			if(v==p) continue; // 부모로 되돌아가지 않음
			dfs(v, u);
			subSize[u] += subSize[v]; // 자식 서브트리 크기 누적
		}
	}
}

/* 노드 방문 처리 - 실행 속도 2등 */
/*
import java.util.*;
import java.io.*;

public class Main {
	private static int N, R, Q;
	private static List<Integer>[] nodeList;
	private static int[] subSize;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		nodeList = new ArrayList[N+1];
		subSize = new int[N+1];
		for(int i=0; i<N+1; i++) nodeList[i] = new ArrayList<>();
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			nodeList[u].add(v);
			nodeList[v].add(u);
		}
		
		bfs();
		
		StringBuilder sb = new StringBuilder();
		for(int q=0; q<Q; q++) {
			int u = Integer.parseInt(br.readLine());
			sb.append(subSize[u]).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void bfs() {
		Deque<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {R, 0});
		boolean[] visited = new boolean[N+1];
		
		while(!q.isEmpty()) {
			int[] info = q.pollLast();
			int node = info[0];
			int visit = info[1];
			if(visit==0) {
				q.offer(new int[] {node, 1});
				for(int n : nodeList[node]) {
					if(!visited[n]) {
						visited[node] = true;
						q.offer(new int[] {n,0});
					}
				}
			} else {
				int size = 0;
				for(int n : nodeList[node]) {
					size += subSize[n];
				}
				subSize[node] = size + 1;
			}
		}
	}
}
*/


/* 부모 노드 처리 - 실행 속도 3등 */
/*
import java.util.*;
import java.io.*;

public class Main {
	private static int N, R, Q;
	private static List<Integer>[] nodeList;
	private static int[] subSize;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		nodeList = new ArrayList[N+1];
		subSize = new int[N+1];
		for(int i=0; i<N+1; i++) nodeList[i] = new ArrayList<>();
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			nodeList[u].add(v);
			nodeList[v].add(u);
		}
		
		bfs();
		
		StringBuilder sb = new StringBuilder();
		for(int q=0; q<Q; q++) {
			int u = Integer.parseInt(br.readLine());
			sb.append(subSize[u]).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void bfs() {
		Deque<int[]> st = new ArrayDeque<>();
		st.push(new int[] {R, 0}); // 0이면 자식 방문 안한 상태 -> 1이면 자식 확인한 상태
		
		int[] parent = new int[N+1];
		Arrays.fill(parent, -1);
		parent[R] = 0; // 루투 노드
		
		while(!st.isEmpty()) {
			int[] info = st.pop();
			int node = info[0];
			int visit = info[1];
			
			if(visit==0) {
				st.push(new int[] {node, 1});
				for(int n : nodeList[node]) {
					if(n==parent[node]) continue; // node의 부모가 n이라면 패스
					parent[n] = node;
					st.push(new int[] {n,0});
				}
			} else {
				int size = 0;
				for(int n : nodeList[node]) {
					if(n==parent[node]) continue;
					size += subSize[n];
				}
				subSize[node] = size + 1;
			}
		}
	}
}
*/