import java.util.*;
import java.io.*;

public class Main {
    private static int N, M;
    private static List<int[]>[] edgeList;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edgeList = new ArrayList[N+1];
        for(int i=0; i<=N; i++) edgeList[i] = new ArrayList<>();

        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            edgeList[n1].add(new int[] {n2, c});
            edgeList[n2].add(new int[] {n1, c});
        }
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        dijkstra(s, e);
    }

    private static void dijkstra(int s, int e) {
        int[] weight = new int[N+1];
        boolean[] visited = new boolean[N+1];
        Arrays.fill(weight, -1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o2[1], o1[1]));
        weight[s] = Integer.MAX_VALUE;
        pq.offer(new int[] {s, Integer.MAX_VALUE});

        while(!pq.isEmpty()) {
            int[] info = pq.poll();
            int n = info[0];
            int c = info[1];

            if(visited[n]) continue;
            visited[n] = true;

            if(n == e) break;

            for(int[] edge : edgeList[n]) {
                int nn = edge[0];
                int nc = edge[1];
                if(visited[nn]) continue;

                if(weight[nn] < Math.min(c, nc)) {
                    weight[nn] = Math.min(c, nc);
                    pq.offer(new int[] {nn, weight[nn]});
                }
            }
        }

        System.out.print(weight[e]);
    }
}
