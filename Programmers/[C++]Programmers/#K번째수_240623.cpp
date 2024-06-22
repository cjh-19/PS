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