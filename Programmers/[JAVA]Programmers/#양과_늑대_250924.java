import java.util.*;
import java.io.*;

class Solution {
    private static List<Integer>[] edgeList;
    private static int N;
    private static int maxCnt;
    
    public int solution(int[] info, int[][] edges) {
        N = info.length;
        edgeList = new ArrayList[N];
        for(int i=0; i<N; i++) edgeList[i] = new ArrayList<>();
        
        for(int i=0; i<edges.length; i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            edgeList[n1].add(n2);
        }
        
        maxCnt = 1;
        Queue<Integer> q = new ArrayDeque<>();
        for(int n : edgeList[0]) {
            q.offer(n);
        }
        boolean[] visited = new boolean[N];
        visited[0] = true;
        dfs(q, 1, 0, visited, info);
        
        return maxCnt;
    }
    
    private static void dfs(Queue<Integer> q, int sCnt, int wCnt, boolean[] visited, int[] info) {
        while(!q.isEmpty()) {
            int idx = q.poll();
            if(info[idx] == 1 && sCnt <= wCnt+1) continue;
            
            visited[idx] = true;
            Queue<Integer> newQ = createQ(visited);
            int newS = sCnt;
            int newW = wCnt;
            if(info[idx]==0) newS++;
            else newW++;
            
            maxCnt = Math.max(maxCnt, newS);
            dfs(newQ, newS, newW, visited, info);
            visited[idx] = false;
        }
    }
    
    private static Queue<Integer> createQ(boolean[] visited) {
        Queue<Integer> q = new ArrayDeque<>();
        for(int i=0; i<N; i++) {
            if(visited[i]) {
                for(int n : edgeList[i]) {
                    if(!visited[n]) q.offer(n);
                }
            }
        }
        return q;
    }
}