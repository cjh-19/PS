function solution(input_string) {
    var answer = new Set();
    for(let k = 0; k<input_string.length-1; k++){
        for(let i = k+2; i<input_string.length; i++){
            if(input_string[k] != input_string[k+1] && input_string[k] === input_string[i]){
                answer.add(input_string[k]);
            }
        }
    }
    if(answer.size === 0) return "N";
    //answer.sort((a,b) => a-b);
    let result = "";
    let numset = new Array();
    answer.forEach((w) => {
        if(w != undefined) numset.push(w);
    });
    numset.sort();
    for(let i=0; i<numset.length; i++){
        result += numset[i];
    }

    return result;
}