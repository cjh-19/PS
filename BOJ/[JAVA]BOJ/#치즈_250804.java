import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static int[][] board;
	
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int cheeseCnt = 0;
		int timeCnt = 0;
		while(true) {
			int cnt = bfs();
			if(cnt == 0) {
				break;
			}
			cheeseCnt = cnt;
			timeCnt++;
		}
		
		System.out.println(timeCnt);
		System.out.print(cheeseCnt);
	}
	
	// 공기를 순회하며 만나는 치즈 체크 => 구멍난 치즈는 배열에 담고 bfs 끝나면 지우기
	private static int bfs() {
		List<int[]> cheeseList = new ArrayList<>();
		
		Queue<int[]> q = new ArrayDeque<>();
		boolean[][] visited = new boolean[N][M];
		q.offer(new int[] {0, 0});
		visited[0][0] = true;
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int xpos = pos[0];
			int ypos = pos[1];
			
			for(int d=0; d<4; d++) {
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(!check(nx, ny) || visited[nx][ny]) continue;
				
				if(board[nx][ny] == 1) {
					cheeseList.add(new int[] {nx, ny});
				} else {
					q.offer(new int[] {nx, ny});
				}
				visited[nx][ny] = true;
			}
		}
		
		int cheesCnt = cheeseList.size();
		
		// 치즈 녹이기 => 0
		for(int[] ch : cheeseList) {
			board[ch[0]][ch[1]] = 0;
		}
		
		return cheesCnt;
	}
	
	private static boolean check(int x, int y) {
		return x >= 0 && x < N && y >= 0 && y < M;
	}
}
