import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static List<int[]> edgeList;
	private static int[] parent;
	private static int[] rank;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		edgeList = new ArrayList<>();
		parent = new int[N+1];
		rank = new int[N+1];
		for(int i=0; i<=N; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			edgeList.add(new int[] {n1, n2, w});
		}
		
		System.out.println(kruskal());
	}
	
	private static int kruskal() {
		int result = 0;
		
		Collections.sort(edgeList, (o1, o2) -> Integer.compare(o1[2], o2[2]));
		
		int maxPath = 0;
		for(int[] edge : edgeList) {
			int n1 = edge[0];
			int n2 = edge[1];
			int w = edge[2];
			
			if(find(n1) != find(n2)) {
				union(n1, n2);
				result += w;
				maxPath = Math.max(maxPath, w);
			}
		}
		
		return result - maxPath;
	}
	
	private static int find(int x) {
		if(parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}
	
	private static void union(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		
		if(n1 == n2) return;
		
		if(n2 > n1) {
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
		}
		
		parent[n2] = n1;
		rank[n1] += rank[n2];
	}
}
