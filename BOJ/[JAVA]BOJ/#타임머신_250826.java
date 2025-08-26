import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	
	private static class Edge {
		int node1;
		int node2;
		int weight;
		public Edge(int node1, int node2, int weight) {
			this.node1=node1;
			this.node2=node2;
			this.weight=weight;
		}
	}
	
	private static List<Edge> edgeList;
	private static long[] distance;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		edgeList = new ArrayList<>();
		distance = new long[N];
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken())-1;
			int n2 = Integer.parseInt(st.nextToken())-1;
			int w = Integer.parseInt(st.nextToken());
			edgeList.add(new Edge(n1, n2, w));
		}
		
		if(!bellmanFord()) { // 음수 사이클이 있다면
			System.out.print(-1);
		} else {
			StringBuilder sb = new StringBuilder();
			for(int i=1; i<N; i++) {
				sb.append(distance[i]==Long.MAX_VALUE?-1:distance[i]).append("\n");
			}
			System.out.print(sb.toString());
		}
	}
	
	private static boolean bellmanFord() {
		boolean result = true;
		
		distance[0] = 0;
		for(int i=1; i<N; i++) distance[i] = Long.MAX_VALUE;
		
		// N-1 반복
		for(int i=0; i<N-1; i++) {
			for(Edge edge : edgeList) {
				if(distance[edge.node1] == Long.MAX_VALUE) continue;
				distance[edge.node2] = Math.min(distance[edge.node2], distance[edge.node1] + edge.weight);
			}
		}
		
		// 음수 사이클 판단
		for(Edge edge : edgeList) {
			if (distance[edge.node1] == Long.MAX_VALUE) continue;
		    if (distance[edge.node2] > distance[edge.node1] + edge.weight) return false;
		}
		
		return result;
	}
}