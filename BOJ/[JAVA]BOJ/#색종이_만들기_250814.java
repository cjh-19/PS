import java.util.*;
import java.io.*;

public class Main {
	static int[][] spaces;
	static int green, white;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		spaces = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				spaces[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		green = white = 0;
		makeSpace(0, 0, N);
		System.out.println(white);
		System.out.println(green);
	}
	
	static void makeSpace(int r, int c, int size) {
		// step1. 주어진 영역이 모두 같은 색상으로 이루어졌는지 체크
		int sum = 0;
		for(int i=r, rEnd=r+size; i<rEnd; i++) {
			for(int j=c, cEnd=c+size; j<cEnd; j++) {
				sum += spaces[i][j];
			}
		}
		
		// step2. 같은 색으로 이루어져 있는다면 해당 색의 카운트 증가 후 리턴
		if(sum == size*size) { // 모두 초록색이면
			++green;
			return;
		} else if(sum == 0) { // 모두 하얀색이면
			++white;
			return;
		} else { // 섞여 있으면
			// step3. 같은 색으로 이러어져 있지 않다면 4분할 후 각 공간에 대해 동일한 처리
			int newSize = size/2;
			makeSpace(r, c, newSize);
			makeSpace(r, c+newSize, newSize);
			makeSpace(r+newSize, c, newSize);
			makeSpace(r+newSize, c+newSize, newSize);
		}
		
	}

}
