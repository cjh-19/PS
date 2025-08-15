import java.util.*;
import java.io.*;

public class Main {
	private static int N, r, c;
	private static long count;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		count = 0;
		
		zPoint(0, 0, N);
		System.out.print(count);
	}
	
	private static void zPoint(int rPos, int cPos, int size) {
		// z를 그릴 수 있게 됐다면 4칸 방문
		if(size == 1) {
			if(rPos+1 == r && cPos+1 == c) count += 3;
			else if(rPos+1 == r) count += 2;
			else if(cPos+1 == c) count += 1;
			return;
		}
		
		// 네 칸으로 분할
		int halfSize = 1<<(size-1);
		boolean rcheck = false, ccheck = false;
		if(rPos+halfSize <= r) {
			rPos = rPos+halfSize;
			rcheck = true;
		}
		if(cPos+halfSize <= c) {
			cPos = cPos+halfSize;
			ccheck = true;
		}
		
		if(rcheck && ccheck) {
			count += halfSize*halfSize*3;
		} else if(rcheck) {
			count += halfSize*halfSize*2;
		} else if(ccheck) {
			count += halfSize*halfSize;
		}
		zPoint(rPos, cPos, size-1);
	}
}