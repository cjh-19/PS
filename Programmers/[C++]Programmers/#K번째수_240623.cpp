// 2차 풀이
// vector을 .begin()을 이용하여 자르는 것과 담는 것을 동시에 진행하여 최적화
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // command 개수만큼 반복 (return 배열 요소 개수)
    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0], // 시작점
            end = commands[i][1], // 끝점
            point = commands[i][2];

        // i-1부터 j까지 tmp에 담기
        vector<int> tmp(array.begin() + start - 1, array.begin() + end);

        // tmp 정렬
        sort(tmp.begin(), tmp.end());

        // k번째 숫자 추가
        answer.push_back(tmp[point - 1]);
    }

    return answer;
}


// 1차 풀이
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // command 개수만큼 반복 (return 배열 요소 개수)
    for (int i = 0; i < commands.size(); i++) {
        // 자른 숫자 담을 벡터
        vector<int> tmp;
        // i-1부터 j까지 tmp에 담기
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            tmp.push_back(array[j]);
        }
        // tmp 정렬
        sort(tmp.begin(), tmp.end());
        // k번째 숫자 추가
        answer.push_back(tmp[commands[i][2] - 1]);
    }

    return answer;
}
*/