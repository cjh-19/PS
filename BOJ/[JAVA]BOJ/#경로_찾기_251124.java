import java.util.*;
import java.io.*;

public class Main {
	private static int N, K, last;
	private static List<String> list;
	private static int[] parent;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		parent = new int[N];
		Arrays.fill(parent, -1);
		list = new ArrayList<>();
		for(int i=0; i<N; i++) {
			String str = br.readLine();
			list.add(str);
		}
		
		st = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		
		bfs(s, e);
		if(last==-1) {
			System.out.print(-1);
			return;
		}
		
		StringBuilder sb = new StringBuilder();
		List<Integer> result = new ArrayList<>();
		while(true) {
			result.add(last+1);
			last=parent[last];
			if(last==-1) break;
		}
		for(int i=result.size()-1; i>=0; i--) sb.append(result.get(i)).append(" ");
		
		System.out.print(sb);
	}
	
	private static void bfs(int s, int e) {
		last = -1;
		
		boolean[] visited = new boolean[N];
		Queue<Integer> q = new ArrayDeque<>();
		visited[s-1]=true;
		q.offer(s-1);
		
		while(!q.isEmpty()) {
			int cur = q.poll();
			
			if(cur==e-1) {
				last=e-1;
				return;
			}
			
			for(int i=0; i<list.size(); i++) {
				if(!visited[i] && check(list.get(cur), list.get(i))) {
					q.offer(i);
					parent[i]=cur;
					visited[i]=true;
				}
			}
		}
		
		return;
	}
	
	private static boolean check(String target, String str) {
		int cnt=0;
		for(int i=0; i<K; i++) {
			if(target.charAt(i)!=str.charAt(i))cnt++;
			if(cnt>=2) return false;
		}
		return cnt==1;
	}
}