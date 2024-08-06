function solution(queries) {    
    var answer = [];
    let Rr_wandu = ["RR", "Rr", "Rr", "rr"];

    // 완두콩 찾는 함수
    // 반환값은 ["RR", "Rr", "Rr", "rr"] 중 하나
    function findGene(gene, index) {
        // 1세대인 경우
        if(gene === 1) return "Rr";

        // 2세대 이상인 경우
        // 부모 유전자 찾기
        let parentindex = Math.floor((index - 1) / 4) + 1; // 부모 유전자 순번
        let parentWandu = findGene(gene - 1, parentindex);

        if(parentWandu === "RR") {
            return "RR";
        }
        else if(parentWandu === "rr"){
            return "rr";
        }
        else{
            return Rr_wandu[(index - 1) % 4];
        }
    }

    queries.forEach((query) => {
        let gene = query[0];
        let idx = query[1];
        answer.push(findGene(gene, idx));
    });

    return answer;
}