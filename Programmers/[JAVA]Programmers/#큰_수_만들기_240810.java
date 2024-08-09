/* 풀이 2 - 스택(훨씬 효율이 좋음) */
import java.util.*;

class Solution {
    public String solution(String number, int k) {
        // 스택을 활용
        Stack<Character> stack = new Stack<>();
        
        int len = number.length();
        int toRemove = k; // 제거할 문자수
        
        for(int i=0; i<len; i++){
            char c = number.charAt(i); // i번째 문자
            
            // 스택이 비어있지 않고 && 스택의 top이 현재 문자보다 작고 && 문자를 모두 제거하지 않을 경우
            while(!stack.isEmpty() && stack.peek() < c && toRemove > 0){
                // 스택의 top(작은 숫자)을 지우고 toRemove 감소
                stack.pop();
                toRemove--;
            }
            
            // 작은 숫자를 지우고 남은 가장 큰 숫자를 stack에 추가
            stack.push(c);
        }
        
        // 제거할 문자가 남은 경우
        while(toRemove > 0){
            stack.pop(); // 스택의 top(문자열의 뒷부분)부터 제거
            toRemove--;
        }
        
        StringBuilder answerBuilder = new StringBuilder();
        for(char ch : stack){
            answerBuilder.append(ch);
        }
        
        return answerBuilder.toString();
    }
}

/* 풀이 1 - 그리디 */
// import java.util.*;

// class Solution {
//     public String solution(String number, int k) {
//         // 그리디 알고리즘
//         // 각 자리에서 최고로 높은 수가 나오는 경우를 생각
        
//         String answer = "";
//         StringBuilder answerBuilder = new StringBuilder();
        
//         // 문자열을 char 배열로 변환
//         char[] arr = number.toCharArray();
//         int len = number.length() - k; // 최종 문자열 길이
        
//         // 문자 비교를 시작하는 인덱스를 나타내는 변수
//         int start = 0;
        
//         for(int i=0; i<len; i++){
//             char max = '0';
//             // start부터 i+k만큼 반복
//             for(int j=start; j<=i+k; j++){
//                 // 가장 큰수를 골라서 그 다음 인덱스를 시작 인덱스로 설정
//                 if(arr[j] > max){ // max와 현재 확인중인 숫자비교
//                     max = arr[j];
//                     start = j+1; // 최댓값의 다음 위치
//                 }
//             }
//             // 가장 큰 문자를 answerBuilder에 붙이기 - Character클래스를 String으로 변환
//             answerBuilder.append(Character.toString(max));
//         }
        
//         answer = answerBuilder.toString();
//         return answer;
//     }
// }