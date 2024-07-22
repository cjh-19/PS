#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> info[101]; // 송전탑(노드) 그래프

// 한쪽 그래프의 노드 개수
int bfs(int n1, int n2) {
    int count = 1; // 반환할 노드 개수(첫 시작 노드 담고 시작)
    queue<int> q; // 노드를 담을 큐
    bool visited[101] = { false, }; // 방문 체크

    // 잘린 엣지의 양쪽 노드는 방문체크
    visited[n1] = true;
    visited[n2] = true;
    q.push(n1); // 잘린 엣지의 왼쪽 노드 추가

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // 제거 후 연결된 노드가 있고, 미방문이라면 q에 추가
        for (int i = 0; i < info[node].size(); i++) {
            int connectnode = info[node][i];
            if (visited[connectnode]) continue;

            // 큐에 추가
            q.push(connectnode);
            count++;
            visited[connectnode] = true;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 200;

    // bfs 완전 탐색으로 해결

    // 그래프 생성 (ex. wire[0]에 wire[1]연결, wire[1]에 wire[0]연결)
    for (auto wire : wires) {
        info[wire[0]].push_back(wire[1]);
        info[wire[1]].push_back(wire[0]);
    }

    // 끊어지는 엣지를 기준으로 각 그래프의 노드를 세고, 개수 비교
    for (auto wire : wires) {
        int n1 = wire[0];
        int n2 = wire[1];

        answer = min(answer, abs(n - bfs(n1, n2) * 2));
    }

    return answer;
}