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