import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int s = 1;
        int e = distance;
        int[] rock = new int[rocks.length+2];
        rock[0]=0;
        rock[rocks.length+1]=distance;
        for(int i=0; i<rocks.length; i++) rock[i+1]=rocks[i];
        Arrays.sort(rock);
        while(s<e) {
            int mid = (s+e+1)/2;
            if(check(rock, mid, n)) s = mid;
            else e = mid-1;
        }
        return s;
    }

    public boolean check(int[] rock, int mid, int n) {
        int cnt = 0;
        int prev = 0;
        for(int i=1; i<rock.length; i++) {
            if(rock[i]-prev<mid) cnt++;
            else prev = rock[i];
        }
        return cnt<=n;
    }
}