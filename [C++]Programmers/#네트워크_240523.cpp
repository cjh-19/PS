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
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 영역 개수 추가 dfs
void dfs(int x, int y, int n, vector<vector<int>> computers) {
    visited[x][y] = true;

    // 상하좌우 체크
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 영역확장 가능한지 확인
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && computers[nx][ny] && visited[nx][ny] == false)
            dfs(nx, ny, n, computers);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.resize(n, vector<bool>(n, false)); // n*n과 false로 초기화

    // computers[x][y]의 값이 1이고 방문안했는지 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && visited[i][j] == false) {
                // dfs로 영역 확장(visited 체크)
                dfs(i, j, n, computers);
                netSize++;
            }
        }
    }

    return netSize;
}