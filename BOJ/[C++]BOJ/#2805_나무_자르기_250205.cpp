/* 이분 탐색 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, M; // 나무의 수, 가져가려는 나무의 길
ll low, high, mid, sum, hmax = -1; // 가장 작은 값, 큰값, 중간값, 자른 나무 합, H의 최대값
ll tree[1000001]; // 나무 배열

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> tree[i];
	sort(tree, tree + N); // 0번부터 N번까지 오름차순 정렬

	low = 0;
	high = tree[N - 1];

	// 두 값이 같을 때까지 -> 같다면 그 지점이 hmax이기 때문
	while (low <= high) {
		sum = 0; // 자른 나무 합 초기화
		mid = (low + high) / 2;

		// 자른 나무 길이 더하기
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) sum += tree[i] - mid;
		}

		// 자른 나무 길이가 필요한 길이 이상일 경우
		// low를 mid + 1로 갱신
		if (sum >= M) {
			low = mid + 1;
			// H 최대값 갱신
			if (mid > hmax) hmax = mid;
		}
		// 필요 길이를 만족 못하는 경우 high를 감소 -> 톱날을 내림
		else high = mid - 1;
	}

	cout << hmax;

	return 0;
}