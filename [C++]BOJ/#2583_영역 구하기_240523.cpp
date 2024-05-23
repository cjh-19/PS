#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M; // 세로 길이
int N; // 가로 길이
int K; // 도형 개수

vector<vector<int>> map; // 지도
vector<vector<bool>> visited; // 방문 여부

int dx[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dy[4] = { 0, 0, -1, 1 }; // 상 하 좌 우

// 영역의 크기를 구하는 dfs
int dfs(int x, int y) {
	visited[x][y] = true;
	int areasize = 1; // 현재 영역의 크기

	// 상하좌우 탐색
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; // 행 변화량
		int ny = y + dy[i]; // 열 변화량

		// 이동한 좌표가 탐색할 수 있는 곳인지 확인
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == 0 && visited[nx][ny] == false) {
			// 탐색할 수 있다면 다음 영역 측정한 dfs를 areasize에 추가
			areasize += dfs(nx, ny);
		}
	}
	return areasize;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	// 벡터 초기화
	map.resize(M, vector<int>(N, 0));
	visited.resize(M, vector<bool>(N, false));

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2; // 왼쪽 아래, 오른쪽 위
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				map[j][k] = 1;
			}
		}
	}

	// ex)
	// map[][]
	// 0 2 4 4
	// x(열, 가로)는 0~3 map[][이부분]
	// y(행, 세로)는 2~3 map[이부분][]

	// 영역의 크기 저장
	vector<int> areas;

	// 방문하는 곳이 0인지 방문하지 않았는지 확인
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				// 영역의 크기를 구하는 dfs
				int areasize = dfs(i, j);
				areas.push_back(areasize);
			}
		}
	}

	// 오름차순으로 정렬
	sort(areas.begin(), areas.end());

	// 출력
	cout << areas.size() << "\n";
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << " ";
	}
	cout << "\n";

	return 0;
}