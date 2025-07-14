import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String N = st.nextToken();

        int sum = 0;
        for(int i=0; i < N.length(); i++) {
            sum += N.charAt(i) - '0';
        }

        System.out.println(sum);

        br.close();
    }
}