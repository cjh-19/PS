function solution(begin, target, words) {
    var answer = Infinity;
    let check = false;
    // word에 target이 없는 경우
    for(let i=0; i<words.length; i++){
        if(words[i] === target){
            check = true;
            break;
        }
    }
    if(!check) return 0;
    
    // dfs로 백트래킹하며 탐색
    let visited = new Array(words.length).fill(false);
    const dfs = (current, idx) => {
        if(idx > words.length - 1) return;
        // 종료 조건
        if(current === target){
            answer = Math.min(answer, idx);
            return;
        }
        
        // 재귀
        for(let i=0; i<words.length; i++){
            // 재귀 못하는 단어 조건
            if(visited[i]) continue;
            let diff = 0;
            for(let j=0; j<words[i].length; j++){
                if(words[i][j] != current[j]) diff++;
            }
            if(diff != 1) continue;
            
            // dfs 실행
            visited[i] = true; // 방문
            dfs(words[i], idx + 1);
            visited[i] = false; // 백트래킹
        }
    };
    dfs(begin, 0);
    return answer;
}