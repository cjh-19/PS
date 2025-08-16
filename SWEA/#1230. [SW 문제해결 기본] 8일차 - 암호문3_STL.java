import java.util.*;
import java.io.*;

public class Solution{
    private static int N, M;
    private static List<Integer> list;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;

        StringBuilder sb = new StringBuilder();
        for(int t=1; t<=10; t++) {
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            list = new LinkedList<>();
            for(int i=0; i<N; i++) {
                int num = Integer.parseInt(st.nextToken());
                list.add(num);
            }

            M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<M; i++) {
                char cmd = st.nextToken().charAt(0);
                switch(cmd) {
                    case 'I': {
                        int x = Integer.parseInt(st.nextToken());
                        int y = Integer.parseInt(st.nextToken());
                        // y개의 암호 삽입
                        for(int j=0; j<y; j++) {
                            int num = Integer.parseInt(st.nextToken());
                            list.add(x++, num);
                        }
                        break;
                    }
                    case 'D': {
                        int x = Integer.parseInt(st.nextToken());
                        int y = Integer.parseInt(st.nextToken());
                        for(int j=0; j<y; j++) {
                            list.remove(x+1);
                        }
                        break;
                    }
                    case 'A': {
                        int y = Integer.parseInt(st.nextToken());
                        for(int j=0; j<y; j++) {
                            int num = Integer.parseInt(st.nextToken());
                            list.add(num);
                        }
                        break;
                    }

                }
            }
            sb.append("#").append(t).append(" ");
            for(int i=0; i<10; i++) {
                sb.append(list.get(i)).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}