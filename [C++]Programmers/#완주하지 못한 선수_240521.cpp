// 해시 알고리즘 사용 방법 - unordered_map
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> map;

    for (auto i : participant) {
        // participant[i]가 map에 저장되어있지 않으면 저장하고 값 1 설정
        if (map.find(i) == map.end())
            map[i] = 1;
        else // 존재하면 1 증가
            map[i]++;
    }
    for (auto i : completion) {
        map[i]--; // 완주한 사람 map에서 제외
    }
    for (auto i : map) {
        if (i.second != 0) // 완주하지 못한 사람
            return i.first;
    }
}

// 구현 방법

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i]; // 다른 요소를 발견하자마자 반환해야함
    }

    return participant[participant.size() - 1];
}
*/