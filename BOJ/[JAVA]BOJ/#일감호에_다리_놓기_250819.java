import java.util.*;
import java.io.*;

public class Main {
    private static int N, M;
    private static long K;
    private static class Edge {
        int n1;
        int n2;
        int weight;
        public Edge(int n1, int n2, int weight) {
            this.n1=n1;
            this.n2=n2;
            this.weight=weight;
        }
    }
    private static PriorityQueue<Edge> nodepq;
    private static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        nodepq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.weight, o2.weight));
        st = new StringTokenizer(br.readLine());
        // 와우도(0번 노드)와 강의동 간의 간선
        for(int i=1; i<=N; i++) {
            int n = Integer.parseInt(st.nextToken());
            nodepq.offer(new Edge(0, i, n));
        }

        parent = new int[N+1];
        for(int i=0; i<=N; i++) {
            parent[i] = i;
        }

        // removed[i] = true는 i번과 i+1 사이가 공사중이라는 의미
        boolean[] removed = new boolean[N+1];
        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            // 연결 노드 제거
            if((n1 == 1 && n2 == N) || (n1 == N && n2 == 1)) removed[N] = true;
            else removed[Math.min(n1, n2)] = true;
        }

        // 공사를 한 곳에서만 한다면
        if(M <= 1) {
            System.out.print("YES");
            return;
        }

        // 남아있는 연결 노드들은 가중치 0으로 추가
        for(int i=1; i<=N; i++) {
            if(!removed[i]) nodepq.offer(new Edge(i, (i==N ? 1 : i+1), 0));
        }

        // nodepq에 있는 간선들로 kruskal 진행
        if(kruskal()) System.out.print("YES");
        else System.out.print("NO");
    };

    private static int find(int x) {
        if(parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }

    private static void union(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);

        // 부모 같으면 종료
        if(n1 == n2) return;

        // 와우도와의 연결이라면
        if(parent[n1] < parent[n2]) parent[n2] = n1;
        else parent[n1] = n2;
    }

    private static boolean kruskal() {
        long weightSum = 0;

        while(!nodepq.isEmpty()) {
            Edge edge = nodepq.poll();
            int n1 = edge.n1;
            int n2 = edge.n2;
            int w = edge.weight;

            if(find(n1) == find(n2)) continue;

            union(n1, n2);
            weightSum += w;
            if(weightSum > K) return false;

        }

        return weightSum <= K;
    }

}
