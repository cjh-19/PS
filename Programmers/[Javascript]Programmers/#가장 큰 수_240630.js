function solution(numbers) {
    numbers.sort((a,b) => Number(b.toString()+a.toString()) - Number(a.toString()+b.toString()));
    let Num = "";
    if(numbers[0] === 0){
        return "0";
    }
    else{
        for(let i=0; i<numbers.length; i++){
            Num += numbers[i];
        }   
    }
    return Num;
}