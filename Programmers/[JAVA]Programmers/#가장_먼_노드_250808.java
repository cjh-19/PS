import java.util.*;

class Solution {
    private static List<List<Integer>> nodeList;
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        nodeList = new ArrayList<>();
        for(int i=0; i<n; i++) {
            nodeList.add(new ArrayList<>());
        }
        
        for(int i=0; i<edge.length; i++) {
            int n1 = edge[i][0]-1;
            int n2 = edge[i][1]-1;
            
            nodeList.get(n1).add(n2);
            nodeList.get(n2).add(n1);
        }
        
        return bfs(n);
    }
    
    private static int bfs(int n) {
        int maxlen = 0;
        int nodeCnt = 0;
        
        Queue<int[]> q = new ArrayDeque<>();
        boolean[] visited = new boolean[n];
        
        q.offer(new int[] {0, 0}); // 0번 노드, 거리
        visited[0] = true;
        
        while(!q.isEmpty()) {
            int[] pos = q.poll();
            int node = pos[0];
            int distance = pos[1];
            
            // 경로 최적화
            if(maxlen < distance) {
                maxlen = Math.max(maxlen, distance);
                nodeCnt = 1;
            } else if (maxlen == distance) {
                nodeCnt++;
            }
            
            for(int n1 : nodeList.get(node)) {
                if(!visited[n1]) {
                    q.offer(new int[] {n1, distance+1});
                    visited[n1] = true;
                }
            }
        }
        
        return nodeCnt;
    }
}