import java.util.*;
import java.io.*;

public class Main {
    static int T;
    static long[] dp = new long[1000001];
    static int mod = 1000000009;

    public static void main(String[] args)  throws IOException{
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        // dp 설정
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i < 1000001; i++){
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
        }

        for(int i=0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            System.out.println(dp[N]);
        }

        br.close();
    }
}