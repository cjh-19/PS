import java.util.*;
import java.io.*;

public class Main {
	private static int N, M, moveCnt;
	private static int[][] board;
	private static int[] dx = {-1, 0, 1, 0};
	private static int[] dy = {0, -1, 0, 1};
	private static String paths;
	private static boolean[][][][] visited;
	private static HashMap<Integer, String> dirHm;
	
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
		
		dirHm = new HashMap<>();
		dirHm.put(0, "U");
		dirHm.put(1, "L");
		dirHm.put(2, "D");
		dirHm.put(3, "R");
		
		moveCnt=11;
		visited = new boolean[N][M][N][M];
		dfs(0, -1, info, "");
		if(moveCnt==11) {
			System.out.print(-1);
			return;
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append(moveCnt).append("\n").append(paths);
		System.out.print(sb);
	}
	
	private static void dfs(int cnt, int preDir, int[][] info, String path) {
		if(cnt<=10 && ballCheck(info)) {
			if(moveCnt > cnt) {
				moveCnt=cnt;
				paths=path;
			}
			return;
		} else if(cnt>10 || (info[0][0]==info[2][0] && info[0][1]==info[2][1])) return;
		
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
			if(visited[rx][ry][bx][by]) continue;
			visited[rx][ry][bx][by] = true;
			dfs(cnt+1, d, tmp, path+dirHm.get(d));
			visited[rx][ry][bx][by] = false;
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
}