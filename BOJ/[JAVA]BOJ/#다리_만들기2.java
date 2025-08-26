import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static int[][] board;
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	private static boolean[][] visited;
	private static List<int[]>[] disList;
	
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
	private static int[] parent;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		board = new int[N][M];
		for(int r=0; r<N; r++) {
			st = new StringTokenizer(br.readLine());
			for(int c=0; c<M; c++) {
				board[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 구역 나누기
		visited = new boolean[N][M];
		int landCnt = -1;
		for(int r=0 ;r<N; r++) {
			for(int c=0; c<M; c++) {
				if(!visited[r][c] && board[r][c] == 1) {
					bfs(r, c, landCnt);
					landCnt--;
				}
			}
		}
		
		int size = landCnt*-1-1;
		edgeList = new ArrayList<>();
		
		// 거리 계산하기
		calculate(landCnt);
		
		System.out.print(kruskal(size));
	}
	
	private static void bfs(int r, int c, int landCnt) {
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {r, c});
		visited[r][c] = true;
		board[r][c] = landCnt;
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int xpos = pos[0];
			int ypos = pos[1];
			
			for(int d=0; d<4; d++) {
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(!valid(nx, ny) || visited[nx][ny]) continue;
				if(board[nx][ny] == 0) {
					board[xpos][ypos] = landCnt;
				} else if(board[nx][ny] == 1) {
					q.offer(new int[] {nx, ny});
					visited[nx][ny] = true;
				}
			}
		}
	}
	
	private static boolean valid(int x, int y) {
		return x>=0 && x<N && y>=0 && y<M;
	}
	
	private static void calculate(int landCnt) {
		// 각 구역 테두리에서 다른 테두리로 맨해튼 거리 계산
		disList = new ArrayList[Math.abs(landCnt)-1];
		for(int i=0; i<Math.abs(landCnt)-1; i++) disList[i] = new ArrayList<>();
		for(int r=0; r<N; r++) {
			for(int c=0; c<M; c++) {
				if(board[r][c] < 0) {
					disList[Math.abs(board[r][c])-1].add(new int[] {r,c});
				}
			}
		}
		
		int distance;
		int size = disList.length;
		for(int i=0; i<size-1; i++) {
			// i번째 인덱스에서 다른 인덱스로의 연결
			for(int j=i+1; j<size; j++) {
				distance = Integer.MAX_VALUE;
				for(int[] ixy : disList[i]) {
					for(int[] jxy : disList[j]) {
						if(ixy[0] == jxy[0]) { // 같은 행
							int d = Math.abs(ixy[1] - jxy[1]) - 1;
							if(d>=2 && clearPath(ixy[0], ixy[1], jxy[1], 0)) distance = Math.min(distance, d);
						} else if(ixy[1] == jxy[1]) { // 같은 열
							int d = Math.abs(ixy[0] - jxy[0]) - 1;
							if(d>=2 && clearPath(ixy[1], ixy[0], jxy[0], 1)) distance = Math.min(distance, d);
						}
					}
				}
				// i-j간의 연결에 대해서 최소 거리로 가중치 생성
				if(distance != Integer.MAX_VALUE) {
					edgeList.add(new Edge(i, j, distance));
				}
			}
		}
	}
	
	private static boolean clearPath(int base, int s, int e, int rc) {
		if(s>e) {
			int tmp = s;
			s = e;
			e = tmp;
		}
		if(rc == 0) { // 행이 같은 경우
			for(int i=s+1; i<e; i++) {
				if(board[base][i] != 0) return false;
			}
		} else { // 열이 같은  경우
			for(int i=s+1; i<e; i++) {
				if(board[i][base] != 0) return false;
			}
		}
		
		return true;
	}
	
	// 크루스칼을 통해서 MST 구하기
	private static int kruskal(int landSize) {
		int sumWeight = 0;
		parent = new int[landSize];
		for(int i=0; i<landSize; i++) parent[i] = i;
		
		// edgeList 간선 길이로 오름차순 정렬
		Collections.sort(edgeList, (o1, o2) -> Integer.compare(o1.weight, o2.weight));
		
		// 각 노드가 서로 같은 부모가 아니라면 union
		for(Edge edge : edgeList) {
			int n1 = edge.node1;
			int n2 = edge.node2;
			int w = edge.weight;
			
			if(find(n1) != find(n2)) {
				union(n1, n2);
				sumWeight += w;
			}
			
		}
		
		int root = find(0);
		for(int i=1; i<landSize; i++) {
			if(root != find(i)) return -1;
		}
		
		return sumWeight;
	}
	
	private static int find(int n) {
		if(parent[n] == n) return parent[n];
		else return parent[n] = find(parent[n]);
	}
	
	private static void union(int n1, int n2) {
		n1 = find(n1);
		n2 = find(n2);
		
		if(n1 == n2) return;
		
		if(n1 > n2) {
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
		}
		
		parent[n2] = n1;
	}
}
