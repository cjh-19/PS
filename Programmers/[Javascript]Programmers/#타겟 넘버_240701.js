function solution(numbers, target) {
    var answer = 0;
    
    function dfs(index, sum){
        // 끝까지 탐색했고
        if(index === numbers.length){
            // 다 더한 값이 target과 같다면
            if(sum === target)
                answer++; // 방법의 수 증가
            return;
        }
        // 탐색 중 (현재 인덱스를 sum에 더하고 빼는 경우 두가지를 진행)
        dfs(index + 1, sum+numbers[index]);
        dfs(index + 1, sum-numbers[index]);        
    }
    
    // 0번째 인덱스부터 아무것도 더해지지 않은 상태에서 dfs 시작
    dfs(0,0);
    
    return answer;
}