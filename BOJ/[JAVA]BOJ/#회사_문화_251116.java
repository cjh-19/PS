import java.util.*;
import java.io.*;

public class Main {
    private static List<Integer>[] edgeList;
    private static int N, M;
    private static long[] bonus;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edgeList = new ArrayList[N+1];
        for(int i=0; i<=N; i++) edgeList[i] = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; i++) {
            int from = Integer.parseInt(st.nextToken());
            if(from==-1) continue;
            edgeList[from].add(i);
        }

        bonus = new long[N+1];

        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            bonus[idx] += w;
        }

        propagate();

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=N; i++) {
            sb.append(bonus[i]).append(' ');
        }
        System.out.print(sb);
    }

    private static void propagate() {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(1);

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int next : edgeList[cur]) {
                bonus[next] += bonus[cur];
                q.offer(next);
            }
        }
    }
}