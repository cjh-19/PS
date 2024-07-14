#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    // prices i번째와 뒤의 모든 가격을 비교
    for (int i = 0; i < prices.size(); i++) {
        // i번째 가격 초기 시간 추가
        answer.push_back(0);

        for (int j = i + 1; j < prices.size(); j++) {
            answer[i]++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
    }

    return answer;
}