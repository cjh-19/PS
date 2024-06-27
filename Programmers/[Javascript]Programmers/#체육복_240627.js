function solution(n, lost, reserve) {    
    // 여벌옷을 가진 학생인 도난 당한 경우의 수 필터링
    let lost_person = lost.filter( i => !reserve.includes(i)).sort((a,b) => a-b);
    let reserve_person = reserve.filter( i => !lost.includes(i)).sort((a,b) => a-b);
    
    // lost의 앞 뒤 번호가 reserve에 있으면
    // lost 해당번호와 reserve 해당번호 삭제
    for(let i=0; i<reserve_person.length; i++){
        // 앞 번호가 있다면, lost_person 재필터링
        if(lost_person.includes(reserve_person[i] - 1)){
            lost_person = lost_person.filter(j => j != reserve_person[i] - 1);
        }
        // 뒤 번호가 있다면, lost_person 재필터링
        else if(lost_person.includes(reserve_person[i] + 1)){
            lost_person = lost_person.filter(j => j != reserve_person[i] + 1);
        }
    }
    
    // n - lost.length 반환
    return n - lost_person.length;
}