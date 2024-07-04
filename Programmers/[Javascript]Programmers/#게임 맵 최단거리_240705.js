// 상하좌우 - 캐릭터의 이동방향을 알려줄 변수
const dx = [-1, 1, 0, 0]; // 상하
const dy = [0, 0, -1, 1]; // 좌우

function solution(maps) {
    // 해당 좌표까지의 최소 이동 횟수를 저장하는 배열
    let minCount = Array.from(Array(maps.length), () => Array(maps[0].length).fill(0));
    // 방문 체크
    let visited = Array.from(Array(maps.length), () => Array(maps[0].length).fill(false));
    minCount[0][0] = 1; // 처음 위치 값 1
    visited[0][0] = true; // 처음 자신 위치 true
    
    // 첫 위치: (1,1)
    // 상대 위치(maps.length, maps[0].length) = (n,m)
    
    let queue = [[0,0]]; // 현재 위치를 담을 큐
    
    // 최단거리를 못찾는 경우가 있으므로 dfs는 안되고, bfs로 탐색
    // 큐가 비어있지 않으면 반복
    while(queue.length > 0){
        // 가장 마지막에 담은 위치 빼고 다음 위치를 담는 방식으로 진행
        let x = queue[0][0];
        let y = queue[0][1];
        queue.splice(0,1);
        // or let [x,y] = queue.shift();
        
        for(let k=0; k<4; k++){
            // 다음 이동 좌표 계산
            let nx = x + dx[k];
            let ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx < maps.length && ny < maps[0].length && maps[nx][ny] === 1 && visited[nx][ny] === false){
                visited[nx][ny] = true; // 다음 위치 방문 표시
                 // 이동한 위치에 '이전 이동값 + 1'로 추가
                minCount[nx][ny] = minCount[x][y] + 1;
                queue.push([nx, ny]); // 이동한 위치에서 다음 위치로 가기위해 큐에 추가
            }    
        }
    }
    
    if(minCount[maps.length - 1][maps[0].length - 1] === 0)
        return -1;
    
    return minCount[maps.length - 1][maps[0].length - 1];
}