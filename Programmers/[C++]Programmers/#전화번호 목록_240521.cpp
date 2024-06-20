// 1. unordered_map 해시를 이용한 구현 방법
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> map;

    // 각 번호마다 hash를 만듦
    for (auto i : phone_book) {
        if (map.find(i) == map.end())
            map[i] = 1;
    }

    // 각 번호의 부분 문자열을 추출해서 접두사가 되는 문자가 있는지 확인
    for (auto i : map) {
        for (int j = 1; j < i.first.size(); j++) {
            string number = i.first.substr(0, j);
            if (map.find(number) != map.end())
                return false;
        }
    }

    return true;
}


// 2. 정렬과 for 루프를 이용한 구현 방법
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    // 숫자순이 아니라 "사전순"으로 정렬됨
    // i번째와 i+2번째를 비교할 필요가 없음
    // i번재 문자열이 i+2번째 문자열의 접두사라면 i+1번째는 i+2번째의 접두사기 때문임
    // substr(n,k): 문자열을 n번 인덱스부터 k개만큼 자름
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
            return false;
    }

    return true;
}
*/