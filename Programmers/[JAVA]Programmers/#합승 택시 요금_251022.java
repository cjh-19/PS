import java.util.*;
import java.io.*;

class Solution {
    private static List<int[]>[] edgeList;
    private static int[][] dist, distA, distB;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        edgeList = new ArrayList[n+1];
        for(int i=0; i<=n; i++) edgeList[i] = new ArrayList<>();
        for(int i=0; i<fares.length; i++) {
            int n1 = fares[i][0];
            int n2 = fares[i][1];
            int w = fares[i][2];

            edgeList[n1].add(new int[] {n2, w});
            edgeList[n2].add(new int[] {n1, w});
        }
        dist = new int[3][n+1];
        
        // 1. 시작 지점에서 각 지점까지의 최단 경로 저장
        // 2. 시작 노드 -> 중간 노드 -> a, b각자의 위치까지의 최단 거리
        int minAns = Integer.MAX_VALUE;
        dijkstra(s, n, 0);
        dijkstra(a, n, 1);
        dijkstra(b, n, 2);
        for(int i=1; i<=n; i++) {
            minAns = Math.min(minAns, dist[0][i] + dist[1][i] + dist[2][i]);
        }

        return minAns;
    }
    
    private static void dijkstra(int s, int n, int method) {
        int[] d = new int[n+1];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[s] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        pq.offer(new int[]{s, 0});
        boolean[] visited = new boolean[n+1];
        
        while(!pq.isEmpty()) {
            int[] info = pq.poll();
            int node = info[0];
            int w = info[1];
            
            if(visited[node]) continue;
            visited[node] = true;
            
            for(int[] edge : edgeList[node]) {
                int nn = edge[0];
                int nw = edge[1];
                if(!visited[nn]) {
                    pq.offer(new int[] {edge[0], w+nw});
                    d[nn] = Math.min(w+nw, d[nn]);
                }
            }
        }
        
        dist[method]=d;
    }
}