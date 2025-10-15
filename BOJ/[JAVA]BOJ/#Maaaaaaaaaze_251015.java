import java.util.*;
import java.io.*;

public class Main {
	private static int[][][] board;
	private static int minDist;
	private static int[] dx = {-1, 1, 0, 0, 0, 0};
	private static int[] dy = {0, 0, -1, 1, 0, 0};
	private static int[] dz = {0, 0, 0, 0, -1, 1};
	
	private static int[][] spos = {{0,0,0}, {0,0,4}, {0,4,4}, {0,4,0}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		board = new int[5][5][5];
		for(int t=0; t<5; t++) {
			for(int i=0; i<5; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<5; j++) {
					board[t][i][j] = Integer.parseInt(st.nextToken());
				}
			}
		}
		
		minDist = Integer.MAX_VALUE;
		
		// 1. 판의 순서 순열 구하기
		int[] p = new int[5];
		boolean[] visited = new boolean[5];
		perm(0, p, visited);
		
		if(minDist==Integer.MAX_VALUE) System.out.print(-1);
		else System.out.print(minDist);
	}
	
	private static void perm(int cnt, int[] p, boolean[] visited) {
		// 판을 돌리며 시뮬레이션
		if(cnt==5) {
			if(minDist == 12) return;
			rotate(p);
			return;
		}
		
		for(int i=0; i<5; i++) {
			if(visited[i]) continue;
			visited[i] = true;
			p[cnt] = i;
			perm(cnt+1, p, visited);
			visited[i] = false;
		}
	}
	
	private static void rotate(int[] p) {
		int[][][] maze = new int[5][5][5];
		int idx = 0;
		for(int n : p) {
			for(int i=0; i<5; i++) {
				for(int j=0; j<5; j++) {
					maze[idx][i][j] = board[n][i][j];
				}
			}
			idx++;
		}

		// maze에는 순열로 조합된 판들이 순서대로 들어가있음
		// 이것을 각 보드들을 회전 시키면서 출발
		rotateDfs(0, maze);
	}
	
	private static void rotateDfs(int idx, int[][][] maze) {
		if(idx==5) {
			// 회전 완료하면 시뮬레이션
			if(minDist == 12) return;
			simulation(maze);
			return;
		}
		
		// 회전 x
		rotateDfs(idx+1, maze);
		// 회전 o -> 3번만 90도 회전
		int[][][] mazeTmp = new int[5][5][5];
		for(int i=0; i<5; i++) for(int j=0; j<5; j++) for(int k=0; k<5; k++) mazeTmp[i][j][k] = maze[i][j][k];
		
		for(int i=0; i<3; i++) {
			int[][] tmp = new int[5][5];
			for(int r=0; r<5; r++) {
				for(int c=0; c<5; c++) {
					tmp[c][5-r-1] = mazeTmp[idx][r][c];
				}
			}
			for(int r=0; r<5; r++) {
				for(int c=0; c<5; c++) {
					mazeTmp[idx][r][c] = tmp[r][c];
				}
			}
			rotateDfs(idx+1, mazeTmp);
		}
	}
	
	private static void simulation(int[][][] maze) {
		// 출발 꼭짓점과 끝 꼭짓점이 출발 및 도착이 가능한지 판단 -> 4가지의 경우만 가능
		for(int i=0; i<4; i++) {
			int[] s = spos[i];
			int[] e = new int[3];
			e[0] = 4-s[0]; e[1] = 4-s[1]; e[2] = 4-s[2];
			if(maze[s[0]][s[1]][s[2]] == 0 || maze[e[0]][e[1]][e[2]] == 0) continue;
			
			boolean[][][] visited = new boolean[5][5][5];
			Queue<int[]> q = new ArrayDeque<>();
			q.offer(new int[] {s[0], s[1], s[2], 0});
			visited[s[0]][s[1]][s[2]] = true;
			
			while(!q.isEmpty()) {
				int[] info = q.poll();
				int x = info[0];
				int y = info[1];
				int z = info[2];
				int dist = info[3];
				
				if(dist > minDist) continue;
				
				if(x==e[0] && y==e[1] && z==e[2]) {
					minDist = Math.min(minDist, dist);
					break;
				}
				
				for(int d=0; d<6; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					int nz = z + dz[d];
					
					if(!valid(nx, ny, nz)) continue;
					if(visited[nx][ny][nz] || maze[nx][ny][nz]==0) continue;
					
					visited[nx][ny][nz] = true;
					q.offer(new int[] {nx, ny, nz, dist+1});
				}
			}
		}
	}
	
	private static boolean valid(int x, int y, int z) {
		return x>=0 && x<5 && y>=0 && y<5 && z>=0 && z<5;
	}
}
