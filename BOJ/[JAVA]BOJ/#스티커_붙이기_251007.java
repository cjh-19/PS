import java.util.*;
import java.io.*;

public class Main {
    private static int N, M, K, count;
    private static int[][] board;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        count = 0;

        board = new int[N][M];

        for(int i=0; i<K; i++) {
            st = new StringTokenizer(br.readLine());
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            int[][] piece = new int[Math.max(R, C)][Math.max(R, C)];
            for(int r=0; r<R; r++) {
                st = new StringTokenizer(br.readLine());
                for(int c=0; c<C; c++) {
                    piece[r][c] = Integer.parseInt(st.nextToken());
                }
            }

            sticker(R,C,piece);
        }
        System.out.print(count);
    }

    private static void sticker(int R, int C, int[][] piece) {
        int rotateCnt = 0;
        // 0, 90, 180, 270 -> 총 3번 회전 시킬 동안 통과 한다면 붙이고 break
        while(true) {
            if(R<=N && C<=M && take(R, C, piece)) return;

            if(rotateCnt>2) break;
            rotate(R, C, piece);
            int tmp = R;
            R = C;
            C = tmp;
            rotateCnt++;
        }
    }

    private static void rotate(int R, int C, int[][] piece) {
        int[][] tmpPiece = new int[Math.max(R,C)][Math.max(R,C)];
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                tmpPiece[c][R-r-1] = piece[r][c];
            }
        }
        for(int c=0; c<C; c++) {
            piece[c] = Arrays.copyOf(tmpPiece[c], R);
        }
    }

    private static boolean take(int R, int C, int[][] piece) {
        for(int r=0; r<=N-R; r++) {
            for(int c=0; c<=M-C; c++) {
                boolean flag = true;
                for(int rr=0; rr<R; rr++) {
                    for(int cc=0; cc<C; cc++) {
                        if(piece[rr][cc] == 1 && board[r+rr][c+cc] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag) {
                    for(int rr=0; rr<R; rr++) {
                        for(int cc=0; cc<C; cc++) {
                            if(piece[rr][cc]==1) {
                                board[r+rr][c+cc] = 1;
                                count++;
                            }
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }
}
