import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[][] board;
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	private static boolean[][] visited;
	private static List<int[]>[] disList;
	private static int distance;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		distance = Integer.MAX_VALUE;
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		for(int r=0; r<N; r++) {
			st = new StringTokenizer(br.readLine());
			for(int c=0; c<N; c++) {
				board[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 구역 나누기
		visited = new boolean[N][N];
		int landCnt = -1;
		for(int r=0 ;r<N; r++) {
			for(int c=0; c<N; c++) {
				if(!visited[r][c] && board[r][c] == 1) {
					bfs(r, c, landCnt);
					landCnt--;
				}
			}
		}
		
		// 거리 계산하기
		calculate(landCnt);
		
		System.out.print(distance);
	}
	
	private static void bfs(int r, int c, int landCnt) {
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {r, c});
		visited[r][c] = true;
		
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
		return x>=0 && x<N && y>=0 && y<N;
	}
	
	private static void calculate(int landCnt) {
		// 각 구역 테두리에서 다른 테두리로 맨해튼 거리 계산
		disList = new ArrayList[Math.abs(landCnt)-1];
		for(int i=0; i<Math.abs(landCnt)-1; i++) disList[i] = new ArrayList<>();
		for(int r=0; r<N; r++) {
			for(int c=0; c<N; c++) {
				if(board[r][c] < 0) {
					disList[Math.abs(board[r][c])-1].add(new int[] {r,c});
				}
			}
		}
		
		int size = disList.length;
		for(int i=0; i<size-1; i++) {
			// i번째 인덱스에서 다른 인덱스로의 연결
			for(int j=i+1; j<size; j++) {
				for(int[] ixy : disList[i]) {
					for(int[] jxy : disList[j]) {
						int d = Math.abs(ixy[0] - jxy[0]) + Math.abs(ixy[1] - jxy[1]) - 1;
						distance = Math.min(distance, d);
					}
				}
			}
		}
	}
}
