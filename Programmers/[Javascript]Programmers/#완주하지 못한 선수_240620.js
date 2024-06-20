function solution(participant, completion) {
    let sortPar = participant.sort();
    let sortComp = completion.sort();
    let noComp = sortPar[sortPar.length - 1]; // 완주하지 못한 선수이름
    for(let i=0; i<sortComp.length; i++){
        if(sortPar[i] != sortComp[i]){
            noComp = sortPar[i];
            break;
        }
    }
    
    return noComp;
}