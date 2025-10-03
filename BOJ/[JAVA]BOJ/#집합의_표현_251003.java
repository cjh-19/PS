import java.util.*;
import java.io.*;

public class Main {
    private static int[] parent;
    private static int[] size;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        parent = new int[N+1];
        size = new int[N+1];
        for(int i=0; i<=N; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(cmd == 1) {
                if(find(a) == find(b)) sb.append("YES");
                else sb.append("NO");
                sb.append("\n");
            } else {
                if(find(a) != find(b)) union(a, b);
            }
        }
        System.out.print(sb);
    }

    private static int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private static void union(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);

        if(n1==n2) return;

        if(size[n1] < size[n2]) {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }

        parent[n2] = n1;
        size[n1] += n2;
    }
}
