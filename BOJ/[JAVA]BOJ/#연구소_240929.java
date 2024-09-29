import java.util.*;
import java.io.*;

public class Main {
    private static int N, M;
    private static int[][] area;
    private static int[] dx = {-1, 1, 0 ,0};
    private static int[] dy = {0, 0, -1, 1};
    private static int maxCnt = Integer.MIN_VALUE;

    static class Node {
        int x;
        int y;
        public Node (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        input(br);

        dfs(0); // 벽 세우기

        System.out.println(maxCnt);
        br.close();
    }

    /* 입력 처리 메서드 */
    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        area = new int[N][M];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<M; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    /* 벽 세우기 메서드 n: 세운 벽 개수 */
    private static void dfs(int n) {
        if (n == 3) {
            bfs(); // 바이러스 확산
            return;
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (area[i][j] == 0) {
                    area[i][j] = 1;
                    dfs(n+1);
                    area[i][j] = 0; // 백트래킹
                }
            }
        }
    }

    /* 바이러스 확산 메서드 */
    private static void bfs() {
        Queue<Node> Q = new LinkedList<Node>();

        // 바이러스 위치 삽입
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (area[i][j] == 2) {
                    Q.offer(new Node(i, j));
                }
            }
        }

        // 맵 카피
        int copyArea[][] = new int[N][M];
        for (int i=0; i<N; i++) {
            copyArea[i] = area[i].clone();
        }

        // bfs 탐색
        while(!Q.isEmpty()) {
            Node node = Q.poll();

            for (int i=0; i<4; i++) {
                int nx = node.x + dx[i];
                int ny = node.y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M && copyArea[nx][ny] == 0) {
                    copyArea[nx][ny] = 2;
                    Q.offer(new Node(nx, ny));
                }
            }
        }
        safeCount(copyArea);
    }

    /* 안전 구역 세기 메서드 */
    private static void safeCount(int[][] copyArea) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (copyArea[i][j] == 0) cnt++;
            }
        }
        maxCnt = Math.max(maxCnt, cnt);
    }
}