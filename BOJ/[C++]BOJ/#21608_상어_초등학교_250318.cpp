#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;
vector<pair<int, vector<int>>> stu;
int board[21][21]; // ���� �¼�

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // �����ϴ� �¼��� ���� ��
	else if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // ���ڸ��� ���� ��
	else if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // ���� ���� ��
	return get<3>(a) < get<3>(b); // ���� ���� ��
}

// �л� �¼� ����
void select() {
	// ù��° �л��� (2,2) ����
	board[2][2] = stu[0].first;

	// �� �л��� ����, 1 -> 2 -> 3 �� ������ �����ϴ´�� �¼� ��ġ
	for (int i = 1; i < stu.size(); i++) {
		vector<tuple<int, int, int, int>> xy; // (�����ϴ� �л� ��, ��ĭ ��, ��, ��)
		// 1. ����ĭ�� �����ϴ� �л��� ���� ���� ��
		// �ش� ������ �ִ��� 4 -> 4���� 0���� Ž���ϴµ�, ���� ������ ����
		// ���� 2�� �̵�

		unordered_map<int, int> m; // �����ϴ� �л�
		for (int j = 0; j < 4; j++) m.insert({ stu[i].second[j], 1 });

		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				// �л��� �ִٸ� �н�
				if (board[x][y] != 0) continue;

				int cnt = 0; // �����ϴ� �л� ��
				int emptyCnt = 0; // �ֺ� ��ĭ

				// ��ĭ���� Ž���ϸ� �ǹǷ� �׳� Ž��
				// ��
				if (x - 1 >= 1) {
					if (m.find(board[x - 1][y]) != m.end()) cnt++;
					if (board[x - 1][y] == 0) emptyCnt++;
				}
				// ��
				if (x + 1 <= N) {
					if (m.find(board[x + 1][y]) != m.end()) cnt++;
					if (board[x + 1][y] == 0) emptyCnt++;
				}
				// ��
				if (y - 1 >= 1) {
					if (m.find(board[x][y - 1]) != m.end()) cnt++;
					if (board[x][y - 1] == 0) emptyCnt++;
				}
				// ��
				if (y + 1 <= N) {
					if (m.find(board[x][y + 1]) != m.end()) cnt++;
					if (board[x][y + 1] == 0) emptyCnt++;
				}

				xy.push_back({ cnt, emptyCnt, x, y });
			}
		}

		// ���� 1(�����ϴ� �л� ��), 2(�ֺ� ��ĭ), 3(�� -> �� �ּ�)�� �´� �л� �ڸ� ��ġ
		sort(xy.begin(), xy.end(), cmp);
		board[get<2>(xy[0])][get<3>(xy[0])] = stu[i].first;
	}
}

long long satisfy() {
	long long result = 0;

	// �� ��ġ�� ���� ������ �����ϴ� �л��� ���� ���� �� �߰�
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			// �ش� ��ġ�� �л��� �����ϴ� �л� map
			unordered_map<int, int> m; // �����ϴ� �л�
			for (int i = 0; i < N * N; i++) {
				if (stu[i].first == board[x][y]) {
					for (int j = 0; j < 4; j++) m.insert({ stu[i].second[j], 1 });
					break;
				}
			}

			int cnt = 0; // �����ϴ� �л� ��

			// ��ĭ���� Ž���ϸ� �ǹǷ� �׳� Ž��
			// ��
			if (x - 1 >= 1) {
				if (m.find(board[x - 1][y]) != m.end()) cnt++;
			}
			// ��
			if (x + 1 <= N) {
				if (m.find(board[x + 1][y]) != m.end()) cnt++;
			}
			// ��
			if (y - 1 >= 1) {
				if (m.find(board[x][y - 1]) != m.end()) cnt++;
			}
			// ��
			if (y + 1 <= N) {
				if (m.find(board[x][y + 1]) != m.end()) cnt++;
			}

			// 10�� cnt-1 ������ŭ ���ϱ�
			result += (long long)pow(10, cnt - 1);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	// �л� ���� �Է�
	int n;
	for (int i = 0; i < N * N; i++) {
		cin >> n;
		vector<int> tmp;
		int t;
		for (int j = 0; j < 4; j++) {
			cin >> t;
			tmp.push_back(t);
		}
		stu.push_back({ n, tmp });
	}

	select();

	// ������ ���ϱ�
	cout << satisfy();

	return 0;
}