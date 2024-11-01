import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[] P;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        P = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            P[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(P);
        int[] sum = new int[N];
        sum[0] = P[0];
        for(int i=1; i<N; i++){
            sum[i] = sum[i-1] + P[i];
        }
        int result = 0;
        for(int i=0; i<N; i++){
            result += sum[i];
        }
        System.out.println(result);

        br.close();
    }
}
