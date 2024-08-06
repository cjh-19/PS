function solution(rectangle, characterX, characterY, itemX, itemY) {
    /* 설계 */
    // 테두리를 1, 테두리 내부를 2, 테두리 바깥쪽을 0으로 지정
    // 1을 따라서 탐색
    // 이때, 1칸 차이나는 경우는 1사이에 0이 생기지 않으므로 모든 길이를 2배로 해주어 예외를 처리
    // -> 좌표 제한사항이 1~50 이므로 배열 크기를 넉넉하게 110을 설정
    
    /* 풀이 */
    // 1. 좌표를 2배로 늘리기
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    // 사각형의 좌표도 2배로 늘리기
    let doubleRec = rectangle.map(rec => rec.map(point => point * 2));
    
    // 2. 방향 설정 - 상, 하, 좌, 우
    let dx = [-1, 1, 0, 0];
    let dy = [0, 0, -1, 1];
    
    // 3. 좌표판 생성
    let board = Array.from(Array(110), () => new Array(110).fill(0));
    
    // 4. 테두리를 1, 테두리 내부를 2, 테두리 바깥쪽을 0으로 지정
    doubleRec.forEach(([x1, y1, x2, y2]) => {
        // x1부터 x2까지
        for(let i = x1; i <= x2; i++){
            // y1부터 y2까지
            for(let j = y1; j <= y2; j++){
                // i와 j가 테두리라면
                if(i === x1 || i === x2 || j === y1 || j === y2){
                    // 테두리가 내부에 있으면 1이 아니라 2여야 하기때문에 조건문
                    if(board[i][j] === 0) board[i][j] = 1;
                }
                else{
                    board[i][j] = 2;
                }
            }
        }
    });
    
    // 5. dfs로 거리 탐색
    // 방문 체크
    let visited = Array.from(Array(110), () => new Array(110).fill(false));
    let count = Infinity;
    
    const dfs = (x, y, cnt) => {
        // 도착했다면 이동횟수 업데이트 후 반환
        if(x === itemX && y === itemY){
            count = Math.min(count, cnt/2);
            return;
        }
        
        // 4가지 방향 탐색해서 방문x & 값이 1인 곳 방문
        for(let i=0; i<4; i++){
            let moveX = x + dx[i];
            let moveY = y + dy[i];
            if(board[moveX][moveY] === 1 && !visited[moveX][moveY]){
                visited[moveX][moveY] = true;
                dfs(moveX, moveY, cnt + 1);
                visited[moveX][moveY] = false;
            }
        }
    };
    
    dfs(characterX, characterY, 0);
    
    return count;
}