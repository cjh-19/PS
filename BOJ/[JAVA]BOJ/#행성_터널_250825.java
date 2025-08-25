import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static class Edge {
		int node;
		long weight;
		
		public Edge(int node, long weight) {
			this.node=node;
			this.weight=weight;
		}
	}
	private static class Node {
		int node;
		long x;
		long y;
		long z;
		public Node(int node, long x, long y, long z) {
			this.node=node;
			this.x=x;
			this.y=y;
			this.z=z;
		}
	}
	private static Node[] nodeInfo;
	private static List<Edge>[] edgeList;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		nodeInfo = new Node[N];
		edgeList = new ArrayList[N];
		for(int i=0; i<N; i++) {
			edgeList[i] = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			long x = Long.parseLong(st.nextToken());
			long y = Long.parseLong(st.nextToken());
			long z = Long.parseLong(st.nextToken());
			nodeInfo[i] = new Node(i, x, y, z);
		}
		
		// nodeList에 간선 정보 등록
		addEdge();
		
		// 프림을 통해 MST 생성
		System.out.print(prim());
	}
	
	private static void addEdge() {
		// x 기준 정렬 후 양 옆만 연결
		Arrays.sort(nodeInfo, (o1, o2) -> Long.compare(o1.x, o2.x));
		for(int i=0; i<N-1; i++) {
			long w = Math.abs(nodeInfo[i].x - nodeInfo[i+1].x);
			edgeList[nodeInfo[i].node].add(new Edge(nodeInfo[i+1].node, w));
			edgeList[nodeInfo[i+1].node].add(new Edge(nodeInfo[i].node, w));
		}
		
		// y 기준 정렬 후 양 옆만 연결
		Arrays.sort(nodeInfo, (o1, o2) -> Long.compare(o1.y, o2.y));
		for(int i=0; i<N-1; i++) {
			long w = Math.abs(nodeInfo[i].y - nodeInfo[i+1].y);
			edgeList[nodeInfo[i].node].add(new Edge(nodeInfo[i+1].node, w));
			edgeList[nodeInfo[i+1].node].add(new Edge(nodeInfo[i].node, w));
		}
		
		// z 기준 정렬 후 양 옆만 연결
		Arrays.sort(nodeInfo, (o1, o2) -> Long.compare(o1.z, o2.z));
		for(int i=0; i<N-1; i++) {
			long w = Math.abs(nodeInfo[i].z - nodeInfo[i+1].z);
			edgeList[nodeInfo[i].node].add(new Edge(nodeInfo[i+1].node, w));
			edgeList[nodeInfo[i+1].node].add(new Edge(nodeInfo[i].node, w));
		}
	}
	
	private static long prim() {
		PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1.weight, o2.weight));
		boolean[] visited = new boolean[N];
		visited[0] = true;
		for(Edge e : edgeList[0]) {
			pq.offer(e);
		}
		
		long sum = 0;
		
		while(!pq.isEmpty()) {
			Edge edge = pq.poll();
			int node = edge.node;
			long weight = edge.weight;
			
			if(visited[node]) continue;
			visited[node] = true;
			
			sum += weight;
			for(Edge e : edgeList[node]) {
				if(!visited[e.node]) pq.offer(e);
			}
		}
		
		return sum;
	}
}
