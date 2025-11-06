import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        while(true) {
            String str = br.readLine();
            if(str.equals(".")) break;
            ArrayDeque<Character> dq = new ArrayDeque<>();
            boolean flag = false;
            for(int i=0; i<str.length(); i++) {
                if(str.charAt(i)=='(' || str.charAt(i)=='[') dq.push(str.charAt(i));
                else if (str.charAt(i)==')' || str.charAt(i)==']') {
                    if(dq.isEmpty()) {
                        flag = true;
                        break;
                    }
                    if(str.charAt(i)==')') {
                        if(dq.pop()!='(') {
                            flag = true;
                            break;
                        }
                    } else if(str.charAt(i)==']') {
                        if(dq.pop()!='[') {
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if(dq.isEmpty() && !flag) sb.append("yes");
            else sb.append("no");
            sb.append("\n");
        }
        System.out.println(sb);
    }
}