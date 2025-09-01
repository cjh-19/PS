import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static List<int[]> edge;
	private static int[] parent;
	private static int[] rank;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		edge = new ArrayList<>();
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			edge.add(new int[] {n1, n2});
		}
		
		parent = new int[N];
		rank = new int[N];
		for(int i=0; i<N; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
		
		// 0번 엣지부터 M-1번 엣지까지 연결하며 사이클 생기는 순간 종료
		int edgeCnt = 0;
		for(int[] e : edge) {
			edgeCnt++;
			int n1 = e[0];
			int n2 = e[1];
			
			if(find(n1) != find(n2)) {
				union(n1, n2);
			} else {
				System.out.println(edgeCnt);
				return;
			}
		}
		
		System.out.println(0);
	}
	
	private static int find(int x) {
		if(parent[x] == x) return parent[x];
		return parent[x] = find(parent[x]);
	}
	
	private static void union(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		
		if(n1==n2) return;
		
		if(rank[n1] < rank[n2]) {
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
		}
		
		parent[n2] = n1;
		rank[n1] += rank[n2];
	}
}
