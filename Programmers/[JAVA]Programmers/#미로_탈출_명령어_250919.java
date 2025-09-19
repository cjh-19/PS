import java.util.*;
import java.io.*;

class Solution {
    private static String answer;
    private static int[] dx = {1, 0, 0, -1};
    private static int[] dy = {0, -1, 1, 0};
    private static String[] dd = {"d", "l", "r", "u"};
    private static int N, M;
    private static class Node {
        int x;
        int y;
        int dist;
        StringBuilder sb;
        public Node(int x, int y, int dist, StringBuilder sb) {
            this.x=x;
            this.y=y;
            this.dist=dist;
            this.sb=sb;
        }
    }
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        this.N=n; this.M=m;
        
        answer = "impossible";
        int minDist = Math.abs(x-r) + Math.abs(y-c);
        if(minDist > k || (k-minDist)%2==1) return answer;
        bfs(x, y, r, c, k);
        
        return answer;
    }
    
    private static void bfs(int x, int y, int r, int c, int k) {
        Queue<Node> q = new ArrayDeque<>();
        boolean[][][] visited = new boolean[N+1][M+1][k+1];
        q.offer(new Node(x,y, 0, new StringBuilder()));
        visited[x][y][0] = true;
        
        while(!q.isEmpty()) {
            Node info = q.poll();
            int xpos = info.x;
            int ypos = info.y;
            int dist = info.dist;
            
            if(xpos == r && ypos == c && k==dist) {
                answer = info.sb.toString();
                return;
            }
            if(k<=dist) continue;
            
            for(int d=0; d<4; d++) {
                int nx = xpos + dx[d];
                int ny = ypos + dy[d];
                
                if(!valid(nx, ny) || visited[nx][ny][dist+1]) continue;
                
                StringBuilder nsb = new StringBuilder();
                nsb.append(info.sb.toString());
                nsb.append(dd[d]);
                
                q.offer(new Node(nx, ny, dist+1, nsb));
                visited[nx][ny][dist+1] = true;
            }
        }
    }
    
    private static boolean valid(int x, int y) {
        return x>=1 && x<=N && y>=1 && y<=M;
    }
}