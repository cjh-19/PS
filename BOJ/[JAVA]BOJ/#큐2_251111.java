import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        while(N-->0) {
            String str = br.readLine();
            if(str.contains("push")) {
                st = new StringTokenizer(str);
                st.nextToken();
                dq.offer(Integer.parseInt(st.nextToken()));
            } else if(str.equals("size")) {
                sb.append(dq.size());
            } else if(str.equals("empty")) {
                if(dq.isEmpty()) sb.append("1");
                else sb.append("0");
            } else if(dq.isEmpty()) {
                sb.append("-1");
            } else if(str.equals("pop")) {
                sb.append(dq.pop());
            } else if(str.equals("front")) {
                sb.append(dq.peekFirst());
            } else if(str.equals("back")) {
                sb.append(dq.peekLast());
            }

            if(!str.contains("push")) sb.append("\n");
        }
        System.out.print(sb);
    }
}