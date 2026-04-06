import java.util.*;
import java.io.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long sT = 1;
        long eT = 1_000_000_000L * times[times.length-1];

        while(sT<eT) {
            long mid = (sT + eT) /2;
            if(check(n, times, mid)) {
                eT = mid;
            }
            else sT = mid+1;
        }
        return sT;
    }

    public boolean check(int n, int[] times, long T) {
        long cnt = 0;
        for(int i=0; i<times.length; i++) {
            cnt += T / times[i];
            if(cnt>=n) return true;
        }
        return false;
    }
}