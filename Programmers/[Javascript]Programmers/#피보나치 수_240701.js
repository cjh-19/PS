function solution(n) {
    // 기존 재귀함수로 하면 시간 초과 발생
    // 수가 너무 커지는 이유도 있어보임
    let fiboNum = [0,1];
    for(let i=2; i<=n; i++){
        let sum = fiboNum[i-1] + fiboNum[i-2];
        fiboNum.push(sum % 1234567)
    }

    return fiboNum[n];
}

// 실패코드
// function fibo(n){
//     if(n <= 1)
//         return n;
//     return fibo(n-1) + fibo(n-2);
// }