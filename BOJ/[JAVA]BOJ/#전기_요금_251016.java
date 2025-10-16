import java.util.*;
import java.io.*;

public class Main {
	private static int A, B;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		StringBuilder sb = new StringBuilder();
		while(true) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			if(A==0 && B==0) break;
			
			// 1. A를 통해서 총 사용량 찾기
			int totalUsed = wattCalc(A);
			
			// 2. 총 사용량 기준으로 이분 탐색으로 상근이 요금 구하기
			int used = binarySearch(B, totalUsed);
			sb.append(used).append("\n");
		}
		
		System.out.print(sb);
	}
	
	private static int binarySearch(int diff, int totalUsed) {
		int s=0, e=totalUsed+1;
		
		while(s<e) {
			int mid = (s+e)/2;
			int used = priceCalc(totalUsed-mid);
			int neiUsed = priceCalc(mid);
			int midDiff = Math.abs(used-neiUsed);
			if(midDiff == diff) {
				return used;
			}
			else if(midDiff < diff) {
				s = mid;
			} else {
				e = mid;
			}
		}
		return priceCalc(totalUsed-s);
	}
	
	private static int wattCalc(int price) {
		long watt = 0;
		int curIdx = 0;
		long[] priceArr = {2, 3, 5, 7};
		long[] wattArr = { 100, 9900, 990000, 999000000};
		while(price > 0) {
			if(wattArr[curIdx]*priceArr[curIdx] >= price) {
				watt += price/priceArr[curIdx];
				price = 0;
			} else {
				watt += wattArr[curIdx];
				price -= wattArr[curIdx]*priceArr[curIdx];
			}
			curIdx++;
		}
		
		return (int)watt;
	}
	
	private static int priceCalc(int watt) {
		long price = 0;
		int curIdx = 0;
		long[] priceArr = {2, 3, 5, 7};
		long[] wattArr = { 100, 9900, 990000, 999000000};
		while(watt > 0) {
			if(wattArr[curIdx] >= watt) {
				price += watt*priceArr[curIdx];
				watt = 0;
			} else {
				price += wattArr[curIdx]*priceArr[curIdx];
				watt -= wattArr[curIdx];
			}
			curIdx++;
		}
		
		return (int)price;
	}
}
