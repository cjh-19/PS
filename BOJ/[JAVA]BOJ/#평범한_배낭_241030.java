import java.io.*;
import java.util.*;

public class Main {
    private static int W, N; // 배낭 무게, 귀금속 종류
    private static int[][] metal; // 금속 무게, 무게당 가격
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        input(br, st);
        System.out.println(knapsack());

        br.close();
    }

    // 입력 메소드
    private static void input(BufferedReader br, StringTokenizer st) throws IOException {
        W = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        metal = new int[N][2];
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            metal[i][0] = Integer.parseInt(st.nextToken());
            metal[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    // 배낭에 담기 메소드 - 그리디 방식 -> fractional knapsack
    private static int knapsack(){
        int result = 0;
        int weight = W;
        Arrays.sort(metal, (a, b) -> b[1] - a[1]); // 무게당 가격 내림차순
        for(int i=0; i<N; i++){
            if(weight == 0){
                break;
            }
            else if(metal[i][0] <= weight){
                result += metal[i][0] * metal[i][1];
                weight -= metal[i][0];
            }
            else if(metal[i][0] > weight) {
                result += weight * metal[i][1];
                weight = 0;
            }
        }
        return result;
    }
}
