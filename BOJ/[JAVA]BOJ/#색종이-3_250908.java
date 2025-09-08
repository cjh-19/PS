import java.util.*;
import java.io.*;

public class Main {
	private static int N, maxX, maxY;
	private static int[][] board, prefix;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		
		maxX = 0; maxY = 0;
		board = new int[101][101];
		prefix = new int[102][102];
		
		for(int i=0; i<101; i++) Arrays.fill(board[i], -1000000);
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int xpos = Integer.parseInt(st.nextToken());
			int ypos = Integer.parseInt(st.nextToken());
			
			for(int j=xpos; j<xpos+10; j++) {
				for(int k=ypos; k<ypos+10; k++) {
					board[j][k] = 1;
					maxX = Math.max(maxX, j);
					maxY = Math.max(maxY, k);
				}
			}
		}
		
		System.out.println(prefixFunc());
	}
	
	private static int prefixFunc() {
		// 누적합 구하기
		for(int i=1; i<=maxX; i++) {
			for(int j=1; j<=maxY; j++) {
				prefix[i][j] = board[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
			}
		}
		
		int result = 0;
		// 구간합 구하기
		for(int i=1; i<=maxX; i++) {
			for(int j=1; j<=maxY; j++) {
				for(int k=i+1; k<=maxX; k++) {
					for(int w=j+1; w<=maxY; w++) {
						int sum = prefix[k][w] - prefix[i-1][w] - prefix[k][j-1] + prefix[i-1][j-1];
						if(sum < 0) break; // 구간에 빈칸이 있다면
						result = Math.max(result, sum);
					}
				}
			}
		}
		
		return result;
	}
}
