import java.util.*;
import java.io.*;

public class Main {
	private static int N, L;
	private static int[][] board;
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		
		board = new int[N][N];
		for(int r=0; r<N; r++) {
			st = new StringTokenizer(br.readLine());
			for(int c=0; c<N; c++) {
				board[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		
		int count = 0;
		boolean[][] visited = new boolean[N][N];
		// 상-하 탐색
		for(int c=0; c<N; c++) {
			// 해당 열 이동
			visited = new boolean[N][N];
			if(dfs(N-1, c, 0, c, 1, visited)) count++;
		}
		
		// 좌-우 탐색
		for(int r=0; r<N; r++) {
			// 해당 행 이동
			visited = new boolean[N][N];
			if(dfs(r, N-1, r, 0, 3, visited)) count++;
		}
		
		System.out.print(count);
	}
	
	// 도착x위치, 도착y위치, 현재 x위치, 현재 y위치, 이동 방향
	private static boolean dfs(int endX, int endY, int curX, int curY, int dir, boolean[][] visited) {
		if(endX == curX && endY == curY) {
			return true;
		}
		
		// 진행
		int nx = curX + dx[dir];
		int ny = curY + dy[dir];
		
		// 다음 높이도 같다면 그대로 진행
		if(board[curX][curY] == board[nx][ny]) {
			return dfs(endX, endY, nx, ny, dir, visited);
		}
		// 내려가야한다면
		else if(board[curX][curY]-1 == board[nx][ny]) {
			// L길이만큼 연속되는지 진행하다가 범위 벗어나면 false
			int x = curX;
			int y = curY;
			for(int i=0; i<L; i++) {
				x += dx[dir];
				y += dy[dir];
				if(!valid(x, y) || visited[x][y]) return false;
				if(board[curX][curY]-1 != board[x][y]) return false;
				visited[x][y] = true;
			}
			return dfs(endX, endY, x, y, dir, visited);
		}
		// 올라가야 한다면
		else if(board[curX][curY] == board[nx][ny]-1) {
			// L길이만큼 이전 길이 연속되는지 확인
			int x = nx;
			int y = ny;
			for(int i=0; i<L; i++) {
				x -= dx[dir];
				y -= dy[dir];
				if(!valid(x, y) || visited[x][y]) return false;
				if(board[curX][curY] != board[x][y]) return false;
				visited[x][y] = true;
			}
			return dfs(endX, endY, nx, ny, dir, visited);
		} else return false;
	}
	
	private static boolean valid(int x, int y) {
		return x>=0 && x<N && y>=0 && y<N;
	}
}