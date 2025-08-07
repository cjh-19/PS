import java.util.*;
import java.io.*;

public class Main {
	private static int R, C, T;
	private static int[][] board;
	private static int airX;
	private static Queue<int[]> q = new ArrayDeque<>();
	
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		board = new int[R][C];
		for(int r=0; r<R; r++) {
			st = new StringTokenizer(br.readLine());
			for(int c=0; c<C; c++) {
				board[r][c] = Integer.parseInt(st.nextToken());
				// 아래 칸
				if(board[r][c] == -1) airX = r;
				else if(board[r][c] >= 5) q.offer(new int[] {r,c});
			}
		}
		
		while(T > 0) {
			T--;
			// 1. 미세먼지 확산
			micro();
			
			// 2. 공기청정기 가동
			airMove();
			
			// 3. 전파할 미세먼지 큐에 담기
			q.clear();
			for(int r=0; r<R; r++) {
				for(int c=0; c<C; c++) {
					if(board[r][c] >= 5) q.offer(new int[] {r,c});
				}
			}
		}
		
		// 미세먼지 양 출력
		printMicroSize();
	}
	
	private static void micro() {
		int[][] newBoard = new int[R][C];
		for(int i=0; i<R; i++) {
			newBoard[i] = Arrays.copyOf(board[i], C);
		}
		
		// 큐에 담겨 있던 미세먼지 전파
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int xpos = pos[0];
			int ypos = pos[1];
			
			int cnt = 0;
			for(int d=0; d<4; d++) {
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(!check(nx, ny)) continue;
				
				newBoard[nx][ny] += board[xpos][ypos] / 5;
				cnt++;
			}
			newBoard[xpos][ypos] -= (board[xpos][ypos] / 5) * cnt;
		}
		
		// 새로운 보드에 갱신한 미세먼지 기존 보드에 옮기기
		for(int r=0; r<R; r++) {
			board[r] = Arrays.copyOf(newBoard[r], C);
		}
	}

	private static void airMove() {
		// 위 공기 청정기
		for(int i=airX-2; i>=1; i--) {
			board[i][0] = board[i-1][0];
		}
		for(int i=0; i<C-1; i++) {
			board[0][i] = board[0][i+1];
		}
		for(int i=0; i<airX-1; i++) {
			board[i][C-1] = board[i+1][C-1];
		}
		for(int i=C-1; i>=2; i--) {
			board[airX-1][i] = board[airX-1][i-1];
		}
		board[airX-1][1] = 0;
		
		// 아래 공기 청정기
		for(int i=airX+1; i<R-1; i++) {
			board[i][0] = board[i+1][0];
		}
		for(int i=0; i<C-1; i++) {
			board[R-1][i] = board[R-1][i+1];
		}
		for(int i=R-1; i>airX-1; i--) {
			board[i][C-1] = board[i-1][C-1];
		}
		for(int i=C-1; i>=2; i--) {
			board[airX][i] = board[airX][i-1];
		}
		board[airX][1] = 0;
	}
	
	private static void printMicroSize() {
		int sum = 0;
		
		for(int r=0; r<R; r++) {
			for(int c=0; c<C; c++) {
				if(board[r][c] > 0) sum += board[r][c];
			}
		}
		
		System.out.print(sum);
	}
	
	private static boolean check(int x, int y) {
		return x >= 0 && x < R && y >= 0 && y < C && board[x][y] != -1;
	}
}
