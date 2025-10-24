import java.util.*;
import java.io.*;

public class Main {
    private static int N, M, H, minCnt;
    private static int[][] board;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        board = new int[H+1][N+1];
        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            board[r][c] = 1;
        }

        if (check()) {
            System.out.print(0);
            return;
        }

        minCnt=Integer.MAX_VALUE;
        dfs(1, 1, 0);
        if(minCnt==Integer.MAX_VALUE) minCnt=-1;
        System.out.print(minCnt>3 ? -1 : minCnt);
    }

    private static void dfs (int x, int y, int cnt) {
        if (cnt > 3 || cnt >= minCnt) return;

        if (x==H + 1) {
            if (check()) minCnt = Math.min(minCnt, cnt);
            return;
        }

        if (y>=N) {
            dfs(x + 1, 1, cnt);
            return;
        }

        if(board[x][y] == 0 && board[x][y-1]==0) {
            board[x][y]=1;
            dfs(x, y + 1, cnt + 1);
            board[x][y]=0;
        }

        dfs(x, y+1, cnt);
    }

    private static boolean check() {
        for(int i=1; i<=N; i++) {
            int col = i;
            for(int j=1; j<=H; j++) {
                if(board[j][col]==1) col++;
                else if(col>1&&board[j][col-1]==1) col--;
            }
            if(col!=i) return false;
        }

        return true;
    }
}