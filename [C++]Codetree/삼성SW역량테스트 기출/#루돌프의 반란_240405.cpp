#include<iostream>

using namespace std;

#define MAX_N 51 // 최대 게임 판 크기
#define MAX_P 31 // 최대 산타 수

int	n, m, p, c, d;
int point[MAX_P]; // 산타의 점수
pair<int, int> rudolf; // 루돌프 좌표
pair<int, int> santa[MAX_P]; // 산타 좌표

int board[MAX_N][MAX_N]; // 보드 위 루돌프 산타 좌표
bool alive[MAX_P]; // 산타 생존 여부
int stun[MAX_P]; // 산타 기절 종료 턴수

// {좌, 상, 우, 하}
const int dx[4] = { -1, 0, 1, 0 }; // 좌우 방향 벡터
const int dy[4] = { 0, 1, 0, -1 }; // 상하 방향 벡터

// (x, y)가 보드 내의 좌표인지 확인하는 함수
bool is_inrange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> p >> c >> d; // 초기 변수 값
	cin >> rudolf.first >> rudolf.second; // 루돌프 좌표 입력
	board[rudolf.first][rudolf.second] = -1; // 보드에 루돌프 위치 표시

	for (int i = 1; i <= p; i++) {
		int id; // 산타 번호
		cin >> id;
		cin >> santa[id].first >> santa[id].second; // 산타 좌표 입력
		board[santa[id].first][santa[id].second] = id; // 보드에 산타 위치 표시
		alive[id] = true; // 산타 생존 여부
	}

	// 게임 턴수 만큼 진행
	for (int i = 1; i <= m; i++) {
		// 첫번재로는 루돌프에 가장 가까운 산타 찾기 (단, 생존 산타에서)
		int closestX = 10000, closestY = 10000, closestIdx = 0;

		// 살아있는 산타 중 루돌프에 가장 가까운 산타를 찾음
		for (int j = 1; j <= p; j++) {
			if (!alive[j]) continue; // 산타가 살아있지 않다면, 아래 과정 스킵

			// currentBest : 이전에 가장 가까운 산타와 루돌프의 거리
			// currentValue : 살아있는 산타들과 루돌프의 거리
			pair<int, pair<int, int>> currentBest = { (closestX - rudolf.first) * (closestX - rudolf.first) + (closestY - rudolf.second) * (closestY - rudolf.second), {-closestX, -closestY} };
			pair<int, pair<int, int>> currentValue = { (santa[j].first - rudolf.first) * (santa[j].first - rudolf.first) + (santa[j].second - rudolf.second) * (santa[j].second - rudolf.second), {-santa[j].first, -santa[j].second} };

			// 가장 가까운 산타 번호와 산타 좌표 업데이트
			if (currentBest > currentValue) {
				closestX = santa[j].first;
				closestY = santa[j].second;
				closestIdx = j;
			}
		}

		// (가장 가까운 산타가 있다면) 
		// 가장 가까운 산타의 방향으로 루돌프가 이동
		if (closestIdx) {
			pair<int, int> prevRudolf = rudolf;

			// 루돌프의 이동방향을 체크 (어느 방향으로 충돌될지 계산)
			int moveX = 0;
			if (closestX > rudolf.first) moveX = 1;
			else if (closestX < rudolf.first) moveX = -1;

			int moveY = 0;
			if (closestY > rudolf.second) moveY = 1;
			else if (closestY < rudolf.second) moveY = -1;

			// 루돌프 위치 업데이트
			rudolf.first += moveX;
			rudolf.second += moveY;
			board[prevRudolf.first][prevRudolf.second] = 0; // 기존 루돌프 위치 0으로 초기화

			// 루돌프의 이동 -> 산타 충돌 -> 산타 이동
			if (rudolf.first == closestX && rudolf.second == closestY) {
				// 연쇄 이동을 시작한 산타의 이동 목표 지점 : (firstX, firstY)
				int firstX = closestX + moveX * c; // c만큼 moveX 방향으로 이동
				int firstY = closestY + moveY * c; // c만큼 moveY 방향으로 이동

				// 연쇄 이동의 마지막 산타가 도달한 최종지점 : (lastX, lastY)
				int lastX = firstX;
				int lastY = firstY;

				stun[closestIdx] = i + 1; // 부딪힌 산타는 i+1 번째 턴까지 기절

				// 산타간 충돌하여 이동할 경우, 산타가 최종적으로 도달할 수 있는 위치
				// 1. 위치가 보드내에 있고 2. 그 칸에 산타가 있을 때
				while (is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
					lastX += moveX;
					lastY += moveY;
				}

				// (lastX, lastY) 위치부터 역방향으로 산타를 이동
				// (lastX, lastY)가 (firstX, firstY)에 도달할 때까지 반복
				while (!(lastX == firstX && lastY == firstY)) {
					// 산타가 이동하기 전의 위치
					int beforeX = lastX - moveX;
					int beforeY = lastY - moveY;

					// 이동하기 전의 위치가 보드 밖이라면 whlie문 종료
					// 연쇄 이동이 보드의 경계를 넘어가는 것을 방지
					if (!is_inrange(beforeX, beforeY)) break;

					// 이동하기 전의 위치에 있는 산타 번호
					int idx = board[beforeX][beforeY];

					// 이동한 뒤의 위치가 보드 범위 밖이라면, 산타 제거
					if (!is_inrange(lastX, lastY)) {
						alive[idx] = false;
					}
					else {
						// 산타의 번호를 이동 후의 칸으로 변경
						board[lastX][lastY] = board[beforeX][beforeY];
						santa[idx] = { lastX, lastY }; // 산타의 좌표 업데이트
					}

					// 충돌 역방향으로 이동중이므로 이전 좌표로 업데이트
					lastX = beforeX;
					lastY = beforeY;
				}

				// 루돌프와 충돌한 루돌프와 가장 가까운 산타 점수 추가
				point[closestIdx] += c;
				santa[closestIdx] = { firstX, firstY }; // 첫번째 충돌 산타 위치 업데이트
				if (is_inrange(firstX, firstY)) {
					board[firstX][firstY] = closestIdx; // 이동한 칸으로 산타 번호 변경
				}
				else { // 이동한 좌표가 보드 밖이면 산타 제거
					alive[closestIdx] = false;
				}

			}
		}
		board[rudolf.first][rudolf.second] = -1; // 루돌프 이동 후 좌표 변경

		// 각 산타들은 루돌프와 가장 가까운 방향으로 한칸 이동
		for (int j = 1; j <= p; j++) {
			// 산타가 살아있거나 기절이 아니라면
			if (!alive[j] || stun[j] >= i)
				continue;

			// 거리 계산
			// 현재 위치와 루돌프와의 거리
			int minDistance = (santa[j].first - rudolf.first) * (santa[j].first - rudolf.first) + (santa[j].second - rudolf.second) * (santa[j].second - rudolf.second);
			// 이동할 방향(임의)
			int moveDir = -1;

			// 루돌프와 가장 가까운 방향으로 이동하기 위한 방향 탐색(상하좌우)
			for (int dir = 0; dir < 4; dir++) {
				int nx = santa[j].first + dx[dir]; // 좌/우
				int ny = santa[j].second + dy[dir]; // 상/하

				// 이동할 위치가 보드 범위 밖이거나
				// 이동할 위치에 산타가 있는 경우는 스킵 
				if (!is_inrange(nx, ny) || board[nx][ny] > 0)
					continue;

				// 이동할 거리와 루돌프와의 거리
				int dist = (nx - rudolf.first) * (nx - rudolf.first) + (ny - rudolf.second) * (ny - rudolf.second);
				if (dist < minDistance) {
					minDistance = dist;
					moveDir = dir;
				}
			}

			// 이동할 수 있어서 moveDir이 업데이트 된 경우
			// 산타 이동
			if (moveDir != -1) {
				// {nx, ny} : 이동한 산타 좌표
				int nx = santa[j].first + dx[moveDir];
				int ny = santa[j].second + dy[moveDir];

				// 산타의 이동으로 루돌프와 충돌한 경우
				if (nx == rudolf.first && ny == rudolf.second) {
					stun[j] = i + 1; // i+1턴까지 기절

					// 팅겨나갈 좌우/상하 방향
					int moveX = -dx[moveDir];
					int moveY = -dy[moveDir];

					// d만큼 팅겨나간 좌표
					int firstX = nx + moveX * d;
					int firstY = ny + moveY * d;

					int lastX = firstX;
					int lastY = firstY;

					if (d == 1) { // d = 1 이라면 산타는 제자리로 돌아옴
						point[j] += d;
					}
					else {
						// 만약 이동한 위치에 산타가 있는 경우
						// 연쇄적인 이동
						// (lastX, lastY) : 마지막으로 충돌된 산타의 최종 위치
						while (is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
							lastX += moveX;
							lastY += moveY;
						}

						// 충돌이 일어난 마지막 산타부터
						// 처음으로 부딪힌 산타까지 역순으로 한칸씩 이동
						while (!(lastX == firstX && lastY == firstY)) {
							// 이동 전 산타 좌표
							int beforeX = lastX - moveX;
							int beforeY = lastY - moveY;

							// 이동전에 보드 범위 바깥에 있었다면 while문 종료
							if (!is_inrange(beforeX, beforeY))
								break;

							// 이동 전 위치에 있는 산타 번호
							int idx = board[beforeX][beforeY];

							// 이동 후의 위치가 보드 밖이라면 산타 제거
							if (!is_inrange(lastX, lastY)) {
								alive[idx] = false;
							}
							else { // 산타의 좌표 업데이트
								board[lastX][lastY] = board[beforeX][beforeY];
								santa[idx] = { lastX, lastY };
							}

							// 다음 산타 계산
							lastX = beforeX;
							lastY = beforeY;
						}

						// 첫번째로 부딪힌 산타 좌표 업데이트
						point[j] += d; // 처음 부딪힌 산타 점수 추가
						board[santa[j].first][santa[j].second] = 0; // 처음 부딪힌 산타 이동 전 위치 초기화
						santa[j] = { firstX, firstY };
						if (is_inrange(firstX, firstY)) {
							board[firstX][firstY] = j;
						}
						else {
							alive[j] = false;
						}
					}
				}
				else { // 한칸 이동한 산타 좌표 업데이트
					board[santa[j].first][santa[j].second] = 0;
					santa[j] = { nx, ny };
					board[nx][ny] = j;
				}
			}
		}

		// 각 라운드가 끝나고 탈락하지 않은 산타들은 1점 증가
		for (int j = 1; j <= p; j++) {
			if (alive[j]) {
				point[j]++;
			}
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << point[i] << " ";
	}


	return 0;
}


