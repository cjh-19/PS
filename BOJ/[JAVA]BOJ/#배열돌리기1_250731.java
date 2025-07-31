import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N, M, R;
	static int[][] board;
	static int[][] result;

	public static void main(String[] args) throws Exception {
		// System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		
		// 원본 배열
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 결과 배열 초기화 (얕은 복사)
		result = new int[N][M];
		for(int i=0; i<N; i++) {
			result[i] = Arrays.copyOf(board[i], M);
		}
		
		// 레이어 개수
		int layerCnt = Math.min(N, M) / 2;
		
		// 각 레이어별로 회전 수행
		for(int layer = 0; layer<layerCnt; layer++) {
			// 현재 레이어의 요소를 일차원 배열에 저장
			List<Integer> elements = extractLayer(layer);
			
			// 필요한 회전수 (레이어의 테두리의 나머지 -> 중복 회전 방지) 모듈러 연산
			int rCnt = R % elements.size();
			
			// 리스트를 r만큼 회전
			List<Integer> rotated = rotateList(elements, rCnt);
			
			// 회전된 값을 result 배열에 채우기
			fillLayer(rotated, layer);
		}
		
		print();
		
		System.out.println(sb);
		br.close();
	}
	
	private static void print() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				sb.append(result[i][j]);
				if(j < M - 1) sb.append(" ");
			}
			sb.append("\n");
		}
	}
	
	// 레이어에 해당하는 요소를 일차원 배열로 저장 (시계방향으로)
	private static List<Integer> extractLayer(int layer) {
		List<Integer> list = new ArrayList<>();
		
		// top (왼 -> 오)
		for(int l=layer; l<=M-layer-1; l++) {
			list.add(board[layer][l]);
		}
		
		// right (위+1 -> 아래-1)
		for(int l=layer+1; l<N - layer - 1; l++) {
			list.add(board[l][M - layer - 1]);
		}
		
		// bottom (오 -> 왼)
		for(int l=M-layer-1; l>=layer; l--) {
			list.add(board[N - layer - 1][l]);
		}
		
		// left (아래+1 -> 위-1)
		for(int l=N-layer-2; l>layer; l--) {
			list.add(board[l][layer]);
		}
		
		return list;
	}
	
	// rCnt만큼 오른쪽 요소를 좌측으로 당겨 넣음
	private static List<Integer> rotateList(List<Integer> list, int rCnt) {
		List<Integer> rotated = new ArrayList<>();
		
		for(int i=0; i<list.size(); i++) {
			rotated.add(list.get((i+rCnt) % list.size()));
		}
		return rotated;
	}
	
	// 회전시킨 layer를 result 배열에 넣기
	private static void fillLayer(List<Integer> rotated, int layer) {
		int idx = 0;
		
		// top (왼 -> 오)
		for(int l=layer; l<=M-layer-1; l++) {
			result[layer][l] = rotated.get(idx++);
		}
		
		// right (위+1 -> 아래-1)
		for(int l=layer+1; l<N - layer - 1; l++) {
			result[l][M - layer - 1] = rotated.get(idx++);
		}
		
		// bottom (오 -> 왼)
		for(int l=M-layer-1; l>=layer; l--) {
			result[N - layer - 1][l] = rotated.get(idx++);
		}
		
		// left (아래+1 -> 위-1)
		for(int l=N-layer-2; l>layer; l--) {
			result[l][layer] = rotated.get(idx++);
		}
	}
}
