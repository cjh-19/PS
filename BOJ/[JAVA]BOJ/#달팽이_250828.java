import java.util.*;
import java.io.*;

public class Main {
	private static int N, Num;
	private static int[][] board;
	private static int[] dx = {-1,0,1,0};
	private static int[] dy = {0,1,0,-1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		Num = Integer.parseInt(br.readLine());
		
		board = new int[N][N];
		int x = N/2;
		int y = N/2;
		
		int dir = 0;
		int n = 1;
		board[x][y] = n++;
		int cnt = 0, len = 1;
		int[] pos = new int[2];
		if(Num==1)pos = new int[] {N/2+1, N/2+1};
		while(n<=N*N) {
			for(int i=0; i<len; i++) {
				if(n>N*N) break;
				x += dx[dir];
				y += dy[dir];
				if(n==Num) pos = new int[] {x+1, y+1};
				board[x][y] = n++;
				
			}
			cnt++;
			dir = (dir+1)%4;
			if(cnt == 2) {
				len++;
				cnt=0;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				sb.append(board[i][j] + " ");
			}
			sb.append("\n");
		}
		sb.append(pos[0] + " " + pos[1]);
		System.out.print(sb.toString());
	}
}