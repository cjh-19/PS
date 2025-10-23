import java.util.*;
import java.io.*;

public class Main {
	private static int N, Q, bSize, totalIce;
	private static int[][] board;
	private static boolean[][] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		bSize = 1 << N;
		
		board = new int[bSize][bSize];
		totalIce = 0;
		for(int i=0; i<bSize; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<bSize; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				totalIce += board[i][j];
			}
		}
		
		// 파이어스톰~!
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<Q; i++) {
			int L = Integer.parseInt(st.nextToken());
			fireStorm(L);
		}
		
		// 결과 계산
		int maxRound = 0;
		visited = new boolean[bSize][bSize];
		for(int i=0; i<bSize; i++) {
			for(int j=0; j<bSize; j++) {
				if(!visited[i][j] && board[i][j]>0) {
					maxRound = Math.max(maxRound, bfs(i,j));
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(totalIce).append("\n").append(maxRound);
		System.out.print(sb);
	}
	
	private static void fireStorm(int L) {
		// 2^L 크기의 칸들을 회전
		int size = 1 << L;
		for(int i=0; i<=bSize-size; i+=size) {
			for(int j=0; j<=bSize-size; j+=size) {
				rotate(i, j, i+size, j+size, size);
			}
		}
		// 해당 칸 인접 칸에 얼음이 있는 칸이 3개 있거나 1개 이하 얼음 칸이라면 1 감소
		int[][] tmp = new int[bSize][bSize];
		for(int i=0; i<bSize; i++) {
			for(int j=0; j<bSize; j++) {
				tmp[i][j] = board[i][j];
			}
		}
		for(int i=0; i<bSize; i++) {
			for(int j=0; j<bSize; j++) {
				if(board[i][j]>0 && around(i, j, tmp)) {
					board[i][j]--;
					totalIce--;
				}
			}
		}
	}
	
	private static void rotate(int xs, int ys, int xe, int ye, int size) {
		int[][] tmp = new int[size][size];
		for(int i=xs; i<xe; i++) {
			for(int j=ys; j<ye; j++) {
				tmp[j-ys][size-(i-xs)-1] = board[i][j];
			}
		}
		for(int i=xs; i<xe; i++) {
			for(int j=ys; j<ye; j++) {
				board[i][j] = tmp[i-xs][j-ys];
			}
		}
	}
	
	private static boolean around(int x, int y, int[][] tmp) {
		int cnt=0;
		
		if(valid(x-1, y) && tmp[x-1][y]>0) cnt++;
		if(valid(x+1, y) && tmp[x+1][y]>0) cnt++;
		if(valid(x, y-1) && tmp[x][y-1]>0) cnt++;
		if(valid(x, y+1) && tmp[x][y+1]>0) cnt++;
		
		if(cnt<=2) return true;
		return false;
	}
	
	private static boolean valid(int x, int y) {
		return x>=0 && x<bSize && y>=0 && y<bSize;
	}
	
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	
	private static int bfs(int r, int c) {
		int cnt = 1;
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {r,c});
		visited[r][c]=true;
		
		while(!q.isEmpty()) {
			int[] info = q.poll();
			int xpos = info[0];
			int ypos = info[1];
			
			for(int d=0; d<4; d++) {
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(!valid(nx, ny) || visited[nx][ny] || board[nx][ny]<=0) continue;
				q.offer(new int[] {nx, ny});
				visited[nx][ny] = true;
				cnt++;
			}
		}
		
		return cnt;
	}
}