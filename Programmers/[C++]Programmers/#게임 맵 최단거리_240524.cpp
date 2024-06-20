#include<vector>
#include<queue>

using namespace std;

//�����¿츦 Ȯ���ؾ� ��
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m; // ���� ���� ��ġ
vector<vector<int>> min_dist; // ������ �ִܰŸ� min_dist[0][0] = 1�̴�.
vector<vector<bool>> visited;
queue<pair<int, int>> q; // ���� ��ġ�� ���� ť

// �ִܰŸ� Ž�� -> ���� ���� ã������ ��ΰ� �ִܰŸ�
void bfs(vector<vector<int> > maps) {
    min_dist.resize(n, vector<int>(m, 0)); // ������κ��� �ش� �������� �ִ� �Ÿ�
    visited.resize(n, vector<bool>(m, false)); // n*m ������, false�� �ʱ�ȭ

    min_dist[0][0] = 1; // ����������� �Ÿ��� 1
    visited[0][0] = true; // �ش���ġ �湮
    q.push({ 0, 0 }); // ���� ��ġ ť�� ����

    // ť�� ���������� �ݺ� (�ִܰŸ� ���Ҷ�����)
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); // ������ġ �����ϰ� ť���� ����

        // �����¿�� �� �� �ִ� ��(���)�� bfs
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Ȯ���� �� �ִ� ��ġ���� Ȯ���ϰ�, �湮���� ���� ������ Ȯ��
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == false) {
                // Ž�� �����ϴٸ� ť�� �߰��ϰ� �湮 ǥ��
                q.push({ nx, ny });
                visited[nx][ny] = true;
                min_dist[nx][ny] = min_dist[x][y] + 1; // ���� ��ġ������ �ִ� �Ÿ��� 1����
            }
        }
    }

}

int solution(vector<vector<int> > maps)
{
    // ���� ���� ��ġ ����
    n = maps.size();
    m = maps[0].size();

    bfs(maps);

    // �� �������� ������ �� ���ٸ� -1 ��ȯ
    if (min_dist[n - 1][m - 1] == 0) {
        return -1;
    }

    return min_dist[n - 1][m - 1];
}