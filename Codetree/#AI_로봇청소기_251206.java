import java.util.*;
import java.io.*;

public class Main {
    private static int N, K, L;
    private static int[][] board;
    private static int[][] mcBoard;
    private static long dustTotal;
    private static List<int[]> mcList;
    // 위, 왼, 오, 아래
    private static int[] dx = {-1, 0, 0, 1};
    private static int[] dy = {0, -1, 1, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        dustTotal = 0;
        board = new int[N][N];
        mcBoard = new int[N][N];
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j]>0) dustTotal+=board[i][j];
            }
        }

        mcList = new ArrayList<>();
        for(int i=0; i<K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken())-1;
            int y = Integer.parseInt(st.nextToken())-1;
            mcList.add(new int[]{x, y});
            mcBoard[x][y] = -2; // 청소기
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<L; i++) {
            // 테스트 시행
            if(dustTotal!=0) test();

            sb.append(dustTotal).append("\n");
        }
        System.out.print(sb);
    }

    private static void test() {
        // 1. 청소기 이동
        for(int i=0; i<K; i++) {
            int[] mc = mcList.get(i);
            int[] newmc = bfs(mc);
            // mcList.get(i)[0]=newmc[0];
            // mcList.get(i)[1]=newmc[1];
            mcBoard[mc[0]][mc[1]]=0;
            mcBoard[newmc[0]][newmc[1]]=-2;
            mcList.get(i)[0]=newmc[0];
            mcList.get(i)[1]=newmc[1];
        }

        // 2. 청소
        cleanDust();

        // 3. 먼지 축적 (먼지가 있는 곳에 +5)
        addDust();
        
        // 4. 먼지 확산
        spreadDust();
    }

    private static void cleanDust() {
        int[] dirArr = {1, 0, 2, 3};

        for(int[] mc : mcList) {
            int dustSum=0;
            if(board[mc[0]][mc[1]]>0) dustSum=Math.min(board[mc[0]][mc[1]], 20);
            dustTotal-=dustSum;

            for(int d=0; d<4; d++) {
                int nx = mc[0] + dx[d];
                int ny = mc[1] + dy[d];

                if(!valid(nx, ny) || board[nx][ny]<0) continue;
                dustSum+=Math.min(board[nx][ny], 20);
            }

            int maxSum=-1;
            int maxDir=-1;
            for(int d=0; d<4; d++) {
                int nx = mc[0] + dx[dirArr[d]];
                int ny = mc[1] + dy[dirArr[d]];

                int tmp;
                if(valid(nx, ny) && board[nx][ny]>=0) tmp=board[nx][ny];
                else tmp=0;

                int diff = Math.min(tmp, 20);
                if(dustSum-diff > maxSum) {
                    maxSum=dustSum-diff;
                    maxDir=dirArr[d];
                }
            }

            board[mc[0]][mc[1]]-=Math.min(20, board[mc[0]][mc[1]]);
            for(int d=0; d<4; d++) {
                if(maxDir==d) continue;

                int nx = mc[0] + dx[d];
                int ny = mc[1] + dy[d];

                if(!valid(nx,ny) || board[nx][ny]<0) continue;

                if(board[nx][ny]>20) {
                    board[nx][ny] -= 20;
                    dustTotal-=20;
                }
                else {
                    dustTotal-=board[nx][ny];
                    board[nx][ny]=0;
                }
            }
        }
    }

    private static int[] bfs(int[] mcInfo) {
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];
        q.offer(new int[] {mcInfo[0], mcInfo[1], 0});
        visited[mcInfo[0]][mcInfo[1]] = true;

        int bestX=-1, bestY=-1;
        int minDist = Integer.MAX_VALUE;

        while(!q.isEmpty()) {
            int[] info = q.poll();
            int xpos = info[0];
            int ypos = info[1];
            int dist = info[2];
            
            if(dist>minDist) continue;

            if(board[xpos][ypos]>0) {
                if(dist<minDist) {
                    minDist=dist;
                    bestX=xpos;
                    bestY=ypos;
                }
                else if(dist==minDist) {
                    if(xpos < bestX || (xpos==bestX && ypos<bestY)) {
                        bestX=xpos;
                        bestY=ypos;
                    }
                }
            }

            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];

                if(!valid(nx, ny) || visited[nx][ny] || board[nx][ny]<0 || mcBoard[nx][ny]<0) continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny, dist+1});
            }
        }
        if(bestX==-1) return mcInfo;
        return new int[] {bestX, bestY};
    }

    private static boolean valid(int x, int y) {
        return x>=0 && x<N && y>=0 && y<N;
    }

    private static void addDust() {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]>0) {
                    board[i][j]+=5;
                    dustTotal+=5;
                }
            }
        }
    }

    private static void spreadDust() {
        int[][] tmp = new int[N][N];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                tmp[i][j] = board[i][j];
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]==0) {
                    int sum=0;
                    for(int d=0; d<4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(!valid(nx, ny) || board[nx][ny]<=0) continue;

                        sum+=board[nx][ny];
                    }
                    tmp[i][j] = sum/10;
                    dustTotal+=tmp[i][j];
                }
            }
        }

        board = tmp;
    }
}