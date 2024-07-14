#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // priority_queue 우선순위 큐를 오름차순으로 정렬하여 해결
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < scoville.size(); i++) {
        Q.push(scoville[i]);
    }

    // Q에 하나만 남을때까지 반복
    while (Q.size() > 1) {
        // 모든 음식 스코빌지수 도달시
        if (Q.top() >= K)
            break;

        // 스코빌 지수 섞고 추가
        int Sc1 = Q.top();
        Q.pop();
        int Sc2 = Q.top();
        Q.pop();
        int newSc = Sc1 + Sc2 * 2;
        Q.push(newSc);
        answer++;
    }

    if (Q.top() < K)
        return -1;

    return answer;
}