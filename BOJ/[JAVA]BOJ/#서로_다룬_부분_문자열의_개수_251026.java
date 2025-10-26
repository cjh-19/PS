import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        HashSet<String> hs = new HashSet<>();
        for(int i=0; i<str.length(); i++) {
            for(int j=i+1; j<=str.length(); j++) {
                hs.add(str.substring(i, j));
            }
        }

        System.out.print(hs.size());
    }
}