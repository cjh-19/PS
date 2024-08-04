function solution(n, cores) {
    if(n<=cores.length) return n; // 작업수가 코어수보다 작은 경우 작업수 = 마지막 코어 번호
    
    let min = Math.min(...cores); // 가장 짧은 작업 처리 시간을 가진 코어
    let max = min * n; // 가장 빨리처리하는 코어가 모든 작업을 처리하는 경우(최악의 경우)
    let mid; // 중앙값
    let work; // 각 코어가 처리할 수 있는 작업의 수
    
    // 마지막 작업을 처리하는데 걸리는 시간 계산
    while(min <= max){
        mid = Math.floor((min + max) / 2); // min과 max의 중간값
        work = cores.length; // 처음에는 모든 코어가 작업하므로, 작업 수를 코어의 수로 초기화
        
        // 각 코어가 mid 시간 동안 처리할 수 있는 작업의 수를 계산하여 합산
        for(let i=0; i<cores.length; i++){
            // mid / cores[i]는 mid 시간동안 i번째 코어가 처리할 수 있는 작업 수
            // 모든 코어가 처리할 수 있는 작업수를 work에 합산
            work += Math.floor(mid/cores[i]);
        }
        
        // 계산한 작업 수가 n보다 작으면 min을 mid+1로 업데이트
        // mid 시간 내에 모든 작업을 완료할 수 없다는 의미
        if (work < n) {
            min = mid + 1;
        }
        else { // 계산한 작업 수가 n보다 크거나 같으면, max를 mid-1로 업데이트
            // mid 내에 모든 작업을 완료할 수 있다는 의미
            max = mid - 1;
        }
    }
    // 탐색이 끝나면 min은 마지막 작업을 처리하는 데 필요한 최소 시간을 나타냄
    /*
    반복이 끝나는 시점에서 min은 다음을 보장
    1. min 시간 내에 n개의 작업 완료 가능
    2. min-1 시간 내에는 n개의 작업 완료 불가능
    즉, min은 정확히 n번째 작업이 완료되는 시간
    */
    
    // min - 1 시점에서 처리한 작업 수 계산 (마지막 작업 직전)
    work = cores.length; // 시작할 때는 모든 코어가 작업
    let prevTime = min - 1;
    for(let i=0; i<cores.length; i++){
        work += Math.floor(prevTime/cores[i]);
    }
    
    // min 시점에서 n번째 작업을 처리하는 코어 탐색
    for(let i=0; i<cores.length; i++){
        // min의 약수가 되는 첫 cores가 n번째 작업을 수행
        if(min % cores[i] === 0) work++;
        if(work === n) return i + 1; // 코어는 1번부터 시작
    }
}