import java.util.*;
import java.io.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T;
    public static String RD;
    public static int len;
    public static ArrayDeque<Integer> deque;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());

        while(T --> 0) {
            RD = br.readLine();
            len = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), "[],");

            deque = new ArrayDeque<Integer>();

            for(int i=0; i<len; i++) {
                deque.offer(Integer.parseInt(st.nextToken()));
            }
            calculate();
        }

        System.out.println(sb);
    }

    public static void calculate() {
        boolean isReversed = false;

        for(char rd : RD.toCharArray()) {
            if(rd == 'R') {
                isReversed = !isReversed;
                continue;
            }
            else if(rd == 'D') {
                if(!isReversed) { // 뒤집지 않은 상태
                    if(deque.pollFirst() == null) { // 앞에서 뽑기 & 빈 덱이라면
                        sb.append("error\n");
                        return;
                    }
                }
                else {
                    if(deque.pollLast() == null) {
                        sb.append("error\n");
                        return;
                    }
                }
            }
        }
        printDeque(isReversed);
    }

    public static void printDeque(boolean isReversed) {
        sb.append("[");

        if(!deque.isEmpty()) {
            if(!isReversed) {
                sb.append(deque.pollFirst());
                while(!deque.isEmpty()) {
                    sb.append(",").append(deque.pollFirst());
                }
            }
            else {
                sb.append(deque.pollLast());
                while(!deque.isEmpty()) {
                    sb.append(",").append(deque.pollLast());
                }
            }
        }

        sb.append("]").append("\n");
    }
}