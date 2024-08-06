function solution(ability) {
    // 방문 체크
    let visited = new Array(ability.length).fill(false);
    let max = 0;

    // dfs로 최대값 탐색
    // sum은 합계, count는 대표를 정한 종목 수
    const dfs = (sum, count) => {
        if(count === ability[0].length){
            max = Math.max(max, sum);
            return;
        }

        for(let i=0; i<ability.length; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(sum + ability[i][count], count + 1);
                visited[i] = false;
            }
        }
    };
    
    dfs(0, 0);
    return max;
}