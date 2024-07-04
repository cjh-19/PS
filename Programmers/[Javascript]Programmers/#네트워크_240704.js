// 첫 컴퓨터부터 시작하여 마지막 컴퓨터까지 반복
// 한 네트워크에 있는 컴퓨터를 모두 방문
// 한 네트워크에 있는 모든 컴퓨터는 방문한 상태
// 이후 다른 컴퓨터를 확인할 때, 방문을 안했다면 새로운 네트워크 생성
// dfs로 구현

function solution(n, computers) {
    let netCount = 0; // 네트워크 개수
    const visited = new Array(computers.length).fill(false); // 방문 체크 부울린
    
    function dfs(i) {
        visited[i] = true; // 방문 체크
        for(let j=0; j<computers.length; j++){
            // i와 j가 연결되어있고 한번도 방문되지 않은 곳이라면 방문(dfs)
            if(computers[i][j] === 1 && visited[j] === false)
                dfs(j);
        }
    }
    
    for(let i=0; i<computers.length; i++){
        if(visited[i] === false){
            dfs(i);
            netCount++;
        }
    }
    return netCount;
}