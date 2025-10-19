import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        HashSet<Integer> hs = new HashSet<>();

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<A; i++) {
            hs.add(Integer.parseInt(st.nextToken()));
        }

        int cnt=hs.size();
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<B; i++) {
            if(hs.contains(Integer.parseInt(st.nextToken()))) {
                cnt--;
            } else cnt++;
        }
        System.out.print(cnt);
    }
}