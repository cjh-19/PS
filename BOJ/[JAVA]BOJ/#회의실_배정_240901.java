import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[][] time;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        time = new int[N][2];

        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            time[i][0] = Integer.parseInt(st.nextToken());
            time[i][1] = Integer.parseInt(st.nextToken());
        }

        System.out.println(maxMeet(N));
        br.close();
    }

    static int maxMeet(int N) {
        int count = 0;

        // 다중 조건 정렬: 1번 인덱스 오름차순 -> 0번 인덱스 오름차순
        Arrays.sort(time, (o1, o2) -> {
            return o1[1] != o2[1] ? o1[1] - o2[1] : o1[0] - o2[0];
        });

        int start = 0;
        for(int[] num : time){
            if(num[0] >= start){
                start = num[1];
                count++;
            }
        }

        return count;
    }
}