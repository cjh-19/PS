#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<char>> map(5, vector<char>(5));
queue<pair<int, int>> userQ;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 모든 유저가 거리두기를 지키고 있는지 체크
bool bfs() {
    bool visited[5][5] = { false };

    while (!userQ.empty()) {
        int x = userQ.front().first;
        int y = userQ.front().second;
        userQ.pop();
        visited[x][y] = true;

        queue<pair<int, int>> q;
        q.push({ x, y });
        while (!q.empty()) {
            // 다음 탐색할 좌표
            int xpos = q.front().first;
            int ypos = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = xpos + dx[i];
                int ny = ypos + dy[i];

                if (abs(x - nx) + abs(y - ny) > 2) continue;

                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && map[nx][ny] != 'X' && !visited[nx][ny]) {
                    if (map[nx][ny] == 'P') return false;

                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        userQ = queue<pair<int, int>>(); // 유저 큐 초기화
        for (int j = 0; j < 5; j++) {
            string str = places[i][j];
            for (int k = 0; k < 5; k++) { // 각 문자열 순회
                map[j][k] = str[k];
                if (str[k] == 'P') userQ.push({ j, k }); // 유저 좌표 큐에 저장
            }
        }
        // map, 큐 입력 끝나면 유저가 거리두기를 지키고 있는지 체크
        if (bfs()) answer.push_back(1); // 지키면 1
        else answer.push_back(0);
    }

    return answer;
}