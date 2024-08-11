import java.util.*;
import java.io.*;

public class Main {
    static int n; // 식당 수
    static int[] people; // 각 식당의 고객 수
    static int leader; // 팀장이 검사 가능한 최대 고객수
    static int team; // 팀원이 검사 가능한 최대 고객수
    static long count = 0; // 최종 반환할 팀 수

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); // 식당수

        people = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            people[i] = Integer.parseInt(st.nextToken()); // 각 식당의 고객수
        }
        st = new StringTokenizer(br.readLine());
        leader = Integer.parseInt(st.nextToken()); // 팀장 고객
        team = Integer.parseInt(st.nextToken()); // 팀원 고객

        // 1. people에서 leader값을 빼기
        // 2. people의 최댓값을 감당할 수 있는 팀원 수 구하기 (max / team) 올림
        
        int tmp = n;
        for(int i=0; i<n; i++){
            people[i] -= leader;
            count++; // 팀장 수 추가

            // 고객이 남은 경우
            if(people[i] > 0){
                // 각 식당마다 필요 팀원 추가
                count += (long)Math.ceil((double)people[i] / team);
            }
        }

        System.out.println(count);
        br.close();
    }
}