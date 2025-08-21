import java.util.*;
import java.io.*;

public class Main {
    private static int K, W, H;
    private static int[][] board;
    private static final int[] dx = {-1,1,0,0,-1,1,-1,1,-2,-2,2,2};
    private static final int[] dy = {0,0,-1,1,-2,-2,2,2,-1,1,-1,1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        K = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        board = new int[H][W];
        for(int i=0; i<H; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<W; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.print(bfs());
    }

    private static int bfs() {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0, K});
        boolean[][][] visited = new boolean[H][W][K+1];
        visited[0][0][K] = true;

        while(!q.isEmpty()) {
            int[] pos = q.poll();
            int xpos = pos[0];
            int ypos = pos[1];
            int cnt = pos[2];
            int kcnt = pos[3];

            if(xpos==H-1 && ypos==W-1) {
                return cnt;
            }

            // 4방향
            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];

                if(!check(nx, ny) || visited[nx][ny][kcnt] || board[nx][ny] == 1) continue;

                visited[nx][ny][kcnt] = true;
                q.offer(new int[] {nx, ny, cnt+1, kcnt});
            }

            // 말방향
            if(kcnt>0) {
                for(int d=4; d<12; d++) {
                    int nx = xpos + dx[d];
                    int ny = ypos + dy[d];

                    if(!check(nx, ny) || visited[nx][ny][kcnt-1] || board[nx][ny] == 1) continue;

                    visited[nx][ny][kcnt-1] = true;
                    q.offer(new int[] {nx, ny, cnt+1, kcnt-1});
                }
            }
        }

        return -1;
    }

    private static boolean check(int x, int y) {
        return x>=0 && x<H && y>=0 && y<W;
    }
}
