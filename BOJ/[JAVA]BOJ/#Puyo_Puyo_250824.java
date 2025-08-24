import java.util.*;
import java.io.*;

public class Main {
    private static char[][] board;
    private static boolean[][] visited;
    private static int[] dx = {-1 ,1 ,0, 0};
    private static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        board = new char[12][6];
        for(int i=0; i<12; i++) {
            board[i] = br.readLine().toCharArray();
        }

        // 1. 뿌요 메서드
        // 2. 중력 메서드
        int sumPuyo = 0;
        while(true) {
            // 뿌요 진행
            int puyoCnt = puyo();
            if(puyoCnt == 0) {
                break;
            }
            sumPuyo += puyoCnt;

            // 중력 진행
            gravity();
        }

        System.out.print(sumPuyo);
    }

    private static int puyo() {
        visited = new boolean[12][6];
        int puyoCnt = 0;
        for(int r=0; r<12; r++) {
            for(int c=0; c<6; c++) {
                // 방문하지 않은 뿌요 칸이라면 bfs 진행
                if(board[r][c] != '.' && !visited[r][c]) {
                    puyoCnt += bfs(r, c);
                }
            }
        }
        return puyoCnt >= 1 ? 1 : 0;
    }

    private static int bfs(int r, int c) {
        int cnt = 1; // 방문한 뿌요 개수(첫뿌요 추가)

        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {r, c});
        char basePuyo = board[r][c];
        visited[r][c] = true;
        boolean[][] puyoVisted = new boolean[12][6];
        puyoVisted[r][c] = true;

        while(!q.isEmpty()) {
            int[] pos = q.poll();
            int xpos = pos[0];
            int ypos = pos[1];

            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];

                if(!valid(nx, ny) || visited[nx][ny]) continue;
                if(board[nx][ny] != basePuyo) continue;

                visited[nx][ny] = true;
                puyoVisted[nx][ny] = true;
                q.offer(new int[]{nx, ny});
                cnt++;
            }
        }

        if(cnt>=4) {
            for(int i=0;i<12; i++) {
                for(int j=0; j<6; j++) {
                    if(puyoVisted[i][j]) board[i][j] = '.';
                }
            }
        }

        return cnt>=4 ? 1 : 0;
    }

    private static boolean valid(int x, int y) {
        return x>=0 && x<12 && y>=0 && y<6;
    }

    private static void gravity() {
        for(int c=0; c<6; c++) {
            Queue<Character> q = new ArrayDeque<>();
            for(int r=11; r>=0; r--) {
                if(board[r][c] != '.') q.offer(board[r][c]);
            }

            int idx=11;
            while(!q.isEmpty()) {
                board[idx--][c] = q.poll();
            }
            while(idx >= 0) {
                board[idx--][c] = '.';
            }
        }
    }
}
