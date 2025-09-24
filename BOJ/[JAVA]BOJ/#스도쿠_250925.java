import java.util.*;
import java.io.*;

public class Main {
    private static int[][] board;
    private static boolean[][] rowVisited;
    private static boolean[][] colVisited;
    private static boolean[][] boxVisited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        board = new int[9][9];
        rowVisited = new boolean[9][10];
        colVisited = new boolean[9][10];
        boxVisited = new boolean[9][10];
        for(int i=0; i<9; i++) {
            String row = br.readLine();
            for(int j=0; j<9; j++) {
                int n = row.charAt(j) - '0';
                board[i][j] = n;
                if(n != 0) {
                    rowVisited[i][n] = true;
                    colVisited[j][n] = true;
                    boxVisited[(i/3)*3 + j/3][n] = true;
                }
            }
        }

        dfs(0, 0);
    }

    private static boolean dfs(int r, int c) {
        if(r == 9) {
            printBoard();
            return true;
        }
        int nr = c==8 ? r+1 : r;
        int nc = c==8 ? 0 : c+1;

        if(board[r][c] != 0) {
            return dfs(nr, nc);
        }

        int boxIdx = (r/3)*3+(c/3);
        for(int n=1; n<=9; n++) {
            if(!rowVisited[r][n] && !colVisited[c][n] && !boxVisited[boxIdx][n]) {
                board[r][c] = n;
                rowVisited[r][n] = colVisited[c][n] = boxVisited[boxIdx][n] = true;
                if(dfs(nr, nc)) return true;
                board[r][c] = 0;
                rowVisited[r][n] = colVisited[c][n] = boxVisited[boxIdx][n] = false;
            }
        }

        return false;
    }

    private static void printBoard() {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sb.append(board[i][j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
