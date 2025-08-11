import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static List<int[]>[] nodeList;
	private static boolean[] visited;
	private static int[] dp;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		nodeList = new ArrayList[N+1];
		for(int i=0; i<=N; i++) nodeList[i] = new ArrayList<>();
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			nodeList[n1].add(new int[] {n2, w});
		}
		
		st = new StringTokenizer(br.readLine());
		int startNode = Integer.parseInt(st.nextToken());
		int endNode = Integer.parseInt(st.nextToken());
		
		visited = new boolean[N+1];
		dp = new int[N+1]; // startNode에서 i인덱스까지 최단 거리를 저장하는 dp
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[startNode] = 0; // startNode - startNode는 거리 0
		
		dijkstra(startNode, endNode);
		
		System.out.println(dp[endNode]);
	}

	private static void dijkstra(int startNode, int endNode) {
		// 가중치 순으로 오름차순
		Queue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> Integer.compare(o1[1], o2[1]));
		
		pq.offer(new int[] {startNode, 0});
		
		while(!pq.isEmpty()) {
			int[] nodeInfo = pq.poll();
			int node = nodeInfo[0];
			
			if(visited[node]) continue;
			
			visited[node] = true;
			
			for(int[] n : nodeList[node]) {
				// 기존 값보다 새로 갱신하는게 더 최단이라면 갱신
				if(dp[n[0]] > dp[node] + n[1]) {
					dp[n[0]] = dp[node] + n[1];
					
					pq.offer(new int[] {n[0], dp[n[0]]});
				}
			}
		}
	}
}
