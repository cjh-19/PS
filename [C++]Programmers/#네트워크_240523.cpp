#include <string>
#include <vector>

using namespace std;
// 1 1 0
// 1 1 0
// 0 0 1

// 1 1 0
// 1 1 1
// 0 1 1

// -> 1�� ���� ����(�����¿� ����) : ��Ʈ��ũ ����

int netSize = 0;
vector<vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// ���� ���� �߰� dfs
void dfs(int x, int y, int n, vector<vector<int>> computers) {
    visited[x][y] = true;

    // �����¿� üũ
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ����Ȯ�� �������� Ȯ��
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && computers[nx][ny] && visited[nx][ny] == false)
            dfs(nx, ny, n, computers);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.resize(n, vector<bool>(n, false)); // n*n�� false�� �ʱ�ȭ

    // computers[x][y]�� ���� 1�̰� �湮���ߴ��� Ȯ��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && visited[i][j] == false) {
                // dfs�� ���� Ȯ��(visited üũ)
                dfs(i, j, n, computers);
                netSize++;
            }
        }
    }

    return netSize;
}