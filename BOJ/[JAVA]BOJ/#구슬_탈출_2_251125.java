import java.util.*;
import java.io.*;

public class Main {
    private static int N, M, moveCnt;
    private static int[][] board;
    private static boolean[][][][] visited;
    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, -1, 0, 1};

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

                if(c=='O') info[0] = new int[] {i, j};
                else if(c=='R') info[1] = new int[] {i, j};
                else if(c=='B') info[2] = new int[] {i, j};
            }
        }

        moveCnt=11;
        visited = new boolean[N][M][N][M];
        dfs(0, info, -1);
        System.out.print(moveCnt==11?-1:moveCnt);
    }

    private static void dfs(int cnt, int[][] info, int preDir) {
        if(cnt<=10 && ballCheck(info)) {
            moveCnt = Math.min(moveCnt, cnt);
            return;
        }
        else if(cnt>10 || (info[0][0]==info[2][0] && info[0][1]==info[2][1])) return;

        for(int d=0; d<4; d++) {
            if(preDir!=-1 && d==(preDir+2)%4) continue;

            int[][] tmp = new int[3][2];
            for(int i=0; i<3; i++){
                tmp[i][0]=info[i][0]; tmp[i][1]=info[i][1];
            }

            int rx = tmp[1][0], ry = tmp[1][1];
            int bx = tmp[2][0], by = tmp[2][1];
            if(d==0) { // 상
                if(rx<bx) gravity(tmp, d, 1, 2);
                else gravity(tmp, d, 2, 1);
            } else if(d==2) { // 하
                if(rx>bx) gravity(tmp, d, 1, 2);
                else gravity(tmp, d, 2, 1);
            } else if(d==1) { // 좌
                if(ry<by) gravity(tmp, d, 1, 2);
                else gravity(tmp, d, 2, 1);
            } else { // 우
                if(ry>by) gravity(tmp, d, 1, 2);
                else gravity(tmp, d, 2, 1);
            }

            rx = tmp[1][0]; ry = tmp[1][1];
            bx = tmp[2][0]; by = tmp[2][1];

            if(visited[rx][ry][bx][by]) continue;

            visited[rx][ry][bx][by] = true;
            dfs(cnt+1, tmp, d);
            visited[rx][ry][bx][by] = false;
        }
    }

    private static void gravity(int[][] tmp, int dir, int i, int j) {
        gravityBall(tmp, dir, i);
        gravityBall(tmp, dir, j);
    }

    private static boolean ballCheck(int[][] info) {
        return (info[0][0]==info[1][0] && info[0][1]==info[1][1])
                && (info[0][0]!=info[2][0] || info[0][1]!=info[2][1]);
    }

    private static void gravityBall(int[][] tmp, int dir, int color) {
        int x = tmp[color][0];
        int y = tmp[color][1];
        int other = color==1?2:1;
        if(x==tmp[0][0]&&y==tmp[0][1]) return;

        boolean otherInHole = (tmp[other][0] == tmp[0][0] && tmp[other][1] == tmp[0][1]);


        while(true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(board[nx][ny]==-1) break;
            if(nx==tmp[0][0]&&ny==tmp[0][1]) {
                x=nx; y=ny;
                break;
            }
            if(!otherInHole && tmp[other][0]==nx && tmp[other][1]==ny) break;
            x=nx;y=ny;
        }
        tmp[color][0]=x;
        tmp[color][1]=y;
    }
}