function solution(k, tangerine) {
    // map으로 키의 값 증가하며 추가
    let map = new Map();
    for(let i=0; i<tangerine.length; i++){
        // 귤 종류 처음 추가할 때
        if(map.get(tangerine[i]) === undefined){
            map.set(tangerine[i], 1);
            continue;
        }
        // 귤 개수 1 증가
        map.set(tangerine[i], map.get(tangerine[i]) + 1);
    }
    // map 배열로 만들어서 정렬
    let arr = Array.from(map);
    arr.sort((a,b) => b[1] - a[1]);
    
    // k를 만족할때 까지 반복
    let count = 0; // 종류 개수
    let sum = 0; // 귤 개수
    for(let i=0; i<arr.length; i++){
        sum += arr[i][1]; // 귤 종류의 총 개수 추가
        count++; // 귤 종류 추가
        if(sum >= k) break; // 귤 개수 다 채웠다면
    }
    
    return count;
}