import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int[] house = new int[N];
        for(int i=0; i<N; i++)  {
            house[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(house);

        int s=1, e=house[N-1];
        while(s<=e) {
            int mid = (s+e)/2;

            int cnt=1;
            int pos=0;
            for(int i=1; i<N; i++) {
                if(house[i]-house[pos]>=mid) {
                    pos=i;
                    cnt++;
                }
            }

            if(cnt<C) e=mid-1;
            else s=mid+1;
        }
        System.out.print(s-1);
    }
}