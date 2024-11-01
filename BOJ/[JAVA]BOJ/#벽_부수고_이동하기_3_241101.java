import java.util.*;
import java.io.*;

public class Main {

    public static int N, M, K;
    public static int[][] map;

    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N+1][M+1];
        for(int i=1; i<=N; i++) {
            String str = br.readLine();
            for(int j=1; j<=M; j++){
                int num = str.charAt(j-1) - '0';
                map[i][j] = num;
            }
        }

        System.out.println(bfs());

        br.close();
    }

    // Tuple 클래스
    public static class Tuple {
        int x, y, cnt, breakcnt;
        boolean sun;

        Tuple(int x, int y, int cnt, int breakcnt, boolean sun){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.breakcnt = breakcnt;
            this.sun = sun;
        }
    }

    // bfs 최단 거리 탐색
    public static int bfs() {
        Queue<Tuple> Q = new LinkedList<>();
        Q.add(new Tuple(1, 1, 1, 0, true));
        boolean[][][] visited = new boolean[N+1][M+1][K+1]; // 벽을 K개 부술 수 있으므로 K+1개의 경우의 수로 체크
        visited[1][1][0] = true;
        
        while(!Q.isEmpty()){
            Tuple tp = Q.poll();
            int x = tp.x;
            int y = tp.y;
            int cnt = tp.cnt;
            int breakcnt = tp.breakcnt;
            boolean sun = tp.sun;

            if(x == N && y == M){
                return cnt;
            }

            boolean night = true;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

                if(map[nx][ny] == 0 && !visited[nx][ny][breakcnt]){
                    Q.add(new Tuple(nx, ny, cnt+1, breakcnt, !sun));
                    visited[nx][ny][breakcnt] = true;
                }
                else if(map[nx][ny] == 1 && breakcnt < K && !visited[nx][ny][breakcnt+1]){
                    if(sun) {
                        Q.add(new Tuple(nx, ny, cnt+1, breakcnt+1, false));
                        visited[nx][ny][breakcnt+1] = true;
                    }
                    else if(!sun && night) {
                        Q.add(new Tuple(x, y, cnt+1, breakcnt, true));
                        night = false;
                    }
                }
            }
        }
        
        return -1;
    }
}