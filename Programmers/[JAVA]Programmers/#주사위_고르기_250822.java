import java.util.*;
import java.io.*;

class Solution {
    private static int N, win, aWin;
    private static int[] answer, choiceDice, aDice, bDice;
    private static List<Integer> aCombi, bCombi;
    private static boolean[] visited = new boolean[11];
    
    public int[] solution(int[][] dice) {
        N = dice.length;
        choiceDice = new int[N];
        answer = new int[N/2];
        combination(0, 0, dice);
        
        return answer;
    }
    
    private static void combination(int cnt, int idx, int[][] dice) {
        // 절반 뽑았다면
        if(cnt == N/2) {
            aWin = 0;
            // 뽑은 주사위로 몇번 이기는지 세기
            exGame(dice);
            // 기존에 최고 승수 보다 높다면 업데이트
            if(aWin > win) {
                for(int i=0; i<N/2; i++) answer[i] = aDice[i];
                win = aWin;
            }
            return;
        }
        
        for(int i=idx; i<N; i++) {
            visited[i] = true;
            combination(cnt+1, i+1, dice);
            visited[i] = false;
        }
    }
    
    private static void exGame(int[][] dice) {
        // A, B가 각각 뽑은 주사위 인덱스
        aDice = new int[N/2];
        bDice = new int[N/2];
        
        int aSize = 0, bSize = 0;
        for(int i=0; i<N; i++) {
            if(visited[i]) aDice[aSize++] = i+1;
            else bDice[bSize++] = i+1;
        }
        
        aCombi = new ArrayList<>();
        bCombi = new ArrayList<>();
        
        // 각 뽑은 주사위로 나올 수 있는 합의 종류를 Combi 리스트에 저장
        roll(0, 0, aDice, dice, aCombi);
        roll(0, 0, bDice, dice, bCombi);
        
        // A가 뽑은 주사위의 합 조합에 대해서 B가 뽑은 합 조합과 비교하여 승이 몇번있는지 세기
        game(aCombi, bCombi);
        
        return;
    }
    
    private static void roll(int cnt, int sum, int[] nowDice, int[][] dice, List<Integer> sumCombi) {
        // 각 주사위에서 N/2개 선택했다면 선택한 합을 combi에 추가
        if(cnt == N/2) {
            sumCombi.add(sum);
            return;
        }
        
        // 각 주사위에는 6개의 숫자 존재
        for(int i=0; i<6; i++) {
            roll(cnt+1, sum + dice[nowDice[cnt]-1][i], nowDice, dice, sumCombi);
        }
    }
    
    private static void game(List<Integer> aCombi, List<Integer> bCombi) {
        // bCombi를 정렬시키고 aCombi에서 하나씩 뽑아서 bCombi에 대해서 이분탐색
        Collections.sort(bCombi);
        for(int sum : aCombi) {
            aWin += lowerBound(bCombi, sum);
        }
    }
    
    private static int lowerBound(List<Integer> bCombi, int sum) {
        int s = 0, e = bCombi.size();
        while(s < e) {
            int mid = (s+e)/2;
            if(bCombi.get(mid) < sum) s = mid + 1;
            else e = mid;
        }
        return s;
    }
}