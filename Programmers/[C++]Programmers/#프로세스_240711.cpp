#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; // 반환할 location 실행 순번
    queue<int> q; // 우선순위 인덱스 순서 그대로 담을 큐
    priority_queue<int> pq; // 우선순위 내림차순 정렬 우선순위 큐
    for (int i = 0; i < priorities.size(); i++) {
        q.push(priorities[i]);
        pq.push(priorities[i]);
    }

    // location 인덱스 반환 될때까지 반복
    while (1) {
        // 큐의 첫번째 인덱스와 가장 높은 우선순위가 같은 경우
        if (q.front() == pq.top()) {
            // answer 추가하고 두 큐에서 값 제거
            q.pop();
            pq.pop();
            answer++;
            if (location == 0) return answer; // location이 맨 앞 인덱스라면 반환
            location--; // 아니면 1 감소 -> 삭제했으므로 당기기
        }
        else { // 같지 않다면 q 맨 앞 원소를 맨 뒤로 보내고 location 위치 변경
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            location--;
            if (location < 0) location = q.size() - 1; // 위치가 맨앞이었다면 맨뒤로 변경
        }
    }

    return answer;
}