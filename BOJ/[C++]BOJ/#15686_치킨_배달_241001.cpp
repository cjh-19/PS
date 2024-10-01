#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Chiken {
	int x;
	int y;
};

struct House {
	int x;
	int y;
};

int N, M;
vector<Chiken> ckmap; // 치킨 좌표 정보
vector<House> homemap; // 집 좌표 정보
int min_distance = INT_MAX;

void calculate(vector<Chiken> ck) {
	int sum = 0;
	for (int i = 0; i < homemap.size(); i++) {
		int mindis = INT_MAX;
		int hmx = homemap[i].x;
		int hmy = homemap[i].y;

		for (int j = 0; j < ck.size(); j++) {
			int ckx = ck[j].x;
			int cky = ck[j].y;

			int dis = abs(hmx - ckx) + abs(hmy - cky);
			mindis = min(dis, mindis);
		}
		sum += mindis;
	}
	min_distance = min(sum, min_distance);
}

bool cmp(const Chiken& a, const Chiken& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				homemap.push_back({ i, j });
			}
			if (num == 2) {
				ckmap.push_back({ i, j });
			}
		}
	}

	// 치킨 좌표에서 M개 선택
	sort(ckmap.begin(), ckmap.end(), cmp);

	vector<int> arr(ckmap.size(), 1);
	for (int i = 0; i < M; i++) {
		arr[i] = 0;
	}
	do {
		vector<Chiken> subckmap;
		for (int i = 0; i < ckmap.size(); i++) {
			if (arr[i] == 0) {
				subckmap.push_back(ckmap[i]);
			}
		}
		calculate(subckmap);
	} while (next_permutation(arr.begin(), arr.end()));

	cout << min_distance << "\n";

	return 0;
}