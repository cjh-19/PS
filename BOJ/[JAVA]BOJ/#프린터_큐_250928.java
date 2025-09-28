import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            Queue<int[]> q = new ArrayDeque<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o2, o1));
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++) {
                int n = Integer.parseInt(st.nextToken());
                q.offer(new int[] {i, n});
                pq.offer(n);
            }

            int cnt = 0;
            while(true) {
                int[] info = q.poll();
                if(info[1] >= pq.peek()) {
                    pq.poll();
                    cnt++;
                    if(info[0] == M) {
                        break;
                    }
                } else {
                    q.offer(info);
                }
            }
            sb.append(cnt).append("\n");
        }
        System.out.print(sb);
    }
}
