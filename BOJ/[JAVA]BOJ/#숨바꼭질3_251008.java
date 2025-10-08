import java.util.*;
import java.io.*;

public class Main {
    private static int N, K;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        dijkstra();
    }

    private static void dijkstra() {
        final int maxV = 100_001;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        int[] dist = new int[maxV];
        Arrays.fill(dist, maxV);
        pq.offer(new int[]{N, 0});
        dist[N] = 0;
        boolean[] visited = new boolean[maxV];
        while(!pq.isEmpty()) {
            int[] info = pq.poll();
            int pos = info[0];
            int time = info[1];

            if(pos==K) break;
            if(visited[pos]) continue;
            visited[pos] = true;

            if(pos-1 >= 0 && time+1 < dist[pos-1]) {
                pq.offer(new int[] {pos-1, time+1});
                dist[pos-1] = time+1;
            }
            if(pos+1 < maxV && time+1 < dist[pos+1]) {
                pq.offer(new int[] {pos+1, time+1});
                dist[pos+1] = time+1;
            }
            if(pos*2 < maxV && time < dist[pos*2]) {
                pq.offer(new int[] {pos*2, time});
                dist[pos*2] = time;
            }
        }

        System.out.print(dist[K]);
    }
}
