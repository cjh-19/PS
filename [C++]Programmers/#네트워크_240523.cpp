#include <string>
#include <vector>

using namespace std;

int netSize = 0;
vector<bool> visited;

// dfs -> �湮 üũ(��Ʈ��ũ�� �������ִ� ��)
// dfs�� �����Ų ��ǻ���� ��Ʈ��ũ�� ���� ��ǻ�͸� ã�� ��
void dfs(int x, int n, vector<vector<int>> computers) {
    visited[x] = true; // �湮 üũ

    // x�� computers�� i�� ��ǻ�Ͱ� ����ƴ���, ���� �湮���� ���� ��ǻ������ üũ�ϰ� (n���� ��ǻ�� ��� üũ)
    // �׷��ٸ� dfs �����ؼ� �湮ǥ��
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
        if (visited[i] == false) { // �湮 ���ߴٸ� (��Ʈ��ũ�� ���Ե��� ���� ��ǻ��)
            // dfs ���� Ƚ��: ��Ʈ��ũ ���� (visited üũ)
            dfs(i, n, computers);
            netSize++;
        }
    }

    return netSize;
}