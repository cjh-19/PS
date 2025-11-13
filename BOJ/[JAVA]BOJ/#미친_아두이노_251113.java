import java.util.*;
import java.io.*;

public class Main {
    private static int R, C;
    private static char[][] board;
    private static int[] dx = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    private static int[] dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    private static HashMap<Integer, int[]> hm;
    private static HashSet<Integer> hs, removeIdx;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int[] me = new int[2];
        hm = new HashMap<>();
        hs = new HashSet<>();
        removeIdx = new HashSet<>();
        int idx=1;
        board = new char[R][C];
        for(int i=0; i<R; i++) {
            String str = br.readLine();
            for(int j=0; j<C; j++) {
                board[i][j] = str.charAt(j);
                if(board[i][j]=='I') {
                    me[0]=i;me[1]=j;
                }
                else if(board[i][j]=='R') {
                    hm.put(idx, new int[] {i,j});
                    hs.add(idx);
                    idx++;
                }
            }
        }

        boolean flag = false;
        String cmds = br.readLine();
        int moveCnt = 0;
        for(int i=0; i<cmds.length(); i++) {
            int cmd = cmds.charAt(i) - '0' - 1;

            int nx = me[0] + dx[cmd];
            int ny = me[1] + dy[cmd];
            moveCnt++;
            if(board[nx][ny]=='R') {
                flag = true;
                break;
            }
            board[me[0]][me[1]] = '.';
            me[0] = nx; me[1] = ny;
            board[nx][ny] = 'I';

            int[][] newBoard = new int[R][C];
            removeIdx.clear();
            for(int tNum : hs) {
                if(hm.containsKey(tNum)) {
                    if(!move(hm.get(tNum), me, tNum, newBoard)){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;

            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    if (board[j][k] == 'R') {
                        board[j][k] = '.';
                    }
                }
            }
            for(int n : removeIdx) {
                hs.remove(n);
                hm.remove(n);
            }
            for (int tNum : hs) {
                int[] pos = hm.get(tNum);
                board[pos[0]][pos[1]] = 'R';
            }
        }

        if(flag) {
            System.out.print("kraj " + moveCnt);
            return;
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                sb.append(board[i][j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    private static boolean move(int[] target, int[] me, int tNum, int[][] newBoard) {
        int nx=target[0], ny=target[1];

        if(me[0]>target[0]) nx++;
        else if(me[0]<target[0]) nx--;

        if(me[1]>target[1]) ny++;
        else if(me[1]<target[1]) ny--;

        if(board[nx][ny]=='I') return false;
        else if(newBoard[nx][ny]>0) {
            removeIdx.add(newBoard[nx][ny]);
            removeIdx.add(tNum);
        }
        else {
            board[nx][ny] = 'R';
            hm.put(tNum, new int[] {nx,ny});
            newBoard[nx][ny] = tNum;
        }

        return true;
    }
}