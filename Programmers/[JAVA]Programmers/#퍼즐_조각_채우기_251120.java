import java.util.*;
import java.io.*;

class Solution {
    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};
    private static class Block {
        int minX;
        int maxX;
        int minY;
        int maxY;
        boolean use;
        Block(int minX, int maxX, int minY, int maxY, boolean use) {
            this.minX=minX;
            this.maxX=maxX;
            this.minY=minY;
            this.maxY=maxY;
            this.use=use;
        }
    }
    private static List<Block>[] blockList;
    private static int N, M;
    private static boolean[][] visited;
    private static int cntSum;
    
    public int solution(int[][] game_board, int[][] table) {
        N = game_board.length;
        M = game_board[0].length;
        blockList = new ArrayList[N*M+1];
        for(int i=0; i<=N*M; i++) blockList[i] = new ArrayList<>();
        
        visited = new boolean[N][M];
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!visited[i][j] && table[i][j]==1) {
                    initBfs(i, j, table);
                }
            }
        }
        
        visited = new boolean[N][M];
        cntSum=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!visited[i][j] && game_board[i][j]==0) {
                    bfs(i, j, game_board, table);
                }
            }
        }
        
        return cntSum;
    }
    
    private static void initBfs(int r, int c, int[][] table) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {r, c});
        visited[r][c] = true;
        
        int cnt = 1;
        int minX = r, maxX = r;
        int minY = c, maxY = c;
        
        while(!q.isEmpty()) {
            int[] info = q.poll();
            int xpos = info[0];
            int ypos = info[1];
            
            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];
                
                if(!valid(nx, ny) || visited[nx][ny] || table[nx][ny] == 0) continue;
                
                minX=Math.min(minX, nx);
                maxX=Math.max(maxX, nx);
                minY=Math.min(minY, ny);
                maxY=Math.max(maxY, ny);
                cnt++;
                visited[nx][ny]=true;
                q.offer(new int[] {nx, ny});
            }
        }
        blockList[cnt].add(new Block(minX, maxX, minY, maxY, false));
    }
    
    private static boolean valid(int x, int y) {
        return x>=0 && x<N && y>=0 && y<M;
    } 
    
    private static void bfs(int r, int c, int[][] board, int[][] table) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {r, c});
        visited[r][c] = true;
        
        int cnt = 1;
        int minX = r, maxX = r;
        int minY = c, maxY = c;
        
        while(!q.isEmpty()) {
            int[] info = q.poll();
            int xpos = info[0];
            int ypos = info[1];
            
            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];
                
                if(!valid(nx, ny) || visited[nx][ny] || board[nx][ny] == 1) continue;
                
                minX=Math.min(minX, nx);
                maxX=Math.max(maxX, nx);
                minY=Math.min(minY, ny);
                maxY=Math.max(maxY, ny);
                cnt++;
                visited[nx][ny]=true;
                q.offer(new int[] {nx, ny});
            }
        }
        
        // 비교
        if(!blockList[cnt].isEmpty()) {
            for(int i=0; i<blockList[cnt].size(); i++) {
                Block block = blockList[cnt].get(i);
                if(block.use) continue;
                
                if(check(minX, maxX, minY, maxY, block, board, table)) {
                    blockList[cnt].get(i).use=true;
                    cntSum+=cnt;
                    break;
                }
            }
        }
    }
    
    private static boolean check(int minX, int maxX, int minY, int maxY, Block block, int[][] board, int[][] table) {
        boolean result = false;
        int h = block.maxX-block.minX+1;
        int w = block.maxY-block.minY+1;
        
        int[][] tmp1 = new int[h][w];
        int[][] tmp2 = new int[w][h];
        
        if(maxX-minX==h-1 && maxY-minY==w-1) {
            result=true;
            for(int r=block.minX; r<=block.maxX; r++) {
                for(int c=block.minY; c<=block.maxY; c++) {
                    if(table[r][c]==1) tmp1[r-block.minX][c-block.minY] = 0;
                    else tmp1[r-block.minX][c-block.minY] = 1;
                }
            }
            
            for(int r=minX; r<=maxX; r++) {
                for(int c=minY; c<=maxY; c++) {
                    if(board[r][c]!=tmp1[r-minX][c-minY]){
                        result = false;
                        break;
                    }
                }
                if(!result) break;
            }
            
            // 회전
            if(!result) {
                result=true;
                int[][] tmp = new int[h][w];
                for(int r=0; r<h; r++) {
                    for(int c=0; c<w; c++) {
                        tmp[r][c] = tmp1[h-r-1][w-c-1];
                    }
                }
                for(int r=minX; r<=maxX; r++) {
                    for(int c=minY; c<=maxY; c++) {
                        if(board[r][c]!=tmp[r-minX][c-minY]){
                            result = false;
                            break;
                        }
                    }
                    if(!result) break;
                }
            }
        }
        
        if(!result && maxX-minX==w-1 && maxY-minY==h-1) { // 회전 필요
            result=true;
            for(int r=block.minX; r<=block.maxX; r++) {
                for(int c=block.minY; c<=block.maxY; c++) {
                    if(table[r][c]==1) tmp2[c-block.minY][h-(r-block.minX)-1] = 0;
                    else tmp2[c-block.minY][h-(r-block.minX)-1] = 1;
                }
            }
            
            for(int r=minX; r<=maxX; r++) {
                for(int c=minY; c<=maxY; c++) {
                    if(board[r][c]!=tmp2[r-minX][c-minY]){
                        result = false;
                        break;
                    }
                }
                if(!result) break;
            }
            
            // 회전
            if(!result) {
                result=true;
                int[][] tmp = new int[w][h];
                for(int r=0; r<w; r++) {
                    for(int c=0; c<h; c++) {
                        tmp[r][c] = tmp2[w-r-1][h-c-1];
                    }
                }
                for(int r=minX; r<=maxX; r++) {
                    for(int c=minY; c<=maxY; c++) {
                        if(board[r][c]!=tmp[r-minX][c-minY]){
                            result = false;
                            break;
                        }
                    }
                    if(!result) break;
                }
            }
        }
        
        return result;
    }
}