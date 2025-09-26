import java.util.*;
import java.io.*;

public class Main {
	private static int N, S, sum1Size, sum2Size;
	private static int[] arr;
	private static List<Integer> sum1, sum2;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		sum1 = new ArrayList<>();
		sum2 = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		sumCalc();
		Collections.sort(sum2);
		System.out.print(calc());
	}
	
	private static void sumCalc() {
		makeSubSum(0, N/2, 0, 1);
		sum1Size=sum1.size();
		makeSubSum(N/2, N, 0, 2);
		sum2Size=sum2.size();
	}
	
	private static void makeSubSum(int s, int e, int sum, int num) {
		if(s == e) {
			if(num==1) sum1.add(sum);
			else sum2.add(sum);
			return;
		}
		
		makeSubSum(s+1, e, sum, num);
		makeSubSum(s+1, e, sum+arr[s], num);
	}
	
	private static long calc() {
		long cnt = 0;
		for(int i=0; i<sum1Size; i++) {
			cnt += upper_bound(S-sum1.get(i)) - lower_bound(S-sum1.get(i));
		}
		
		if(S==0) cnt--;
		
		return cnt;
	}
	
	private static int upper_bound(int target) {
		int s=0, e=sum2Size;
		while(s<e) {
			int mid = (s+e)/2;
			if(target >= sum2.get(mid)) {
				s = mid+1;
			} else e = mid;
		}
		return s;
	}
	
	private static int lower_bound(int target) {
		int s=0, e=sum2Size;
		while(s<e) {
			int mid = (s+e)/2;
			if(target > sum2.get(mid)) {
				s = mid+1;
			} else e = mid;
		}
		return s;
	}
}
