import java.util.*;

class Solution {
    public String solution(String number, int k) {
        // 그리디 알고리즘
        // 각 자리에서 최고로 높은 수가 나오는 경우를 생각
        
        String answer = "";
        StringBuilder answerBuilder = new StringBuilder();
        
        // 문자열을 char 배열로 변환
        char[] arr = number.toCharArray();
        int len = number.length() - k; // 최종 문자열 길이
        
        // 문자 비교를 시작하는 인덱스를 나타내는 변수
        int start = 0;
        
        for(int i=0; i<len; i++){
            char max = '0';
            // start부터 i+k만큼 반복
            for(int j=start; j<=i+k; j++){
                // 가장 큰수를 골라서 그 다음 인덱스를 시작 인덱스로 설정
                if(arr[j] > max){ // max와 현재 확인중인 숫자비교
                    max = arr[j];
                    start = j+1; // 최댓값의 다음 위치
                }
            }
            // 가장 큰 문자를 answerBuilder에 붙이기 - Character클래스를 String으로 변환
            answerBuilder.append(Character.toString(max));
        }
        
        answer = answerBuilder.toString();
        return answer;
    }
}