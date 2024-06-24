import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        // numbers의 숫자를 문자열로 바꾼 뒤 정렬
        
        // 문자열로 바꿔 넣을 배열
        ArrayList<String> strNum = new ArrayList<>();
        
        for(int i=0; i < numbers.length; i++){
            strNum.add(Integer.toString(numbers[i]));
        }
        
        // 정렬
        Collections.sort(strNum, Collections.reverseOrder());
        
        for(int i=0; i < strNum.size(); i++){
            answer += strNum.get(i);
        }
        
        return answer;
    }
}

// 내림차순으로 정렬하다가 앞자리가 같은 경우 숫자 오름차순
Class cmp implements Comparator<String>{
    @Override
    public String compare(String str1, String str2){
        if(str1[0] == str2[0]){
            return str1 < str2;
        }
        return str1 > str2;
    }
}