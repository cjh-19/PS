import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};
    public static int N, M;

    public static int[][] map;

    public static int mindis = Integer.MAX_VALUE; // 최단 거리

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N+1][M+1];

        for(int i=1; i<=N; i++) {
            String str = br.readLine();
            for(int j=1; j<=M; j++){
                map[i][j] = str.charAt(j-1) - '0';
            }
        }

        bfs();

        System.out.println(mindis);

        br.close();
    }

    public static class Tuple {
        int x, y, cnt;
        boolean breakcheck;
        Tuple(int x, int y, int cnt, boolean breakcheck) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.breakcheck = breakcheck;
        }
    }

    public static void bfs() {
        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(1,1,1, false));
        boolean[][][] visited = new boolean[N+1][M+1][2]; // 벽을 부수지 않은 경우0, 벽을 부순 경우1
        // 두가지로 나누는 이유: 벽을 부수고 x,y에 도달해서 방문체크를 한 경우
        // 벽을 부수지 않고 x,y에 도달하는 경우 이미 방문체크가 되어있기 때문에 갈 수가 없음
        visited[1][1][0] = true;

        while(!q.isEmpty()){
            Tuple tp = q.poll();
            int x = tp.x;
            int y = tp.y;
            int cnt = tp.cnt;
            boolean breakcheck = tp.breakcheck;

            if(x == N && y == M) { // 도달한 경우
                mindis = Math.min(mindis, cnt);
                return;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

                // 벽을 부순 경우
                if(breakcheck){
                    if(map[nx][ny] == 0 && !visited[nx][ny][1]){
                        q.add(new Tuple(nx, ny, cnt+1, breakcheck));
                        visited[nx][ny][1] = true;
                    }
                }
                else { // 벽을 부수지 않은 경우
                    if(map[nx][ny] == 0 && !visited[nx][ny][0]){
                        q.add(new Tuple(nx, ny, cnt+1, breakcheck));
                        visited[nx][ny][0] = true;
                    }
                    else if(map[nx][ny] == 1 && !visited[nx][ny][0]){
                        q.add(new Tuple(nx, ny, cnt+1, true));
                        visited[nx][ny][1] = true;
                    }
                }
            }
        }

        mindis = -1;
    }
}
