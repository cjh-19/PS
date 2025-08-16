import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            if((M & ((1<<N)-1)) == ((1<<N)-1)) sb.append("#").append(t).append(" ON").append("\n");
            else sb.append("#").append(t).append(" OFF").append("\n");
        }
        System.out.print(sb);
    }
}