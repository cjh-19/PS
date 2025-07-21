import java.io.*;
import java.util.*;

public class Solution {

	static StringBuilder sb = new StringBuilder();
	static int T, N;
	static int[][] board;

	// 우 하 좌 상
	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { 1, 0, -1, 0 };

	// N -> N-1 > N-1 > N-2 > N-2 ... 1 두번 처리할 때까지
	static void makeBoard(int dir) {
		int n = N, cnt = 0;
		int num = 1;
		int xpos = 0, ypos = -1;
		
		while(n >= 0 && cnt <= 2) {
			if((n == N && cnt == 1) || (cnt == 2)) {
				n--; cnt = 0;
			}
			
			for(int i=0; i<n; i++) {
				int nx = xpos + dx[dir];
				int ny = ypos + dy[dir];
				board[nx][ny] = num;
				num++;
				xpos = nx;
				ypos = ny;
			}
			
			dir = (dir + 1) % 4;
			cnt++;
		}
	}
	
	static void output() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				sb.append(board[i][j]);
				if(j != N - 1) sb.append(" ");
			}
			sb.append("\n");
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		T = Integer.parseInt(st.nextToken());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());

			board = new int[N][N];
			makeBoard(0);
			
			sb.append("#").append(t).append("\n");
			output();
		}

		System.out.println(sb);
		br.close();
	}
}
