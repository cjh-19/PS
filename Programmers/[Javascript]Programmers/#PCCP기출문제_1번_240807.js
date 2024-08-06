function solution(bandage, health, attacks) {
    // 최대 체력, 붕대 시전 시간, 초당 회복량, 추가회복량
    const [max, healTime, healsec, healadd] = [health, bandage[0], bandage[1], bandage[2]];

    let currentTime = 0; // 시작 시간

    // 공격받은 시간 기준으로 업데이트
    for(let i=0; i<attacks.length; i++){
        // 공격 받기 전까지 붕대감은 시간
        let time = attacks[i][0] - 1 - currentTime;

        health += time * healsec; // 초당 회복량
        if(time >= healTime) health += healadd * Math.floor(time / healTime); // 추가 회복량
        if(health > max) health = max; // 최대 체력

        // 공격받은 후 체력
        health -= attacks[i][1];
        if(health <= 0) return -1;

        // 현재시간 업데이트
        currentTime += time + 1;
    }

    return health;
}