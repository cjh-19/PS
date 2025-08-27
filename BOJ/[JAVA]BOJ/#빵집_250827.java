import java.util.*;
import java.io.*;

public class Main {
	private static int R, C;
	private static char[][] board;
	private static boolean[][] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		board = new char[R][C];
		for(int r=0; r<R; r++) {
			st = new StringTokenizer(br.readLine());
			board[r] = st.nextToken().toCharArray();
		}
		
		// 그리디로 0행부터 R-1행까지 그리디로 위로만 채워서 탐색
		System.out.print(pipe());
	}
	
	private static int pipe() {
		int count = 0;
		
		visited = new boolean[R][C];
		for(int r=0; r<R; r++) {
			if(dfs(r, 0)) count++;
		}
		return count;
	}
	
	// 선택한 방향이 막혀있으면 백트래킹 탐색
	private static boolean dfs(int row, int col) {
		if(col == C-1) {
			return true;
		}
		
		for(int i=-1; i<=1; i++) {
			if(!valid(row+i, col+1) || visited[row+i][col+1] || board[row+i][col+1] == 'x') continue;
			visited[row+i][col+1] = true;
			if(dfs(row+i, col+1)) return true;
		}
		return false;
	}
	
	private static boolean valid(int x, int y) {
		return x>=0 && x<R && y>=0 && y<C;
	}
}