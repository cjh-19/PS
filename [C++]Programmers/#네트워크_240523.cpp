#include <string>
#include <vector>

using namespace std;

int netSize = 0;
vector<bool> visited;

// dfs -> 방문 체크(네트워크에 포함해주는 것)
// dfs를 실행시킨 컴퓨터의 네트워크에 들어가는 컴퓨터를 찾는 것
void dfs(int x, int n, vector<vector<int>> computers) {
    visited[x] = true; // 방문 체크

    // x번 computers와 i번 컴퓨터가 연결됐는지, 아직 방문하지 않은 컴퓨터인지 체크하고 (n개의 컴퓨터 모두 체크)
    // 그렇다면 dfs 실행해서 방문표시
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
        if (visited[i] == false) { // 방문 안했다면 (네트워크에 포함되지 않은 컴퓨터)
            // dfs 실행 횟수: 네트워크 개수 (visited 체크)
            dfs(i, n, computers);
            netSize++;
        }
    }

    return netSize;
}