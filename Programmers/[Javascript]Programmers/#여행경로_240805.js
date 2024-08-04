function solution(tickets) {
    var answer = [];
    let path = []; // 누적 경로
    
    // 티켓 방문 체크
    let visited = new Array(tickets.length).fill(false);
    
    const dfs = (ticket, idx) => {
        path.push(ticket); // 현재까지의 경로 누적
        
        // 종료 조건
        if(idx === tickets.length){
            if(answer.length === 0 || answer.join('') > path.join('')) {
                answer = [...path];
                path.pop(); // 마지막 경로 제거 후 백트래킹
                return;
            }
        }
        
        for(let i=0; i<tickets.length; i++){
            // dfs 및 백트래킹
            if(!visited[i] && ticket === tickets[i][0]){
                visited[i] = true;
                dfs(tickets[i][1], idx + 1);
                visited[i] = false;
            }
        }
        path.pop() // dfs 종료후 방문을 false로 했으므로 제거
    };
    
    // dfs 시작 경로를 ICN으로만
    tickets.forEach((t, idx) => {
        if(t[0] === "ICN") {
            visited[idx] = true;
            path = ["ICN"];
            dfs(t[1], 1);
            visited[idx] = false;
        }
    });
    return answer;
}