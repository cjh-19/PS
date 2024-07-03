function solution(phone_book) {
    // phone_book을 숫자순이 아닌 문자열 순으로 오름차순 정렬
    // 이렇게 되면, 12, 123, 88 순으로 정렬되어 바로 앞 숫자와만 비교하면 됨
    phone_book.sort();
    
    for(let i=0; i<phone_book.length - 1; i++){
        // 현재 인덱스의 값과 바로 뒤의 인덱스 요소의 부분 문자열과 같다면 false
        if(phone_book[i] === phone_book[i+1].substring(0, phone_book[i].length)){
            return false;
        }
    }
    
    return true;
}