// 정렬과 for 루프를 이용한 구현 방법

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    // i번째와 i+2번째를 비교할 필요가 없음
    // i번재 문자열이 i+2번째 문자열의 접두사라면 i+1번째는 i+2번째의 접두사기 때문임
    // substr(n,k): 문자열을 n번 인덱스부터 k개만큼 자름
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
            return false;
    }

    return true;
}