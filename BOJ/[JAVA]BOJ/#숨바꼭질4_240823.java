import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static int[] visited = new int[100001]; // 이동했을때 시간
    static int[] path = new int[100001]; // 이전 경로 저장

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 수빈이 위치
        K = Integer.parseInt(st.nextToken()); // 동생 위치

        bfs(N);
        br.close();
    }

    static void bfs(int n){
        // 큐 생성
        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(n); // 수빈의 첫 위치 넣기
        visited[n] = 1; // 첫 위치는 1 저장

        // 큐가 빌 때까지 반복
        while(!queue.isEmpty()){
            n = queue.remove(); // 가장 앞에 있는 위치 제거

            if(n == K) { // 동생을 찾았다면
                System.out.println(visited[n] - 1);
                printPath(n); // n번 위치의 경로 출력
                return; // 반복문 종료
            }
            // 범위를 안 벗어나며 방문하지 않은 곳이라면,
            if(n-1 >= 0 && visited[n-1] == 0){
                queue.add(n-1);
                visited[n-1] = visited[n] + 1; // 1초 추가
                path[n-1] = n;
            }
            // 범위를 안 벗어나며 방문하지 않은 경우
            if(n+1 <= 100000 && visited[n+1] == 0){
                queue.add(n+1);
                visited[n+1] = visited[n] + 1;
                path[n+1] = n;
            }
            // 순간이동
            if(n*2 <= 100000 && visited[n*2] == 0){
                queue.add(n*2);
                visited[n*2] = visited[n] + 1;
                path[n*2] = n;
            }
        }
    }

    static void printPath(int n){
        Stack<Integer> stack = new Stack<>();
        // n이 시작 위치가 될때까지 반복
        while(n != N){
            stack.push(n);
            n = path[n];
        }
        stack.push(N);
        while(!stack.isEmpty()){
            System.out.print(stack.pop() + " ");
        }
        System.out.println();
    }
}