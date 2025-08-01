import java.util.*;
import java.io.*;

public class Main {
    private static int N, M, R;
    private static int[][] board;
    private static int[][] result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 큰 값으로 2차원 배열 선언
        int maxDim = Math.max(N, M);
        result = new int[maxDim][maxDim];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<R; i++) {
            solve(Integer.parseInt(st.nextToken()));
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sb.append(board[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    private static void solve(int rNum) {
        switch (rNum) {
            case 1: case 2: reverse(rNum); break;
            case 3: case 4: rotate(rNum); break;
            case 5: case 6: four(rNum); break;
        }
    }

    // 1번 2번 연산 => 동일 배열 swap
    private static void reverse(int rNum) {
        // 상하 반전
        if(rNum == 1) {
            for(int i=0; i<N/2; i++) {
                int[] tmp = board[i];
                board[i] = board[N-i-1];
                board[N-i-1] = tmp;
            }
        }
        // 좌우 반전
        else if (rNum == 2) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<M/2; j++) {
                    int tmp = board[i][j];
                    board[i][j] = board[i][M-j-1];
                    board[i][M-j-1] = tmp;
                }
            }
        }
    }

    // 3번 4번 연산
    private static void rotate(int rNum) {
        if(rNum == 3) { // 오른쪽 90도
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    result[j][N-i-1] = board[i][j];
                }
            }
        } else if(rNum == 4) { // 왼쪽 90도
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    result[M-j-1][i] = board[i][j];
                }
            }
        }

        // board - result 배열 swap => N,M 값 변경
        swapArr();
        int tmp = N; N=M; M=tmp;
    }

    // board와 result의 참조 교환
    private static void swapArr() {
        int[][] tmpArr = board;
        board = result;
        result = tmpArr;
    }

    // 5번 6번 연산
    private static void four(int rNum) {
        if(rNum == 5) { // 오른쪽 90도
            for(int i=0; i<N/2; i++) {
                for(int j=0; j<M/2; j++) {
                    int tmp = board[i][j];
                    board[i][j] = board[i+N/2][j];
                    board[i+N/2][j] = board[i+N/2][j+M/2];
                    board[i+N/2][j+M/2] = board[i][j+M/2];
                    board[i][j+M/2] = tmp;
                }
            }
        }else if(rNum == 6) { // 왼쪽 90도
            for(int i=0; i<N/2; i++) {
                for(int j=0; j<M/2; j++) {
                    int tmp = board[i][j];
                    board[i][j] = board[i][j+M/2];
                    board[i][j+M/2] = board[i+N/2][j+M/2];
                    board[i+N/2][j+M/2] = board[i+N/2][j];
                    board[i+N/2][j] = tmp;
                }
            }
        }
    }
}
