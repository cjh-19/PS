import java.util.*;
import java.io.*;

public class Main {

    public static int N, M;
    public static int[][] map;
    public static int[][] zerocnt;
    public static int[][] result;
    public static Map<Integer, Integer> area = new HashMap<>(); // 영역 번호별 크기

    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N+1][M+1];
        zerocnt = new int[N+1][M+1];
        result = new int[N+1][M+1];
        for(int i=1; i<=N; i++) {
            String str = br.readLine();
            for(int j=1; j<=M; j++){
                int num = str.charAt(j-1) - '0';
                map[i][j] = num;
            }
        }

        // 각 연결된 0의 구역별 크기 계산
        int areaId = 1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(map[i][j] == 0 && zerocnt[i][j] == 0){
                    area.put(areaId, bfs(i,j,areaId));
                    areaId++;
                }
            }
        }

        // 각 1에 붙은 0구역 중 겹치지 않는 0구역의 크기 합산
        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(map[i][j] == 1){
                    sb.append(areasum(i,j));
                }
                else if(map[i][j] == 0){
                    sb.append("0");
                }
            }
            sb.append("\n");

        }

        System.out.println(sb);

        br.close();
    }

    // Tuple 클래스
    public static class Tuple {
        int x, y;

        Tuple(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    // bfs 최단 거리 탐색
    public static int bfs(int x, int y, int areaId) {
        Queue<Tuple> Q = new LinkedList<>();
        Q.add(new Tuple(x, y));
        zerocnt[x][y] = areaId;
        int cnt = 1;
        while(!Q.isEmpty()){
            Tuple tp = Q.poll();
            int posx = tp.x;
            int posy = tp.y;

            for(int i=0; i<4; i++){
                int nx = posx + dx[i];
                int ny = posy + dy[i];

                if(nx>0 && nx<=N && ny>0 && ny<=M && map[nx][ny] == 0 && zerocnt[nx][ny] == 0){
                    Q.add(new Tuple(nx, ny));
                    zerocnt[nx][ny] = areaId;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    public static int areasum(int x, int y){
        Set<Integer> uniqueArea = new HashSet<>();
        int sum = 1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>0 && nx<=N && ny>0 && ny<=M && map[nx][ny] == 0){
                uniqueArea.add(zerocnt[nx][ny]);
            }
        }

        // 각 구역의 합 계산
        for(int id : uniqueArea){
            sum += area.get(id);
        }

        return sum%10;
    }
}