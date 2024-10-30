import java.io.*;
import java.util.*;

public class Main {
    private static String input; // 균형 잡힌 괄호 문자열

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        input = br.readLine();
        // 열린 괄호 이후 닫힌 괄호 나오면 1
        // 닫힌 괄호 이후 열린 괄호 나오면 +
        makestr();

        br.close();
    }

    // 수식 만들기
    private static void makestr() {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<input.length()-1; i++){
            if(input.charAt(i) == '(' && input.charAt(i+1) == ')') {
                sb.append(input.charAt(i));
                sb.append('1');
            }
            else if(input.charAt(i) == ')' && input.charAt(i+1) == '(') {
                sb.append(input.charAt(i));
                sb.append('+');
            }
            else {
                sb.append(input.charAt(i));
            }
        }
        sb.append(input.charAt(input.length()-1));

        System.out.println(sb);
    }
}
