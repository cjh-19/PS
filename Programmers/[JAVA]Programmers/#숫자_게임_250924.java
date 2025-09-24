/*** 투포인터 ***/
import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        int i=0, j=0, n=A.length, m=B.length;
        while(i<n&&j<m) {
            if(A[i] < B[j]) {
                i++;j++;answer++;
            } else j++;
        }
        
        /* for문 투포인터
        int j=0;
        for(int i=0; i<A.length; i++) {
            for(; j<B.length; j++) {
                if(A[i] < B[j]) {
                    answer++;
                    j++;
                    break;
                }
            }
        }
        */
        return answer;
    }
}


/*** 이분 탐색 ***/
/*
import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        int s=0;
        int e=B.length;
        for(int i=0; i<A.length; i++) {
            int idx = binarySearch(A[i], B, s, e);
            if(idx < e) {
                s = idx+1;
                answer++;
            }
        }
        return answer;
    }
    
    private static int binarySearch(int a, int[] B, int s, int e) {
        while(s<e) {
            int mid = (s+e)/2;
            if(a >= B[mid]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
}
*/