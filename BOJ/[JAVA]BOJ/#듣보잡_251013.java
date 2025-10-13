import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> hm = new HashMap<>();
        for(int i=0; i<N; i++) {
            String name = br.readLine();
            hm.put(name, hm.getOrDefault(name, 0) + 1);
        }
        for(int i=0; i<N; i++) {
            String name = br.readLine();
            hm.put(name, hm.getOrDefault(name, 0) + 1);
        }

        List<String> list = new ArrayList<>();
        for(Map.Entry<String, Integer> m : hm.entrySet()) {
            if(m.getValue() == 2) {
                list.add(m.getKey());
            }
        }
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        sb.append(list.size()).append("\n");
        for(String name : list) {
            sb.append(name).append("\n");
        }
        System.out.print(sb);
    }
}