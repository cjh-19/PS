import java.util.*;
import java.io.*;

public class Main {
    private static int N, K;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        int[] stu = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) stu[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(stu);
        int answer = 0, count = 0, teamMin = 0;

        for(int i=0; i<N; i++) {
            if(count==0) teamMin = stu[i];
            count++;
            if(count == teamMin) {
                answer++;
                count=0;
            }
        }
        if(count != 0) answer++;
        System.out.print(answer);
    }
}