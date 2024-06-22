// 2차 풀이
// slice를 사용하여 코드를 줄임
function solution(array, commands) {
    var answer = [];
    
    // return 배열 개수만큼 반복
    for(let i=0; i<commands.length; i++){
        // i,j,k 값 가져오기
        let [start, end, point] = commands[i];
        
        // i-1부터 j까지 자르기
        let tmp = array.slice(start - 1, end);
        
        // tmp 숫자 정렬
        tmp.sort((a,b) => a - b);
        // k번째 숫자 answer에 추가
        answer.push(tmp[point - 1]);
    }
    
    return answer;
}


// 1차 풀이
/*
function solution(array, commands) {
    var answer = [];
    
    // return 배열 개수만큼 반복
    for(let i=0; i<commands.length; i++){
        // 자른 숫자 배열
        let tmp = [];
        
        // i-1부터 j까지 자르기
        for(let j=commands[i][0] - 1; j<commands[i][1]; j++){
            tmp.push(array[j]);
        }
        // tmp 숫자 정렬
        tmp.sort((a,b) => a - b);
        // k번째 숫자 answer에 추가
        answer.push(tmp[commands[i][2] - 1]);
    }
    
    return answer;
}
*/