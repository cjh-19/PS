import java.util.*;
import java.io.*;

public class Main {
    private static int N, M;
    private static Character[][] board;
    private static boolean[][] finished;
    private static boolean[][] visited;
    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};
    private static int safeCnt;
    private static HashMap<Character, Integer> hm;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new Character[N][M];
        finished = new boolean[N][M];
        visited = new boolean[N][M];
        safeCnt = 0;
        for(int i=0; i<N; i++) {
            String input = br.readLine();
            for(int j=0; j<M; j++) {
                board[i][j] = input.charAt(j);
            }
        }

        hm = new HashMap<>();
        hm.put('U', 0);
        hm.put('D', 1);
        hm.put('L', 2);
        hm.put('R', 3);
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!finished[i][j]) {
                    bfs(i, j);
                }
            }
        }

        System.out.print(safeCnt);
    }

    private static void bfs(int r, int c) {
        Queue<int[]> q = new ArrayDeque<>();
        Queue<int[]> visitQ = new ArrayDeque<>();
        q.offer(new int[]{r,c,0});
        visitQ.offer(new int[]{r,c,0});
        visited[r][c] = true;

        while(!q.isEmpty()) {
            int[] info = q.poll();
            int d = hm.get(board[info[0]][info[1]]);
            int cnt = info[2];
            int nx = info[0] + dx[d];
            int ny = info[1] + dy[d];

            if(finished[nx][ny]) {
                break;
            }
            else if(visited[nx][ny]) {
                safeCnt++;
                break;
            }
            q.offer(new int[] {nx, ny, cnt+1});
            visitQ.offer(new int[] {nx, ny, cnt+1});
            visited[nx][ny] = true;
        }
        while(!visitQ.isEmpty()) {
            int[] info = visitQ.poll();
            finished[info[0]][info[1]] = true;
        }
    }
}
