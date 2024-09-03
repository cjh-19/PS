import java.util.*;
import java.io.*;

public class Main {
    static String str1;
    static String str2;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        str1 = st.nextToken();
        st = new StringTokenizer(br.readLine());
        str2 = st.nextToken();

        // 0번 인덱스는 공집합으로 설정
        dp = new int[str1.length() + 1][str2.length() + 1];

        System.out.println(maxLen());
        br.close();
    }

    static int maxLen() {
        for(int i=1; i<=str1.length(); i++) {
            for(int j=1; j<=str2.length(); j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[str1.length()][str2.length()];
    }
}