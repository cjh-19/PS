#include <vector>
#include <limits.h>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int minsec = INT_MAX;

// ��0 ��1 ��2 ��3 -> �ð� ����
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool visited[101][101][4] = { false };

void bfs(vector<vector<int>> board) {
    queue<tuple<int, int, int, int>> q;
    q.push({ 0, 0, 0, 0 }); // ��ǥ(x,y), ����, �ð�
    q.push({ 0, 1, 2, 0 });
    visited[0][0][0] = true; // {0,0}���� ������ �̵� true;
    visited[0][1][2] = true; // {0,1}���� ���� �̵� true;

    while (!q.empty()) {
        auto [x1, y1, dir, sec] = q.front();
        q.pop();

        int x2 = x1 + dx[dir];
        int y2 = y1 + dy[dir];

        if ((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1)) {
            minsec = min(minsec, sec);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];

            // ���� �� �� üũ
            if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N) continue;
            if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N) continue;
            if (board[nx1][ny1] == 1 || board[nx2][ny2] == 1) continue;

            // �����¿� �̵�
            // ���� �̵����� �״�� �̵� ������ ���
            if (!visited[nx1][ny1][dir]) {
                visited[nx1][ny1][dir] = true;
                q.push({ nx1, ny1, dir, sec + 1 });
            }
            // ���� �̵����� �ݴ���� �̵� ������ ���
            if (!visited[nx2][ny2][(dir + 2) % 4]) {
                visited[nx2][ny2][(dir + 2) % 4] = true;
                q.push({ nx2, ny2, (dir + 2) % 4, sec + 1 });
            }

            // ȸ�� �̵�
            // ���� �̵� ��� ���� �̵� ���� ������ Ȯ�� -> ����1���� �¿�0����
            if ((dir + 1) % 2 == i % 2) { // dir + 1 -> ȸ�� ���� / i ���� ����
                // ���� ��� ȸ���Ϸ��� ������ ���ٸ� �̵�����
                // ���� �����δ� nx ny�� ��� ����(���� if���� ����߱� ����)
                if (!visited[x1][y1][i]) {
                    visited[x1][y1][i] = true;
                    q.push({ x1, y1, i, sec + 1 });
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    bfs(board);

    return minsec;
}