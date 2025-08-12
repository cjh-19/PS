import java.util.*;
import java.io.*;

public class Main {
    private static int N;
    private static int[][] board;
    private static List<Edge>[] nodeList;
    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};
    private static int[] dp;

    private static class Edge {
        int toNode;
        int weight;

        public Edge(int toNode, int weight) {
            this.toNode = toNode;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        StringBuilder sb = new StringBuilder();
        int tc = 0;
        while(true) {
            tc++;
            N = Integer.parseInt(br.readLine());
            if(N==0) break;

            board = new int[N][N];

            for(int i=0; i<N; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // 노드 연결
            nodeList = new ArrayList[N*N];
            for(int i=0; i<N*N; i++) nodeList[i] = new ArrayList<>();

            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    for(int d=0; d<4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(!valid(nx, ny)) continue;
                        nodeList[i*N + j].add(new Edge(nx*N + ny, board[nx][ny]));
                    }
                }
            }

            dp = new int[N*N];
            Arrays.fill(dp, Integer.MAX_VALUE);
            dijkstra(); // 0번 노드에서 24번 노드로
            sb.append("Problem ").append(tc).append(": ").append(dp[N*N-1]).append("\n");
        }

        System.out.print(sb);
    }

    private static void dijkstra() {
        dp[0] = board[0][0];
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.weight, o2.weight));
        pq.offer(new Edge(0, dp[0]));
        boolean[] visited = new boolean[N*N];

        while(!pq.isEmpty()) {
            Edge node = pq.poll();

            if(visited[node.toNode]) continue;
            visited[node.toNode] = true;

            for(Edge e : nodeList[node.toNode]) {
                if(dp[e.toNode] > dp[node.toNode] + e.weight) {
                    dp[e.toNode] = dp[node.toNode] + e.weight;
                    pq.offer(new Edge(e.toNode, dp[e.toNode]));
                }
            }
        }
    }

    private static boolean valid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}
