import java.util.*;
import java.io.*;

public class Main {
    static int N, M;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int[] prefixSum = new int[N+1];
        for(int i=0; i<N; i++) {
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }

        StringBuilder sb = new StringBuilder();
        int s, e;
        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            sb.append(prefixSum[e]-prefixSum[s-1]).append("\n");
        }
        System.out.print(sb);
    }

}