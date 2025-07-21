import java.io.*;
import java.util.*;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static int L, R, C; // 층, 행, 열
	static char[][][] building;
	static boolean[][][] visited;

	static int[] dx = { -1, 1, 0, 0, 0, 0 };
	static int[] dy = { 0, 0, -1, 1, 0, 0 };
	static int[] dz = { 0, 0, 0, 0, -1, 1 };
	
	static void bfs(Queue<int[]> q) {
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int zpos = pos[0], xpos = pos[1], ypos = pos[2];
			int currTime = pos[3];
			
			if(building[zpos][xpos][ypos] == 'E') {
				sb.append("Escaped in ").append(currTime).append(" minute(s).\n");
				return;
			}
			
			for(int d=0; d<6; d++) {
				int nz = zpos + dz[d];
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if(visited[nz][nx][ny] || building[nz][nx][ny] == '#') continue;
				
				visited[nz][nx][ny] = true;
				q.add(new int[] {nz, nx, ny, currTime + 1});
			}
		}
		
		sb.append("Trapped!\n");
		return;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		while (true) {
			st = new StringTokenizer(br.readLine());
			L = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());

			if (L == 0 && R == 0 && C == 0)
				break;

			building = new char[L][R][C];
			Queue<int[]> q = new ArrayDeque<>();
			visited = new boolean[L][R][C];

			for (int l = 0; l < L; l++) {
				for (int r = 0; r < R; r++) {
					String str = br.readLine();
					for (int c = 0; c < C; c++) {
						building[l][r][c] = str.charAt(c);
						if (building[l][r][c] == 'S') {
							q.add(new int[] { l, r, c, 0 });
							visited[l][r][c] = true;
						}
					}
				}
				br.readLine(); // 개행 버리기
			}

			// 탈출 시간 측정
			bfs(q);
		}

		System.out.println(sb);
		br.close();
	}
}