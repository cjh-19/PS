/* 개선 풀이 - BitSet 1차원 배열 */
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		BitSet[] reach = new BitSet[N];
		for(int i=0; i<N; i++) {
			reach[i] = new BitSet(N);
			reach[i].set(i); // set을 통해 i번째 인덱스를 1(true로)
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken())-1;
			int n2 = Integer.parseInt(st.nextToken())-1;
			
			reach[n1].set(n2);
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				if(reach[i].get(k)) { // i->k가 참이라면
					reach[i].or(reach[k]); // k가 갈 수 있는 모든 곳을 true로
				}
			}
		}
		
		int cnt = 0;
		for(int i=0; i<N; i++) {
			boolean flag = true;
			for(int j=0; j<N; j++) {
				if(!reach[i].get(j) && !reach[j].get(i)) {
					flag = false;
					break;
				}
			}
			if(flag) cnt++;
		}
		System.out.print(cnt);
	}
}


/* 기존 풀이 - 2차원 배열
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		boolean[][] fw = new boolean[N][N];
		for(int i=0; i<N; i++) {
			Arrays.fill(fw[i], false);
			fw[i][i] = true;
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken())-1;
			int n2 = Integer.parseInt(st.nextToken())-1;
			
			fw[n1][n2] = true;
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(!fw[i][k] || !fw[k][j]) continue;
					fw[i][j] = true;
				}
			}
		}
		
		int cnt = 0;
		for(int i=0; i<N; i++) {
			boolean flag = true;
			for(int j=0; j<N; j++) {
				if(!fw[i][j] && !fw[j][i]) {
					flag = false;
					break;
				}
			}
			if(flag) cnt++;
		}
		System.out.print(cnt);
	}
}

*/