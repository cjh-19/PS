import java.io.*;
import java.util.*;

public class Main {
    static int W, H;
    static char[][] building;
    static boolean[][] visited;

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    static StringBuilder sb = new StringBuilder();

    // .(빈공간) / #(벽) / @(시작 위치) / *(불)
    // while문을 마치고 return을 한다면 IMPOSSIBLE 출력
    static void bfs(Deque<int[]> personQ, Deque<int[]> fireQ) {
        int time = 0;

        while (!personQ.isEmpty()) {
            // 1. 불 번짐
            int fireSize = fireQ.size();

            for (int f = 0; f < fireSize; f++) {
                int[] pos = fireQ.poll();
                int xpos = pos[0];
                int ypos = pos[1];

                for (int i = 0; i < 4; i++) {
                    int nx = xpos + dx[i];
                    int ny = ypos + dy[i];

                    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                        continue;
                    if (building[nx][ny] == '.') {
                        building[nx][ny] = 'F';
                        fireQ.add(new int[] { nx, ny });
                    }
                }
            }

            // 2. 상근이 이동
            int personSize = personQ.size();

            // 불 번지고 q에 있는 모든 위치 이동
            for (int s = 0; s < personSize; s++) {
                int[] pos = personQ.poll();
                int xpos = pos[0];
                int ypos = pos[1];

                if (xpos == 0 || xpos == H - 1 || ypos == 0 || ypos == W - 1) {
                    sb.append(time + 1);
                    return;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = xpos + dx[i];
                    int ny = ypos + dy[i];

                    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                        continue;
                    if (visited[nx][ny] || building[nx][ny] == '#' || building[nx][ny] == 'F')
                        continue;

                    visited[nx][ny] = true;
                    personQ.add(new int[] { nx, ny });
                }
            }
            time++; // 시간 증가
        }

        sb.append("IMPOSSIBLE");
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        // 빌딩, 방문, 시작위치, 불 초기 큐 초기화
        building = new char[H][W];
        visited = new boolean[H][W];

        Deque<int[]> personQ = new ArrayDeque<>();
        Deque<int[]> fireQ = new ArrayDeque<>();

        // 입력
        for (int i = 0; i < H; i++) {
            String str = br.readLine();

            for (int j = 0; j < W; j++) {
                building[i][j] = str.charAt(j);
                if (building[i][j] == 'J') {
                    personQ.add(new int[] { i, j });
                    visited[i][j] = true;
                } else if (building[i][j] == 'F') {
                    fireQ.add(new int[] { i, j });
                }
            }
        }

        // 탈출 여부 판단(bfs)
        bfs(personQ, fireQ);

        System.out.print(sb);
        br.close();
    }
}