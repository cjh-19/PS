function solution(sizes) {
    // 각 명함의 크기르 내림차순으로 정렬
    for(let i=0; i<sizes.length; i++){
        sizes[i].sort((a,b) => b - a);
    }
    // 가로 최댓값과 세로 최댓값 탐색
    let xMax = 0, yMax = 0;
    for(let i=0; i<sizes.length; i++){
        xMax = Math.max(xMax, sizes[i][0]);
        yMax = Math.max(yMax, sizes[i][1]);
    }
    
    return xMax * yMax;
}