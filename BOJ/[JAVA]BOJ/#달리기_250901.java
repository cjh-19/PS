import java.util.*;
import java.io.*;

public class Main {
	private static int N, M, K;
	private static char[][] board;
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};
	private static int[][] dist;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		board = new char[N][M];
		for(int r=0; r<N; r++) {
			board[r] = br.readLine().toCharArray();
		}
		
		int sx, sy, ex, ey;
		st = new StringTokenizer(br.readLine());
		sx = Integer.parseInt(st.nextToken())-1;
		sy = Integer.parseInt(st.nextToken())-1;
		ex = Integer.parseInt(st.nextToken())-1;
		ey = Integer.parseInt(st.nextToken())-1;
		
		bfs(sx, sy, ex, ey);
		
		System.out.print(dist[ex][ey]==Integer.MAX_VALUE?-1:dist[ex][ey]);
	}

	private static void bfs(int sx, int sy, int ex, int ey) {
		Queue<int[]> q = new ArrayDeque<>();
		dist = new int[N][M];
		for(int i=0; i<N; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
		q.offer(new int[] {sx, sy});
		dist[sx][sy] = 0;
		
		while(!q.isEmpty()) {
			int[] info = q.poll();
			int xpos = info[0];
			int ypos = info[1];
			
			if(xpos == ex && ypos == ey) {
				return;
			}
			
			for(int d=0; d<4; d++) {
				for(int step=1; step<=K; step++) {
					int nx = xpos + dx[d]*step;
					int ny = ypos + dy[d]*step;
					
					if(!valid(nx, ny) || board[nx][ny] == '#') break;
					
					if(dist[nx][ny] < dist[xpos][ypos] + 1) break;
					
					if(dist[nx][ny] > dist[xpos][ypos] + 1) {
						dist[nx][ny] = dist[xpos][ypos] + 1;
						q.offer(new int[] {nx, ny});
					}
				}
			}
		}
	}
	
	private static boolean valid(int x, int y) {
		return x>=0 && x<N && y>=0 && y<M;
	}
}
