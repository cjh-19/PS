import java.util.*;
import java.io.*;

class Solution {
    private static List<List<Integer>> connectList;
    private static int[] light;
    private static int lightCnt = 0;
    
    public int solution(int n, int[][] lighthouse) {
        connectList = new ArrayList<>(n);
        light = new int[n];
        
        for(int i=0; i<n; i++) {
            connectList.add(new ArrayList<>());
        }
        
        // 등대 연결
        for(int i=0; i<lighthouse.length; i++) {
            int node1 = lighthouse[i][0] - 1;
            int node2 = lighthouse[i][1] - 1;
            
            connectList.get(node1).add(node2);
            connectList.get(node2).add(node1);
        }
        
        boolean[] visited = new boolean[n];
        dfs(0, 0, visited);
        
        for(int i : light) {
            if(i==1) lightCnt++;
        }
        
        return lightCnt;
    }
    
    private static boolean dfs(int prev, int cur, boolean[] visited) {
        // 리프노드라면 이전 노드 불켜기
        if(connectList.get(cur).size() == 1 && connectList.get(cur).get(0) == prev) {
            return true;
        }
        
        // 리프노드가 아니라면 dfs
        boolean tmp = false;
        for(int node : connectList.get(cur)) {
            if(!visited[node]) {
                visited[node] = true;
                if(dfs(cur, node, visited)) tmp = true;
                visited[node] = false;
            }
        }
        
        // 이전 노드가 리프 노드라면 불켜
        if(tmp) {
            light[cur] = 1;
            // 내가 불켰으니까 내 이전 노드는 불 켜지마
            return false;
        }
    
        // 내가 지금 안켰으니까 내 부모 넌 켜도 돼 -> false
        return true;
    }
}