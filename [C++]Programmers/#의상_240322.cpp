#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    // 각 의상 종류 개수 세기
    for (auto i : clothes) {
        m[i[1]]++;
    }

    // 경우의 수 세기
    for (auto i : m) {
        answer *= i.second + 1; // 의상을 선택하지 않는 경우의 수 +1 추가
    }

    // 아무것도 입지 않는 경우 제외
    answer--;

    return answer;
}

/*
#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int cloth_count = 1;
    unordered_map<string, int> map;
    for (auto i : clothes) {
        if (map.find(i[1]) == map.end()) // 옷의 종류 저장되지 않았다면
            map[i[1]] = 2; // 해당하는 종류의 경우의 수 2로 초기화(입지않는 경우 포함)
        else
            map[i[1]]++; // 옷이 하나 더 있을 때, 경우의 수 1 증가
    }
    for (auto i : map) {
        cloth_count *= i.second; // 각 종류마다 경우의 수 곱셈
    }
    return cloth_count - 1; // 아무것도 입지 않는 경우의 수 빼고 계산
}
*/