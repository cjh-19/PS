// 방향을 나타내는 알파벳 -> 사전순으로 0~3 매핑
const dir = {
    0: "d", // 아래쪽
    1: "l", // 왼쪽
    2: "r", // 오른쪽
    3: "u", // 위쪽
};

function solution(n, m, x, y, r, c, k) {
    let result = "";
    // 방향 - 하 -> 좌 -> 우 -> 상 순으로 해야 dir과 맞출 수 있음
    let dx = [1, 0, 0, -1];
    let dy = [0, -1, 1, 0];
    
    // 목표점까지의 최소거리가 k 초과일 경우
    // (k - minDis)가 홀수일 경우 (ex. 최소거리 + 1, 최소거리 + 3 이면 도착점으로 다시 돌아올 수 없음)
    //impossible
    let minDis = Math.abs(x-r) + Math.abs(y-c);
    if(minDis > k || (k - minDis) % 2 != 0) return "impossible";
    
    // 재귀함수로 경로 탐색
    let start = [x-1, y-1]; // 시작 위치
    
    // current: 현재 위치, stack 시작위치에서 현재위치까지 경로(알파벳)
    const move = (current, stack) => {
        if(result.length > 0) return; // 경로를 찾은 경우
        if(stack.length > k) return; // 도착전에 이동거리가 k를 넘은 경우
        
        let [nx, ny] = current; // 현재 위치
        if(Math.abs(nx - (r - 1)) + Math.abs(ny - (c - 1)) > k - stack.length) return;
        
        // 도달했을때 result에 저장
        if(stack.length === k && nx === r-1 && ny === c-1){
            result = stack;
            return;
        }
        
        // 다음 위치로 재귀함수
        for(let i=0; i<4; i++){
            let lx = nx + dx[i];
            let ly = ny + dy[i];
            
            // i=0: dir[0]이 아래쪽 ... dx,dy = 0,1
            if(lx >= 0 && lx < n && ly >=0 && ly < m) move([lx, ly], stack + dir[i]);
        }
    };
    move(start, "");
    return result;
}