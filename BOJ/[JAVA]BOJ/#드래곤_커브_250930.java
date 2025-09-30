import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[] dx = {0, -1, 0, 1};
	private static int[] dy = {1, 0, -1, 0};
	private static boolean[][] board;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		board = new boolean[101][101];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int g = Integer.parseInt(st.nextToken());
			
			ArrayDeque<Integer> s = new ArrayDeque<>();
			s.push((d+2)%4);
			int nx = x + dx[d];
			int ny = y + dy[d];
			board[x][y] = true;
			board[nx][ny] = true;
			dragon(nx, ny, s, g, 0);
		}
		
		int cnt = 0;
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
			}
		}
		System.out.println(cnt);
	}
	
	private static void dragon(int x, int y, ArrayDeque<Integer> st, int g, int cnt) {
		// 세대 반복을 마친다면
		if(g == cnt) {
			return;
		}
		
		ArrayDeque<Integer> newSt = new ArrayDeque<>();
		ArrayDeque<Integer> tmp = new ArrayDeque<>(st);
		int nx = x, ny = y;
		while(!tmp.isEmpty()) {
			int d = tmp.pollFirst();
			newSt.offer(d);
		}
		while(!st.isEmpty()) {
			int d = st.pop();
			int nd = (d+3)%4; // 90도 회전
			newSt.push((nd+2)%4);
			
			nx = nx + dx[nd];
			ny = ny + dy[nd];
			board[nx][ny] = true;
		}
		dragon(nx, ny, newSt, g, cnt+1);
	}
}
