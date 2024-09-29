import java.util.*;
import java.io.*;

public class Main {
    static private int N;
    static private int info[][];
    static private int award[];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        info = new int[N][2];
        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            info[i][0] = Integer.parseInt(st.nextToken());
            info[i][1] = Integer.parseInt(st.nextToken());
        }

        countAward();

        for (int i=0; i<N; i++) {
            System.out.print(award[i] + " ");
        }
        System.out.println();

        br.close();
    }

    static private void countAward() {
        award = new int[N];
        for (int i=0; i<N; i++) {
            int weight = info[i][0];
            int height = info[i][1];
            int count = 1;

            for (int j=0; j<N; j++) {
                if(i == j) continue;

                if(weight < info[j][0] && height < info[j][1]) count++;
            }

            award[i] = count;
        }
    }
}