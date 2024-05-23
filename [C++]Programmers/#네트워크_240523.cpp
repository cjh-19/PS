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
vector<bool> visited;

// ���� ���� �߰� dfs
void dfs(int x, int n, vector<vector<int>> computers) {
    visited[x] = true;

    // �����¿� üũ
    for (int i = 0; i < n; i++) {

        if (computers[x][i] == 1 && visited[i] == false) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.resize(n, false); // n, false�� �ʱ�ȭ

    // �湮���ߴ��� Ȯ��
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            // dfs�� ���� Ȯ��(visited üũ)
            dfs(i, n, computers);
            netSize++;
        }
    }

    return netSize;
}