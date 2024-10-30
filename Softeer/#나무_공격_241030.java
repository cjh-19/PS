import java.io.*;
import java.util.*;

public class Main {

    private static int n, m;
    private static int[][] board; // 격자 판
    private static int[][] shoot = new int[2][2]; // 공격 정보
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        input(br, st);
        shooting();
        output();

        br.close();
    }

    // 입력받는 메소드
    private static void input(BufferedReader br, StringTokenizer st) throws IOException {
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n+1][m+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0; i<2; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<2; j++){
                shoot[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    // 요정이 공격하는 메소드
    private static void shooting() {
        int l, r;
        for(int i=0; i<2; i++){
            l = shoot[i][0];
            r = shoot[i][1];

            // l행부터 r행까지 공격
            for(int j=l; j<=r; j++){
                // j행 공격
                for(int k=1; k<=m; k++){
                    if(board[j][k] == 1){
                        board[j][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    // 격자에 남은 환경 파괴범 수 출력
    private static void output() {
        int cnt = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(board[i][j] == 1) cnt++;
            }
        }
        System.out.println(cnt);
    }
}
