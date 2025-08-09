import java.util.*;
import java.io.*;

class Solution {
    private static boolean[][] waterFill;
    private static final long MOD = 1_000_000_007;
    
    public int solution(int m, int n, int[][] puddles) {
        waterFill = new boolean[m][n];
        for(int i=0; i<puddles.length; i++) {
            waterFill[puddles[i][0]-1][puddles[i][1]-1] = true;
        }
        
        long[][] dp = new long[m][n];
        dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue;
                // 물웅덩이라면
                if(waterFill[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                
                // 왼쪽 벽에 붙어 있는 경우
                if(i==0) {
                    dp[i][j] += dp[i][j-1] % MOD;
                } else if(j==0) {
                    dp[i][j] += dp[i-1][j] % MOD;
                } else {
                    dp[i][j] += (dp[i][j-1] + dp[i-1][j]) % MOD;
                }
            }
        }
        
        return (int)dp[m-1][n-1];
    }
}