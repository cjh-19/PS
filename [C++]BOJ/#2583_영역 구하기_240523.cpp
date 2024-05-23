#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M; // ���� ����
int N; // ���� ����
int K; // ���� ����

vector<vector<int>> map; // ����
vector<vector<bool>> visited; // �湮 ����

int dx[4] = { -1, 1, 0, 0 }; // �� �� �� ��
int dy[4] = { 0, 0, -1, 1 }; // �� �� �� ��

// ������ ũ�⸦ ���ϴ� dfs
int dfs(int x, int y) {
	visited[x][y] = true;
	int areasize = 1; // ���� ������ ũ��

	// �����¿� Ž��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; // �� ��ȭ��
		int ny = y + dy[i]; // �� ��ȭ��

		// �̵��� ��ǥ�� Ž���� �� �ִ� ������ Ȯ��
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == 0 && visited[nx][ny] == false) {
			// Ž���� �� �ִٸ� ���� ���� ������ dfs�� areasize�� �߰�
			areasize += dfs(nx, ny);
		}
	}
	return areasize;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	// ���� �ʱ�ȭ
	map.resize(M, vector<int>(N, 0));
	visited.resize(M, vector<bool>(N, false));

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2; // ���� �Ʒ�, ������ ��
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				map[j][k] = 1;
			}
		}
	}

	// ex)
	// map[][]
	// 0 2 4 4
	// x(��, ����)�� 0~3 map[][�̺κ�]
	// y(��, ����)�� 2~3 map[�̺κ�][]

	// ������ ũ�� ����
	vector<int> areas;

	// �湮�ϴ� ���� 0���� �湮���� �ʾҴ��� Ȯ��
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				// ������ ũ�⸦ ���ϴ� dfs
				int areasize = dfs(i, j);
				areas.push_back(areasize);
			}
		}
	}

	// ������������ ����
	sort(areas.begin(), areas.end());

	// ���
	cout << areas.size() << "\n";
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << " ";
	}
	cout << "\n";

	return 0;
}