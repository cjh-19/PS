import java.io.*;
import java.util.*;

public class Solution {

    static StringBuilder sb = new StringBuilder();
    static int T, H, W, N;
    static char[][] board;
    static char[] control;
    static int[] pos;
    static int dir;

    // 상 하 좌 우
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    static void battle() {
        for(int i=0; i<N; i++) {
            char con = control[i];

            if(con == 'U') {
                dir = 0;
                board[pos[0]][pos[1]] = '^';
                int nx = pos[0] + dx[dir];
                int ny = pos[1] + dy[dir];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == '.') {
                    board[pos[0]][pos[1]] = '.';
                    pos = new int[] {nx, ny};
                    board[nx][ny] = '^';
                }
            }
            else if(con == 'D') {
                dir = 1;
                board[pos[0]][pos[1]] = 'v';
                int nx = pos[0] + dx[dir];
                int ny = pos[1] + dy[dir];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == '.') {
                    board[pos[0]][pos[1]] = '.';
                    pos = new int[] {nx, ny};
                    board[nx][ny] = 'v';
                }
            }
            else if(con == 'L') {
                dir = 2;
                board[pos[0]][pos[1]] = '<';
                int nx = pos[0] + dx[dir];
                int ny = pos[1] + dy[dir];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == '.') {
                    board[pos[0]][pos[1]] = '.';
                    pos = new int[] {nx, ny};
                    board[nx][ny] = '<';
                }
            }
            else if(con == 'R') {
                dir = 3;
                board[pos[0]][pos[1]] = '>';
                int nx = pos[0] + dx[dir];
                int ny = pos[1] + dy[dir];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == '.') {
                    board[pos[0]][pos[1]] = '.';
                    pos = new int[] {nx, ny};
                    board[nx][ny] = '>';
                }
            }
            else if(con == 'S') {
                int xpos = pos[0] + dx[dir];
                int ypos = pos[1] + dy[dir];
                while(true) {
                    if(xpos < 0 || xpos >= H || ypos < 0 || ypos >= W) break;
                    if(board[xpos][ypos] == '*') {
                        board[xpos][ypos] = '.';
                        break;
                    }
                    else if(board[xpos][ypos] == '#') {
                        break;
                    }

                    xpos += dx[dir];
                    ypos += dy[dir];
                }
            }
        }
    }

    static void output() {
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                sb.append(board[i][j]);
            }
            sb.append("\n");
        }
    }

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            board = new char[H][W];
            for(int h=0; h<H; h++) {
                String str = br.readLine();
                for(int w=0; w<W; w++) {
                    board[h][w] = str.charAt(w);
                    if(board[h][w] == '^') {
                        pos = new int[] {h,w};
                        dir = 0;
                    }
                    else if(board[h][w] == 'v') {
                        pos = new int[] {h,w};
                        dir = 1;
                    }
                    else if(board[h][w] == '<') {
                        pos = new int[] {h,w};
                        dir = 2;
                    }
                    else if(board[h][w] == '>') {
                        pos = new int[] {h,w};
                        dir = 3;
                    }
                }
            }

            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            control = new char[N];
            String str = br.readLine();
            for(int n=0; n<N; n++) {
                control[n] = str.charAt(n);
            }

            battle();

            sb.append("#").append(t).append(" ");
            output();
        }

        System.out.println(sb);
        br.close();
    }
}