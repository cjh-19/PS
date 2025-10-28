import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayDeque<Integer> stack = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            if(cmd==1) {
                int x = Integer.parseInt(st.nextToken());
                stack.push(x);
            } else if(cmd==2) {
                if(stack.isEmpty()) {
                    sb.append("-1\n");
                }
                else sb.append(stack.pop()).append("\n");
            } else if(cmd==3) {
                sb.append(stack.size()).append("\n");
            } else if(cmd==4) {
                if(stack.isEmpty()) sb.append("1\n");
                else sb.append("0\n");
            } else {
                if(stack.isEmpty()) sb.append("-1\n");
                else sb.append(stack.peek()).append("\n");
            }
        }

        System.out.print(sb);
    }
}