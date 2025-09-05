import java.util.*;
import java.io.*;

public class Main {
	private static int N, numCnt, maxResult;
	private static char[] arr;
	private static int[][] numArr;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		arr = new char[N];
		arr = br.readLine().toCharArray();
		
		if(N==1) {
			System.out.println(arr[0]-'0');
			return;
		}
		
		numCnt = N/2+1;
		// {앞 연산자 번호, 연산 결과}
		// 연산자 번호 = + : 0 / - : 1 / * : 2
		numArr = new int[numCnt-1][2];
		for(int i=0; i<numCnt-1; i++) {
			if(i*2-1 < 0) numArr[i][0] = -1;
			else {
				if(arr[i*2-1] == '+') numArr[i][0] = 0;
				else if(arr[i*2-1] == '-') numArr[i][0] = 1;
				else if(arr[i*2-1] == '*') numArr[i][0] = 2;
			}
			if(arr[i*2+1] == '+') {
				numArr[i][1] = (arr[i*2]-'0') + (arr[i*2+2]-'0');
			}
			else if(arr[i*2+1] == '-') {
				numArr[i][1] = (arr[i*2]-'0') - (arr[i*2+2]-'0');
			}
			else if(arr[i*2+1] == '*') {
				numArr[i][1] = (arr[i*2]-'0') * (arr[i*2+2]-'0');
			}
		}

		maxResult = Integer.MIN_VALUE;
		boolean[] visited = new boolean[numCnt-1];
		dfs(0, visited);
		
		System.out.println(maxResult);
	}
	
	private static void dfs(int idx, boolean[] visited) {
		if(idx >= numCnt-1) {
			maxResult = Math.max(maxResult, calculate(visited));
			return;
		}
		
		for(int i=idx; i<numCnt-1; i++) {
			if(i==0) {
				visited[0] = true;
				dfs(1, visited);
				visited[0] = false;
				dfs(1, visited);
			} else {
				if(visited[i-1]) dfs(i+1, visited);
				else {
					visited[i] = true;
					dfs(i+1, visited);
					visited[i] = false;
					dfs(i+1, visited);
				}
			}
		}
	}
	
	private static int calculate(boolean[] visited) {
		int sum = 0;
		for(int i=0; i<numCnt-1; i++) {
			if(visited[i]) {
				if(numArr[i][0]==-1) sum += numArr[i][1];
				else if(numArr[i][0]==0) sum += numArr[i][1];
				else if(numArr[i][0]==1) sum -= numArr[i][1];
				else if(numArr[i][0]==2) sum *= numArr[i][1];
			} 
			else if(i-1>=0 && visited[i-1]) continue;
			else {
				if(numArr[i][0]==-1) sum += (arr[i*2] - '0');
				else if(numArr[i][0]==0) sum += (arr[i*2] - '0');
				else if(numArr[i][0]==1) sum -= (arr[i*2] - '0');
				else if(numArr[i][0]==2) sum *= (arr[i*2] - '0');
			}
		}
		if(!visited[numCnt-2]) {
			if(arr[N-2] == '+') sum += (arr[N-1] - '0');
			else if(arr[N-2] == '-') sum -= (arr[N-1] - '0');
			else if(arr[N-2] == '*') sum *= (arr[N-1] - '0');
		}
		return sum;
	}
}
