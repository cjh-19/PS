import java.util.*;
import java.io.*;

public class Main {
    private static int N;
    private static int[][] board;
    private static StringBuilder sb;
    private static class Block {
        int h;
        int w;
        int[][] info;
        Block(int h, int w, int[][] info) {
            this.h=h;
            this.w=w;
            this.info=info;
        }
    }
    private static List<Block> blockList;
    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};
    private static long maxSum;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        blockList = new ArrayList<>();
        initBlock();

        sb = new StringBuilder();
        int t=1;
        while(true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            if(N==0) break;

            maxSum=Long.MIN_VALUE;
            board = new int[N][N];
            for(int i=0; i<N; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    for(Block block : blockList) {
                        if(i+block.h<=N && j+block.w<=N) {
                            check(i, j, block);
                        }
                    }
                }
            }

            sb.append(t++).append(". ").append(maxSum).append("\n");
        }

        System.out.print(sb);
    }

    private static void initBlock() {
        int[][] block1 = {{1,1,1,1}};
        int[][] block2 = {{1,1,0},{0,1,1}};
        int[][] block3 = {{1,1,1},{0,0,1}};
        int[][] block4 = {{1,1,1},{0,1,0}};
        int[][] block5 = {{1,1},{1,1}};
        Block tmp;

        blockList.add(new Block(1, 4, block1));
        blockList.add(rotate(block1));
        blockList.add(new Block(2, 3, block2));
        blockList.add(rotate(block2));
        blockList.add(new Block(2, 3, block3));
        tmp = rotate(block3);
        blockList.add(tmp);
        tmp = rotate(tmp.info);
        blockList.add(tmp);
        tmp = rotate(tmp.info);
        blockList.add(tmp);
        blockList.add(new Block(2, 3, block4));
        tmp = rotate(block4);
        blockList.add(tmp);
        tmp = rotate(tmp.info);
        blockList.add(tmp);
        tmp = rotate(tmp.info);
        blockList.add(tmp);
        blockList.add(new Block(2, 2, block5));
    }

    private static Block rotate(int[][] block) {
        int h = block.length;
        int w = block[0].length;
        int[][] info = new int[w][h];
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                info[j][h-i-1]=block[i][j];
            }
        }

        return new Block(w, h, info);
    }

    private static void check(int r, int c, Block block) {
        int h = block.h;
        int w = block.w;
        long sum=0;
        if(r+h>N || c+w>N) return;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (block.info[i][j] == 1) {
                    sum += board[r + i][c + j];
                }
            }
        }

        maxSum = Math.max(maxSum, sum);
    }
}