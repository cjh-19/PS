import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<String, String> hm = new HashMap<>();
        for(int i=0; i<N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String record = st.nextToken();
            if(hm.containsKey(name) && hm.get(name).equals("enter") && record.equals("leave")) {
                hm.remove(name);
            } else if(record.equals("enter")) hm.put(name, record);
        }

        StringBuilder sb = new StringBuilder();
        List<String> list = new ArrayList<>();
        for(Map.Entry<String, String> m : hm.entrySet()) {
            list.add(m.getKey());
        }
        Collections.sort(list);
        for(int i=list.size()-1; i>=0; i--) {
            sb.append(list.get(i)).append("\n");
        }
        System.out.print(sb);
    }
}