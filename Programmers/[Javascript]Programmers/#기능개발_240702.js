function solution(progresses, speeds) {
    var answer = [];
    
    // progresses 배열이 빌때까지 반복
    while(progresses.length > 0){
        let count = 0; // 각 배포때 배포되는 기능 개수
        for(let i=0; progresses.length; i++){
            // 진행률이 100% 미만이라면
            if(progresses[i] < 100)
                progresses[i] += speeds[i]; // 하루 진행률 추가
        }
        // 하루가 지나면 붙어있는 기능 배포(삭제 및 count 증가)
        while(progresses[0] >= 100){
            // 0번째 기능 및 속도 삭제 -> (반복) 붙어있는 진행 완료된 기능 모두 삭제
            progresses.splice(0,1);
            speeds.splice(0,1);
            count++;
        }
        answer.push(count);
    }
    return answer;
}