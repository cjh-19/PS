import java.util.*;
import java.io.*;

public class Main {
	private static int N, M;
	private static long moveCnt;
	private static int[][] board;
	private static int[] dx = {-1, 0, 1, 0};
	private static int[] dy = {0, -1, 0, 1};
	private static long[][][][] dist;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		int[][] info = new int[3][2];
		for(int i=0; i<N; i++) {
			String str = br.readLine();
			for(int j=0; j<M; j++) {
				char c = str.charAt(j);
				if(c=='#') board[i][j]=-1;
				else board[i][j]=0;
				
				if(c=='O') info[0] = new int[] {i, j};
				else if(c=='R') info[1] = new int[] {i, j};
				else if(c=='B') info[2] = new int[] {i, j};
			}
		}
		
		if(bfs(info)) {
			System.out.print(-1);
			return;
		}
		
		moveCnt=Long.MAX_VALUE;
		dist = new long[N][M][N][M];
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				for(int k=0; k<N; k++) {
					Arrays.fill(dist[i][j][k], Long.MAX_VALUE);
				}
			}
		}
		dist[info[1][0]][info[1][1]][info[2][0]][info[2][1]]=0;
		dfs(0, -1, info);
		System.out.println(moveCnt==Long.MAX_VALUE?-1:moveCnt);
	}
	
	private static void dfs(long cnt, int preDir, int[][] info) {
		if(moveCnt>cnt && ballCheck(info)) {
			moveCnt=cnt;
			return;
		} else if(moveCnt<=cnt || info[0][0]==info[2][0] && info[0][1]==info[2][1]) return;
		
		for(int d=0; d<4; d++) {
			if(preDir!=-1 && d==(preDir+2)%4) continue;
			
			int rx=info[1][0], ry=info[1][1], bx=info[2][0], by=info[2][1];
			
			int[][] tmp = new int[3][2];
			for(int i=0; i<3; i++) {
				tmp[i][0]=info[i][0]; tmp[i][1]=info[i][1];
			}
			
			if(d==0) { // 상
				if(rx<bx) gravity(d, tmp, 1, 2);
				else gravity(d, tmp, 2, 1);
			} else if(d==2) { // 하
				if(rx<bx) gravity(d, tmp, 2, 1);
				else gravity(d, tmp, 1, 2);
			} else if(d==1) { // 좌
				if(ry<by) gravity(d, tmp, 1, 2);
				else gravity(d, tmp, 2, 1);
			} else {
				if(ry<by) gravity(d, tmp, 2, 1);
				else gravity(d, tmp, 1, 2);
			}
			
			rx=tmp[1][0]; ry=tmp[1][1]; bx=tmp[2][0]; by=tmp[2][1];
			if(dist[rx][ry][bx][by] <= cnt+1) continue;
			dist[rx][ry][bx][by] = cnt+1;
			dfs(cnt+1, d, tmp);
		}
	}
	
	private static boolean ballCheck(int[][] info) {
		return (info[0][0]==info[1][0] && info[0][1]==info[1][1])
				&& (info[0][0]!=info[2][0] || info[0][1]!=info[2][1]);
	}
	
	private static void gravity(int dir, int[][] info, int first, int second) {
		gravityBall(dir, info, first);
		gravityBall(dir, info, second);
	}
	
	private static void gravityBall(int dir, int[][] info, int color) {
		int x = info[color][0], y = info[color][1];
		int otherColor = color==1?2:1;
		
		while(true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(board[nx][ny]==-1) break;
			if(nx==info[0][0]&&ny==info[0][1]) {
				x=nx;y=ny;
				break;
			}
			if(nx==info[otherColor][0]&&ny==info[otherColor][1]) break;
			
			x=nx;y=ny;
		}
		info[color][0]=x; info[color][1]=y;
	}
	
	private static boolean bfs(int[][] info) {
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {info[1][0], info[1][1]});
		boolean[][] visit = new boolean[N][M];
		visit[info[1][0]][info[1][1]] = true;
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int x = pos[0], y = pos[1];
			
			if(x==info[0][0]&&y==info[0][1]) return false;
			
			for(int d=0; d<4; d++) {
				int nx = x+dx[d];
				int ny = y+dy[d];
				
				if(visit[nx][ny] || board[nx][ny]==-1) continue;
				visit[nx][ny]=true;
				q.offer(new int[] {nx, ny});
			}
		}
		
		return true;
	}
}