import java.util.*;
import java.io.*;

public class Main {
	private static int N, M, T, K;
	private static List<int[]> tList;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		tList = new ArrayList<>();
		
		for(int t=0; t<T; t++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			tList.add(new int[] {x, y});
		}
		
		// x -> y 오름차순 정렬
    Collections.sort(tList, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[0] == o2[0]) {
					return Integer.compare(o1[1], o2[1]);
				}
				else return Integer.compare(o1[0], o2[0]);
			}
		});
		
		int xIdx = 0; // 최적 x 시작점 인덱스
		int yIdx = 0; // 최적 y 시작점 인덱스
		int maxCnt = 0;
		
		int[] buf = new int[T]; // x에 대한 y들을 담는 임시 버퍼
		
		// x의 구역에 맞춰서 y의 구역을 이동시키며 가능한 점들이 몇개인지 카운팅
		// 모든 범인을 x-좌측 변 후보로 하여 탐색
		for(int i=0; i<T; i++) {
			// 현재 x의 시작값
			int baseX = tList.get(i)[0];
			
			int tmplastIdx = i;
			// baseX로부터 K 이내에 들어가는 x 범위의 마지막 인덱스 찾기
			while (tmplastIdx + 1 < T && tList.get(tmplastIdx + 1)[0] <= baseX + K) {
		        tmplastIdx++;
		    }
			
			// 창 [i, tmplastIdx) 내 y들만 추출
			int ySize = 0;
			for(int j=i; j<=tmplastIdx; j++) {
				buf[ySize++] = tList.get(j)[1];
			}
			
			// y 정렬 (0~ySize)
			Arrays.sort(buf, 0, ySize);
			
			// 투포인터로  buf의 값 차이가 K 이상이 되는 구간을 찾고
			// 해당 구간에 들어있는 좌표의 개수 업데이트
			int end = 0;
			for(int start = 0; start<ySize; start++) {
				while(end < ySize && buf[end] - buf[start] <= K) end++;
				int cnt = end-start; // K 구간에 들어가는 가능 좌표 개수
				if(maxCnt < cnt) {
					xIdx = i;
					yIdx = buf[start]; // => 여기는 인덱스 값이 아닌 y의 값이 저장
					maxCnt = cnt;
				}
			}
			
			/* 개선 전 */
			// 현재 x-범위에서 모든 범인을 y-아랫변 후보로 시도
			// x좌표에 해당하는 y들을 모두 돌며 어느 것을 yIdx로 선택했을 때, 범인이 가장 많이 검거되는지 체크
			/*
			for(int c = i; c<=tmplastIdx; c++) {
				int baseY = Math.min(tList.get(c)[1], M - K);
		        int topY  = baseY + K;
		        
				int cnt = 0;
				// 현재 x 범위 안에서 baseY~topY 범위에 들어가는 탈주범 수 카운트
				for(int j=i; j<=tmplastIdx; j++) {
					int yj = tList.get(j)[1];
		            if (baseY <= yj && yj <= topY) cnt++;
				}
				if(maxCnt < cnt) {
					xIdx = i;
					yIdx = c;
					maxCnt = cnt;
				}
			}
			*/
		}
		
		int outX = Math.min(tList.get(xIdx)[0], N - K);
		int outY = Math.min(yIdx, M - K) + K;
		System.out.println(outX + " " + outY);
		System.out.println(maxCnt);
	}

}
