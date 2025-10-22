import java.util.*;
import java.io.*;

public class Main {
	private static int N;
	private static int[][] edgeList;
	private static int[] recieve;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		
		edgeList = new int[52][52];
		recieve = new int[52];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			char n1 = st.nextToken().charAt(0);
			char n2 = st.nextToken().charAt(0);
			int w = Integer.parseInt(st.nextToken());
			if(n1>='A' && n1<='Z') {
				if(n2>='A' && n2<='Z') {
					edgeList[n1-'A'][n2-'A'] += w;
					edgeList[n2-'A'][n1-'A'] += w;
				}
				else {
					edgeList[n1-'A'][n2-'a'+26] += w;
					edgeList[n2-'a'+26][n1-'A'] += w;
				}
			} else {
				if(n2>='A' && n2<='Z') {
					edgeList[n1-'a'+26][n2-'A'] += w;
					edgeList[n2-'A'][n1-'a'+26] += w;
				}
				else {
					edgeList[n1-'a'+26][n2-'a'+26] += w;
					edgeList[n2-'a'+26][n1-'a'+26] += w;
				}
			}
		}
		
		int start = 0;
		int end = 25;
		while(bfs(start, end)) {}
		System.out.print(recieve[end]);
	}
	
	private static class Node {
		int n;
		int minW;
		ArrayDeque<Integer> q;
		Node(int n, int minW, ArrayDeque<Integer> q) {
			this.n=n;
			this.minW=minW;
			this.q=q;
		}
	}
	
	private static boolean bfs(int s, int e) {
		ArrayDeque<Node> q = new ArrayDeque<>();
		ArrayDeque<Integer> tmp = new ArrayDeque<>();
		tmp.offer(0);
		boolean[] visited = new boolean[52];
		q.offer(new Node(0, Integer.MAX_VALUE, tmp));
		visited[0]=true;
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			
			if(node.n==e) {
				simulation(node.minW, node.q);
				return true;
			}
			
			for(int i=0; i<edgeList[node.n].length; i++) {
				if(edgeList[node.n][i]==0) continue;
				int w = edgeList[node.n][i];
				if(!visited[i] && w>0) {
					node.q.offer(i);
					q.offer(new Node(i, Math.min(w,node.minW), new ArrayDeque<>(node.q)));
					node.q.removeLast();   
					visited[i]=true;
				}
			}
		}
		return false;
	}
	
	private static void simulation(int minW, ArrayDeque<Integer> q) {
		int[] path = new int[q.size()];
		int idx=0;
		while(!q.isEmpty()) path[idx++] = q.poll();
		
		for(int i=0; i<path.length-1; i++) {
			int n1 = path[i];
			int n2 = path[i+1];
			for(int j=0; j<edgeList[n1].length; j++) {
				if(j==n2) {
					recieve[n2]+=minW;
					edgeList[n1][j]-=minW;
					edgeList[j][n1]+=minW;
				}
			}
		}
	}
}