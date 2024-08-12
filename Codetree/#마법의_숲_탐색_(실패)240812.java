import java.util.*;
import java.io.*;

public class Main {
    static int R, C, K; // 행, 열, 정령수
    static int[][] gol; // k개의 골렘 정보
    static int[][] board; // RxC 맵
    static int count = 0; // 정령들의 최종위치를 누적할 변수 (최종 반환값)
    static int[] dx = {-1, 1, 0, 0}; // 상 하 좌 우
    static int[] dy = {0, 0, -1, 1}; // 상 하 좌 우

    public static void main(String[] args) throws IOException{
        // 맵: RxC (R행, C열)
        // K명 정령 골렘을 타고 숲 탐색
        // 골렘은 십자모양(동서남북 + 중앙), 동서남북 중 한칸은 골렘 출구
        // 정령은 어떤 방향이든 골렘 탑승 가능
        // 내릴 때는 정해진 출구로만 가능

        /* 골렘 시작 */
        // i번째로 숲을 탐색하는 골렘은 숲의 가장 북쪽에서 시작
        // 골렘의 중앙이 ci열이 되도록 하는 위치에서 내려오기 시작
        // 초기 골렘 출구: di 방향 위치
        // 우선순위에 맞게 이동하고 더이상 움직이지 못할때까지 과정 반복

        // 1순위: 남
        // 2순위: 서, 3순위: 동 -> 마지막 남쪽 이동
        // 서쪽으로 이동하면 출구가 반시계방향으로 회전
        // 동쪽으로 이동하면 출구가 시계방향으로 회전
        // 북0, 동1, 남2, 서3

        // 숫자 입력 (R,C,K 입력)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken()); // 행
        C = Integer.parseInt(st.nextToken()); // 열
        K = Integer.parseInt(st.nextToken()); // 정령 수

        board = new int[R][K]; // 맵
        boardinit(); // 맵 모든 칸 0으로 초기화

        gol = new int[K][2];
        // K개 골렘의 배열 받기
        for(int i=0; i<K; i++){
            st = new StringTokenizer(br.readLine());
            gol[i][0] = Integer.parseInt(st.nextToken()) - 1; // 출발 열
            gol[i][1] = Integer.parseInt(st.nextToken()); // 출구 위치 0-3
        }
        /* 입력 완료 */

        // 구현해야할 함수
        // 0. 보드를 초기화할 함수
        // 1. 골렘을 최하단으로 내리는 함수
        // 2. 정령을 최하단으로 내리는 함수
        // 3. 이동 완료했는데, 정령이 맵 밖에 있는지 확인하는 함수

        /* 1번 함수 방식 */
        // 다음 이동할 위치의 map 값(동서남)이 0인 경우 이동
        // 그렇지 않은 경우(하나라도 0이 아닌 경우) 왼쪽 -> 아래쪽 이동
        // 왼쪽도 없는 경우 오른쪽 -> 아래쪽 이동
        // 둘다 안되는 경우 고정
        // 고정하고 나면 골렘 위치(5칸) map값은 순번(1~k)로 변환, 출구는 -1로 변환
        
        /* 2번 함수 방식 dfs */
        // 최종 위치에서 가장 깊게 내려갈 수 있는 위치로 이동
        // -1위치에서는 어디든 갈 수 있음
        // -1 아닌 값 위치면 같은 값으로만 이동 가능

        for(int i=0; i<k; i++){
            int n1 = gol[i][0]; // 시작 열
            int n2 = gol[i][1]; // 출구 위치

            int[] lastPos = new int[2]; // 골렘 이동후 정령 최종 위치
            lastPos = moveGol(n1, n2); // 골렘 이동 

            // 맵이 꽉차서 정령이 맵 밖인 경우
            if(lastPos[0] == -2 && lastPos[1] === -2){
                boardinit(); // 맵 초기화
                continue; // 이번 for문 패스
            }


        }
    }

    /* 0번 함수 - 맵 초기화*/
    public void boardinit(){
        for(int i=0; i<R; i++){
            for(int j=0; j<K; j++){
                board[i][j] == 0;
            }
        }
    }

    /* 1번 함수 - 골렘 내리기 */
    // current: 시작 열, point: 출구위치
    public int[] moveGol(int current, int point){
        int[] lastPos = new int[2]; // 최종 정령 위치
        int low = 0; // 시작 행
        
        // 첫번째 이동: 아래쪽만 확인하면 됨
        if(map[low][current] > 0){ // 골렘이 있는 경우
            return [-2, -2];
        }
        else{
            low++;
        }

        // 두번째 이상부터 이동: 좌,우,하 모두 확인

        return lastPos;
    }

    /* 2번 함수 - 정령 내리기 */
    // current: 현재 위치, cnt: 열위치
    public void dfs(int current, int cnt){

    }
}