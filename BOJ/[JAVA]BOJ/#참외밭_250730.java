import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int K;
	static int[] lenInfo;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		K = Integer.parseInt(st.nextToken());
		
		// 4개의 방향의 최대 길이 배열
		lenInfo = new int[4];
		
		int firstLen = 0;
		int dir = 0;
		int len = 0;
		int prevDir = 0;
		int prevLen = 0;
		int minSquare = 0;
		for(int i=0; i<6; i++) {
			st = new StringTokenizer(br.readLine());
			dir = Integer.parseInt(st.nextToken());
			len = Integer.parseInt(st.nextToken());
			
			lenInfo[dir-1] = Math.max(lenInfo[dir-1], len);
			
			if(i == 0) {
				prevDir = dir;
				prevLen = len;
				firstLen = len;
			}
			else {
				// 작은 삼각형이라면
				if(prevDir == 1 && dir == 3 ||
						prevDir == 3 && dir == 2 ||
						prevDir == 2 && dir == 4 ||
						prevDir == 4 && dir == 1) {
					minSquare = prevLen * len;
				}
			}
			prevDir = dir;
			prevLen = len;
		}
		
		if(minSquare == 0) {
			minSquare = firstLen * len;
		}
		
		int maxSquare = 0;
		maxSquare = Math.max(lenInfo[0], lenInfo[1]) * Math.max(lenInfo[2], lenInfo[3]);
		
		System.out.print(K * (maxSquare - minSquare));
		
		br.close();
	}

}
