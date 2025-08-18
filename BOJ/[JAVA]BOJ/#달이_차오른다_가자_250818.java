import java.util.*;
import java.io.*;

public class Main {
    private static int N, M;
    private static char[][] board;
    private static final int[] dx = {-1,1,0,0};
    private static final int[] dy = {0,0,-1,1};
    private static int[] startPos;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];

        for(int i=0; i<N; i++) {
            String input = br.readLine();
            for(int j=0; j<M; j++) {
                board[i][j] = input.charAt(j);
                if(board[i][j] == '0') startPos = new int[] {i, j, 0};
            }
        }

        bfs();
    }

    private static void bfs() {
        int result = -1;
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {startPos[0], startPos[1], 0, 0});
        // 해당 키를 가지고 방문했는지 체크
        boolean[][][] visited = new boolean[N][M][64]; // fedcba -> 2^6 = 64
        visited[startPos[0]][startPos[1]][0] = true;

        while(!q.isEmpty()) {
            int[] pos = q.poll();
            int xpos = pos[0];
            int ypos = pos[1];
            int keys = pos[2];
            int dis = pos[3];

            if(board[xpos][ypos] == '1') {
                result = dis;
                break;
            }

            for(int d=0; d<4; d++) {
                int keyTmp = keys;
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];

                if(!valid(nx, ny) || board[nx][ny] == '#') continue;

                // 문을 만났는데 열쇠가 존재하지 않는다면 중지
                if((board[nx][ny] >= 'A' && board[nx][ny] <= 'F') && ((keyTmp & (1<<(board[nx][ny] - 'A'))) == 0)) continue;
                else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'f') {
                    // 열쇠를 만나면 fedcba 순으로 비트마스킹
                    keyTmp |= (1 << board[nx][ny] - 'a');
                }
                if(!visited[nx][ny][keyTmp]) {
                    q.offer(new int[] {nx, ny, keyTmp, dis+1});
                    visited[nx][ny][keyTmp] = true;
                }
            }
        }
        System.out.print(result);
    }

    private static boolean valid(int x, int y) {
        return x>=0 && x<N && y>=0 && y<M;
    }
}
