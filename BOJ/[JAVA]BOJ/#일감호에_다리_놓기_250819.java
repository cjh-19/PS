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
    private static int[] size;

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
        size = new int[N+1];
        for(int i=0; i<=N; i++) {
            parent[i] = i;
            size[i] = 1;
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

        // 남아있는 연결 노드들은 union
        for(int i=1; i<=N; i++) {
            int n1 = i;
            int n2 = (i==N ? 1 : i+1);
            if(!removed[i]) union(n1, n2);
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
        if((n1 == 0) || (size[n2] < size[n1])) {
            size[n1] += size[n2];
            parent[n2] = n1;
        } else if((n2 == 0) || (size[n1] <= size[n2])) {
            size[n2] += size[n1];
            parent[n1] = n2;
        }
    }

    private static boolean kruskal() {
        long weightSum = 0;

        while(!nodepq.isEmpty()) {
            Edge edge = nodepq.poll();
            int n1 = edge.n1;
            int n2 = edge.n2;
            int w = edge.weight;

            // 항상 n1=0, n2=i
            int root0 = find(0);
            int root2 = find(n2);

            if(n1 == n2) continue;

            union(root0, root2);
            weightSum += w;
            if(weightSum > K) return false;

            if(check()) return true;
        }
        return check();
    }

    private static boolean check() {
        int root = find(0);
        return size[root] == N+1; // N+1개 노드가 연결 되었는지
    }
}
