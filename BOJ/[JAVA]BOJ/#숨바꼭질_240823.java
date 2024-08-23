import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static int[] visited = new int[100001]; // 이동했을때 시간을 저장

    public static void main(String[] args) throws IOException {
        /* 문제 설명
        1. 수빈이는 점 N에 위치, 동생은 점 K에 위치
        2. 수빈이는 걷거나 순간이동 가능
        3. 수빈이 위치가 X일때 걸으면, 1초 후 X-1 or X+1로 이동
        4. 순간이동하면, 1초 후 2*X

        => 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾는 가장 빠른 시간 구하기

        둘의 위치는 0부터 100,000까지 위치할 수 있음.
        */

        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 수빈이 위치
        K = Integer.parseInt(st.nextToken()); // 동생 위치

        int result = bfs(N);
        System.out.println(result);
        br.close();
    }

    static int bfs(int n){
        // 큐 생성
        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(n); // 수빈의 첫 위치 넣기
        visited[n] = 1; // 첫 위치는 1 저장
        // 큐가 빌 때까지 반복
        while(!queue.isEmpty()){
            n = queue.remove(); // 가장 앞에 있는 위치 제거

            if(n == K) { // 동생을 찾았다면
                break; // 반복문 종료
            }
            // 범위를 안 벗어나며 방문하지 않은 곳이라면,
            if(n-1 >= 0 && visited[n-1] == 0){
                queue.add(n-1);
                visited[n-1] = visited[n] + 1; // 1초 추가
            }
            // 범위를 안 벗어나며 방문하지 않은 경우
            if(n+1 <= 100000 && visited[n+1] == 0){
                queue.add(n+1);
                visited[n+1] = visited[n] + 1;
            }
            // 순간이동
            if(n*2 <= 100000 && visited[n*2] == 0){
                queue.add(n*2);
                visited[n*2] = visited[n] + 1;
            }
        }

        return visited[n] - 1; // 탐색을 못하는 경우
    }
}