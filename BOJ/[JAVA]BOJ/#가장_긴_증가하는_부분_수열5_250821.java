import java.util.*;
import java.io.*;

public class Main {
    private static int N;
    private static long[] A;
    private static long[] memo;
    private static int[] memoIdx;
    private static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        N = Integer.parseInt(br.readLine());

        A = new long[N];
        memo = new long[N];
        memoIdx = new int[N];
        parent = new int[N];
        Arrays.fill(parent, -1); // 역추적할 부모 값
        
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        lis();
    }

    private static void lis() {
        // 첫번째 원소부터 시작
        memo[0] = A[0];
        memoIdx[0] = 0;

        int idx = 0;
        for(int i=1; i<N; i++) {
            if(memo[idx] < A[i]) {
                // 새로 추가할 i인덱스의 부모는 idx 인덱스
                parent[i] = memoIdx[idx];
                memo[++idx] = A[i];
                memoIdx[idx] = i;
            } else {
                // pos: A[i]를 껴넣을 위치
                int pos = lowerBound(A[i], idx+1);
                memo[pos] = A[i];
                memoIdx[pos] = i;
                // 새로 추가한 i번째 인덱스의 부모는 pos위치 앞의 인덱스
                // 맨앞이면 부모 -1
                parent[i] = (pos>0 ? memoIdx[pos-1] : -1);
            }
        }

        System.out.println(idx + 1); // 최장 길이

        // 역추적
        int curIdx = memoIdx[idx];
        long[] seq = new long[idx+1];
        for(int i=idx; i>=0; i--) {
            seq[i] = A[curIdx];
            curIdx = parent[curIdx];
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<idx+1; i++) sb.append(seq[i]).append(" ");
        System.out.print(sb);
    }

    private static int lowerBound(long num, int memoSize) {
        int startIdx = 0, endIdx = memoSize-1;

        while(startIdx < endIdx) {
            int midIdx = (startIdx + endIdx) / 2;

            if(memo[midIdx] < num ) { // num이 중간보다 크면 오른쪽으로 탐색 범위 좁히기
                startIdx = midIdx + 1;
            } else { // num이 중간보다 작거나 같다면 왼쪽으로 범위 좁히기
                endIdx = midIdx;
            }
        }
        return startIdx;
    }
}