/*
**문제

각 턴에 대해 살아있는 산타 중에서 루돌프와 가장 가까운 산타를 찾아 루돌프가 이동

이때 거리가 가튼 경우 좌표를 기준을 선택

산타와 루돌프가 충돌하면 산타는 점수를 얻고 루돌프 이동 방향으로 특정 칸만큼 밀려남.
해당 칸에 다른 산타가 있으면 연쇄적인 이동

산타는 자신의 차례에 루돌프와 가장 가까워질 수 있는 방향으로 이동

이동 중 루돌프와 충돌하면 반대 방향으로 밀리며, 연쇄적 이동

게임의 각 턴이 끝날 때 살아남은 산타에게 추가 점수 부여

게임은 모든 턴이 종료되거나 모든 산타가 탈락될 때 종료



** 알고리즘

루돌프와 산타의 이동 및 충돌 처리
점수 계산
산타의 기절 및 게임 탈락 여부
를 확인하며 순차적으로 게임의 상태 업데이트

배열과 반복문을 활용해 각 산타의 위치, 루돌프의 위치, 점수 및  게임의 상태 관리

전체 게임의 턴 수만큼 반복문을 실행하므로
시간 복잡도는 시뮬레이션을 수행하는 부분에서 발생하는 비용 -> O(M)
M은 게임의 턴 수

*/