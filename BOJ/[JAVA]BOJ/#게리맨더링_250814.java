import java.util.*;
import java.io.*;

public class Main {
	private static int N, totalSum, minDiff;
	private static int[] peoples;
	private static List<Integer>[] zones;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		peoples = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=N; i++) {
			peoples[i] = Integer.parseInt(st.nextToken());
		}
		
		totalSum = 0;
		minDiff = Integer.MAX_VALUE;
		zones = new ArrayList[N+1];
		zones[0] = new ArrayList<>();
		for(int i=1; i<=N; i++) {
			zones[i] = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			
			int connectZoneCnt = Integer.parseInt(st.nextToken());
			for(int j=0; j<connectZoneCnt; j++) {
				zones[i].add(Integer.parseInt(st.nextToken()));
			}
		}
		
		// 구역이 한 개라면 연결된 노드가 가장 적은 노드를 선택해서 조합 구하기
		if(zoneCntBfs() == 1) {
			minZone();
		}
	}
	
	private static int zoneCntBfs() {
		int zcnt = 0;
		boolean[] visited = new boolean[N+1];
		List<Integer> sumZone = new ArrayList<>();
		
		for(int i=1; i<=N; i++) {
			int sum = 0;
			if(!visited[i]) {
				zcnt++;
				Queue<Integer> q = new ArrayDeque<>();
				q.offer(i);
				visited[i] = true;
				
				while(!q.isEmpty()) {
					int node = q.poll();
					sum += peoples[node];
					totalSum += peoples[node];
					
					// node에 연결된 노드
					for(int n : zones[node]) {
						if(!visited[n]) {
							visited[n] = true;
							q.offer(n);
						}
					}
				}
				sumZone.add(sum);
			}
		}
		
		if(zcnt >= 3) {
			System.out.print(-1);
		}
		else if(zcnt == 2) {
			System.out.print(Math.abs(sumZone.get(0) - sumZone.get(1)));
		}
		
		return zcnt;
	}
	
	private static void minZone() {
		// nC1, nC2, ..., nCn/2 까지의 조합을 모두 만들며 구역 차이 계산
		for(int r=1; r<=N/2; r++) {
			int[] combArr = new int[N+1];
			// 선택한 숫자 개수, 시작 번호, r, combArr
			combi(0, 1, r, combArr);
		}
		
		System.out.print(minDiff);
	}
	
	private static void combi(int cnt, int idx, int r, int[] combArr) {
		if(cnt == r) {
			calculateDiff(combArr);
			return;
		}
		
		for(int i=idx; i<=N; i++) {
			combArr[i] = 1;
			combi(cnt+1, i+1, r, combArr);
			combArr[i] = 0;
		}
	}
	
	private static void calculateDiff(int[] combArr) {
		// 선택된 combArr으로 bfs를 통해서 구역별 값의 차이를 구하는데, 이때, 지역구가 3개 이상이 생기면 continue;
		boolean[] visited = new boolean[N+1];
		int onezcnt = 0, zerozcnt = 0, sumZone = 0;
		
		// 첫번째 지역구 연결
		for(int i=1; i<=N; i++) {
			if(!visited[i] && combArr[i] == 1) {
				onezcnt++;
				if(onezcnt > 1) break;
				Queue<Integer> q = new ArrayDeque<>();
				q.offer(i);
				visited[i] = true;
				
				while(!q.isEmpty()) {
					int node = q.poll();
					sumZone += peoples[node];
					
					// node에 연결된 노드
					for(int n : zones[node]) {
						if(!visited[n] && combArr[n] == 1) {
							visited[n] = true;
							q.offer(n);
						}
					}
				}
			}
		}
		
		// 두번째 지역구 연결
		for(int i=1; i<=N; i++) {
			if(!visited[i] && combArr[i] == 0) {
				zerozcnt++;
				if(zerozcnt > 1) break;
				Queue<Integer> q = new ArrayDeque<>();
				q.offer(i);
				visited[i] = true;
				
				while(!q.isEmpty()) {
					int node = q.poll();
					
					// node에 연결된 노드
					for(int n : zones[node]) {
						if(!visited[n] && combArr[n] == 0) {
							visited[n] = true;
							q.offer(n);
						}
					}
				}
			}
		}
		
		// 두 지역구가 각각 하나로 연결되어있다면
		if(onezcnt == 1 && zerozcnt == 1) minDiff = Math.min(minDiff, Math.abs(totalSum - sumZone*2));
	}
}