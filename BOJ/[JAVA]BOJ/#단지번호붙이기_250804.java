import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[][] board;
	
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		for(int i=0; i<N; i++) {
			String inputStr = br.readLine();
			char[] c = inputStr.toCharArray();
			for(int j=0; j<N; j++) {
				board[i][j] = c[j] - '0';
			}
		}
		
		List<Integer> group = new ArrayList<>();
		int cnt = 1; // 그룹 번호
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(board[i][j] == 1) {
					cnt++;
					group.add(bfs(i, j, cnt));
				}
			}
		}
		
		Collections.sort(group, (o1, o2) -> o1.compareTo(o2));
		
		StringBuilder sb = new StringBuilder();
		sb.append(group.size()).append("\n");
		for(int i=0; i<group.size(); i++) {
			sb.append(group.get(i)).append("\n");
		}
		
		System.out.print(sb);
	}
	
	private static int bfs(int x, int y, int groupNum) {
		int memberCnt = 0;
		
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {x,y});
		board[x][y] = groupNum;
		memberCnt++;
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int xpos = pos[0];
			int ypos = pos[1];
			
			for(int d=0; d<4; d++) {
				int nx = xpos + dx[d];
				int ny = ypos + dy[d];
				
				if(!check(nx, ny)) continue;
				
				if(board[nx][ny] == 1) {
					q.offer(new int[] {nx, ny});
					board[nx][ny] = groupNum;
					memberCnt++;
				}
			}
		}
		
		return memberCnt;
	}
	
	private static boolean check(int x, int y) {
		return x >= 0 && x < N && y >= 0 && y < N;
	}
}
