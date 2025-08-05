import java.util.*;
import java.io.*;

public class Main {
    private static int N;
    private static long[] A;
    private static long[] memo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        N = Integer.parseInt(br.readLine());

        A = new long[N];
        memo = new long[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        lis();
    }

    private static void lis() {
        memo[0] = A[0];

        int idx = 0;
        for(int i=1; i<N; i++) {
            if(memo[idx] < A[i]) {
                memo[++idx] = A[i];
            } else {
                // binarySearch(A[i], idx+1);
                // Arrays 함수 사용
                int pos = Arrays.binarySearch(memo, 0, idx+1, A[i]);
                if (pos < 0) pos = -pos - 1;
                memo[pos] = A[i];
            }
        }

        System.out.println(idx + 1);
        for(int i=0; i<=idx; i++) {
            System.out.print(memo[i] + " ");
        }
    }

    private static void binarySearch(long num, int memoSize) {
        int startIdx = 0, endIdx = memoSize-1;

        while(startIdx < endIdx) {
            int midIdx = (startIdx + endIdx) / 2;

            if(memo[midIdx] < num ) { // num이 중간보다 크면 오른쪽으로 탐색 범위 좁히기
                startIdx = midIdx + 1;
            } else { // num이 중간보다 작거나 같다면 왼쪽으로 범위 좁히기
                endIdx = midIdx;
            }
        }
        memo[startIdx] = num;
    }
}
