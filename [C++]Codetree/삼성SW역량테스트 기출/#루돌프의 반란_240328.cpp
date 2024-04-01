#include<iostream>

using namespace std;

#define MAX_N 51 // 최대 게임 판 크기
#define MAX_P 31 // 최대 산타 수

int	n, m, p, c, d;
pair<int, int> rudolf; // 루돌프 좌표
pair<int, int> santa[MAX_P]; // 산타 좌표

int board[MAX_N][MAX_N]; // 보드 위 루돌프 산타 좌표
bool alive[MAX_P]; // 산타 생존 여부
int stun[MAX_P]; // 산타 기절 종료 턴수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> p >> c >> d; // 초기 변수 값
	cin >> rudolf.first >> rudolf.second; // 루돌프 좌표 입력
	board[rudolf.first][rudolf.second] = -1; // 보드에 루돌프 위치 표시

	for (int i = 0; i < p; i++) {
		int id; // 산타 번호
		cin >> id;
		cin >> santa[id].first >> santa[id].second; // 산타 좌표 입력
		board[santa[id].first][santa[id].second] = id; // 보드에 산타 위치 표시
		alive[id] = true; // 산타 생존 여부
	}

	// 게임 턴수 만큼 진행
	for (int i = 0; i < m; i++) {
		// 첫번재로는 루돌프에 가장 가까운 산타 찾기 (단, 생존 산타에서)

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