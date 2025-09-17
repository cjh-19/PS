import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[] numArr;
	private static int[] maxArr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		numArr = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			numArr[i] = Integer.parseInt(st.nextToken());
		}
		
		maxArr = new int[2];
		maxArr[0]=1_000_000_000;
		maxArr[1]=1_000_000_000;
		for(int i=0; i<N-1; i++) {
			binarySearch(i);
		}
		
		System.out.println(maxArr[0] + " " + maxArr[1]);
	}
	
	private static void binarySearch(int idx) {
		int s = idx+1;
		int e = N;
		
		while(s<e) {
			int mid = (s+e)/2;
			if(Math.abs(numArr[idx]+numArr[mid]) < Math.abs(maxArr[0]+maxArr[1])) {
				maxArr[0] = numArr[idx];
				maxArr[1] = numArr[mid];
			}
			if(numArr[idx] + numArr[mid] < 0) {
				s = mid+1;
			} else e = mid;
		}
	}
}
