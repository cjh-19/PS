import java.util.*;
import java.io.*;

class Solution {

    public int solution(int n, int[][] results) {
        boolean[][] game = new boolean[n+1][n+1];
        for(int i=0; i<results.length; i++) {
            int win = results[i][0];
            int lose = results[i][1];
            game[win][lose] = true;
        }

        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(game[i][k] && game[k][j]) game[i][j]=true;
                }
            }
        }

        int answer = 0;
        for(int i=1; i<=n; i++) {
            int cnt=0;

            for(int j=1; j<=n; j++) {
                if(game[i][j] || game[j][i]) cnt++;
            }

            // n-1개의 결과를 알면 자신의 순위를 알게되는 것
            if(cnt==n-1) answer++;
        }

        return answer;
    }
}