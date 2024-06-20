#include<vector>
#include<queue>

using namespace std;

//상하좌우를 확인해야 함
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m; // 상대방 진영 위치
vector<vector<int>> min_dist; // 적까지 최단거리 min_dist[0][0] = 1이다.
vector<vector<bool>> visited;
queue<pair<int, int>> q; // 현재 위치를 담을 큐

// 최단거리 탐색 -> 가장 먼저 찾아지는 경로가 최단거리
void bfs(vector<vector<int> > maps) {
    min_dist.resize(n, vector<int>(m, 0)); // 출발지로부터 해당 지점까지 최단 거리
    visited.resize(n, vector<bool>(m, false)); // n*m 사이즈, false로 초기화

    min_dist[0][0] = 1; // 출발점에서의 거리는 1
    visited[0][0] = true; // 해당위치 방문
    q.push({ 0, 0 }); // 현재 위치 큐에 저장

    // 큐가 비을때까지 반복 (최단거리 구할때까지)
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); // 현재위치 저장하고 큐에서 제거

        // 상하좌우로 갈 수 있는 곳(노드)로 bfs
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 확인할 수 있는 위치인지 확인하고, 방문하지 않은 곳인지 확인
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == false) {
                // 탐색 가능하다면 큐에 추가하고 방문 표시
                q.push({ nx, ny });
                visited[nx][ny] = true;
                min_dist[nx][ny] = min_dist[x][y] + 1; // 현재 위치까지의 최단 거리에 1증가
            }
        }
    }

}

int solution(vector<vector<int> > maps)
{
    // 상대방 진영 위치 설정
    n = maps.size();
    m = maps[0].size();

    bfs(maps);

    // 적 진영까지 도달할 수 없다면 -1 반환
    if (min_dist[n - 1][m - 1] == 0) {
        return -1;
    }

    return min_dist[n - 1][m - 1];
}