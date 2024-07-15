#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 작업시간이 짧은 순서로 정렬
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, timer = 0, cnt = jobs.size();
    // jobs 작업시간 오름차순 정렬
    sort(jobs.begin(), jobs.end(), cmp);

    // jobs를 하나씩 지워가며 소요시간(answer) 추가, timer은 현재시간
    // timer보다 jobs[i][0]이 작거나 같으면 작업할 수 있음
    while (!jobs.empty()) {
        for (int i = 0; i < jobs.size(); i++) {
            if (timer >= jobs[i][0]) {
                timer += jobs[i][1]; // 현재 시간 증가
                answer += (timer - jobs[i][0]); // 요청시간을 빼서 실제 실행 시간만 추가
                jobs.erase(jobs.begin() + i); // i 번째 인덱스 삭제
                break; // 하나 추가하면 for문 종료하고 새로 시작
            }
            if (i == jobs.size() - 1) // 아무것도 실행되지 않았다면 1초 증가
                timer++;
        }
    }

    return answer / cnt;
}