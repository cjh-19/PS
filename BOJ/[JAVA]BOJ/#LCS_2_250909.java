import java.util.*;
import java.io.*;

public class Main {
	private static String s1, s2;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		s1 = br.readLine();
		s2 = br.readLine();
		
		int[][] dp = new int[s2.length()+1][s1.length()+1];
		
		for(int i=0; i<s2.length(); i++) {
			for(int j=0; j<s1.length(); j++) {
				if(s2.charAt(i) == s1.charAt(j)) {
					dp[i+1][j+1] = dp[i][j] + 1;
				} else {
					dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
				}
			}
		}
		
		int tmp = dp[s2.length()][s1.length()];
		System.out.println(tmp);
		StringBuilder sb = new StringBuilder();
		int i = s2.length(), j = s1.length();
		while(i>0 && j>0) {
			if(s2.charAt(i-1)==s1.charAt(j-1)) {
				sb.append(s1.charAt(j-1));
				i--;
				j--;
			} else if(dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}
		System.out.println(sb.reverse().toString());
	}
}
