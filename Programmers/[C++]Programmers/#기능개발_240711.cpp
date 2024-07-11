#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // i 기능 배포하는 것으로 반복
    for (int i = 0; i < progresses.size();) {
        // i 기능이 100%가 될때까지 반복
        while (progresses[i] < 100) {
            for (int j = i; j < progresses.size(); j++) {
                progresses[j] += speeds[j];
            }
        }
        int count = 0;
        for (int j = i; j < progresses.size(); j++) {
            if (progresses[j] < 100) // 기능 완성이 안되면 탈출
                break;
            count++;
        }
        i += count;
        answer.push_back(count);
    }

    return answer;
}