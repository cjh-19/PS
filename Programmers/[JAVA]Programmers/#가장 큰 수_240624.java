import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        // numbers의 숫자를 문자열로 바꾼 뒤 정렬
        String[] strNum = new String[numbers.length];
        for(int i=0; i<numbers.length; i++){
            strNum[i] = Integer.toString(numbers[i]);
        }
        
        // 두 수를 합친게 큰 순서대로 정렬
        Arrays.sort(strNum, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        // 0인 경우 예외처리
        if(strNum[0].equals("0"))
            answer = "0";
        else{        
            for(int i=0; i<strNum.length; i++){
                answer += strNum[i];
            }    
        }
        
        return answer;
    }
}
