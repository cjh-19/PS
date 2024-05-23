#include <string>
#include <vector>

using namespace std;
// 1 1 0
// 1 1 0
// 0 0 1

// 1 1 0
// 1 1 1
// 0 1 1

// -> 1의 영역 개수(상하좌우 연결) : 네트워크 개수

int netSize = 0;
vector<bool> visited;

// 영역 개수 추가 dfs
void dfs(int x, int n, vector<vector<int>> computers) {
    visited[x] = true;

    // 상하좌우 체크
    for (int i = 0; i < n; i++) {

        if (computers[x][i] == 1 && visited[i] == false) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.resize(n, false); // n, false로 초기화

    // 방문안했는지 확인
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            // dfs로 영역 확장(visited 체크)
            dfs(i, n, computers);
            netSize++;
        }
    }

    return netSize;
}