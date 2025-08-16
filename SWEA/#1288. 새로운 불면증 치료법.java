import java.util.*;
import java.io.*;

public class Solution {
    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            N = Integer.parseInt(br.readLine());

            int check = 0;
            int k = 0;
            while(check != ((1<<10)-1)) {
                k++;
                int tmp = k * N;
                while(tmp > 0) {
                    check |= (1<<(tmp%10));
                    tmp/=10;
                }
            }
            sb.append("#").append(t).append(" ").append(N*k).append("\n");
        }
        System.out.print(sb);
    }
}