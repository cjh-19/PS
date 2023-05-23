#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tile {
	string name; // 타일의 번호
	int numArray[4]; // 타일의 각 면의 값
	int rotation = 0; // 반시계 방향 회전 횟수
};

// 클래스 정의
class Magic_Tiles {
public:
	Magic_Tiles(); // 생성자
	bool solve(int index); // 퍼즐를 푸는 함수, 백트래킹
	void rotateBoard(); // 보드 전체를 회전
	void printBoard(); // 현재 보드의 구성 출력
	void swap(int x, int y); // 두개의 타일 교환
	void rotateTile(int tileNum); // 타일을 시계 방향으로 회전
	void counter_rotateTile(int tileNum); // 타일을 반시계 방향으로 회전
	bool edgesMatch(int position); // 주변 타일의 가장자리와 값을 비교
	~Magic_Tiles(); // 소멸자

//private:
	//bool found = false;
	Tile tileArray[9]; // 보드에는 9개의 타일 존재
};

int solution_count = 0; // 해의 개수, 나중에 *4 해서 출력
vector<Magic_Tiles> solutions(512); // 해가 되는 퍼즐보드를 저장

Magic_Tiles::Magic_Tiles() {
//	for (int i = 0; i < 9; i++) {
//		Tile aTile;
//		aTile.name = to_string(i + 1); // 퍼즐의 번호
//		for (int j = 0; j < 4; j++) {
//			cin >> aTile.numArray[j]; // 각 면의 값 입력
//		}
//		tileArray[i] = aTile;
//	}
//	cout << endl;
}

// 백트래킹을 이용하여 퍼즐을 맞추는 해를 구함
bool Magic_Tiles::solve(int index) {
	if (index == 9) {
		int check = 0;
		if (solution_count == 0) { // 첫번째 해라면 비교없이 바로 추가
			for (int i = 0; i < 9; i++) { // 9개의 퍼즐 조각을 solutions 벡터에 추가
					solutions[solution_count].tileArray[i].name = tileArray[i].name;
					solutions[solution_count].tileArray[i].rotation = tileArray[i].rotation;
				for (int j = 0; j < 4; j++) {
					solutions[solution_count].tileArray[i].numArray[j] = tileArray[i].numArray[j];
				}
			}
			solution_count++;
		}
		else {
			for (int k = 0; k < solution_count; k++) { // 현재 보드와 solutions벡터에 있는 보드를 비교
				for (int t = 0; t < 4; t++) {
					int boardCheck = 0;
					for (int i = 0; i < 9; i++) {
						int sideCheck = 0;
						for (int j = 0; j < 4; j++) {
							if ((solutions[k].tileArray[i].name == tileArray[i].name) ||
								(solutions[k].tileArray[i].numArray[j] == tileArray[i].numArray[j]) ||
								(solutions[k].tileArray[i].rotation == tileArray[i].rotation)){
								sideCheck++; // 면의 값이 맞다면 증가
							}
						}
						if (sideCheck == 4) // 모든 면이 같은 경우
							boardCheck++;
					}
					rotateBoard(); // 4번 회전하며 모두 다른지 체크
					if (boardCheck == 9) { // 9개의 조각이 모두 같은 경우
						check = 1; // 추가하지 않음
					}
				}
			}
		}
		if (check == 1)
			return true; // 추가하지 않고 반환
		else if (check == 0) { // 같지 않다면 추가
			for (int i = 0; i < 9; i++) {
				solutions[solution_count].tileArray[i].name = tileArray[i].name;
				solutions[solution_count].tileArray[i].rotation = tileArray[i].rotation;
				for (int j = 0; j < 4; j++) {
					solutions[solution_count].tileArray[i].numArray[j] = tileArray[i].numArray[j];
				}
			}
			solution_count++;
			return true;
		}
	}
	else {
		for (int i = index; i < 9; i++) {
			swap(index, i);
			for (int j = 0; j < 4; j++) {
				// 현재 퍼즐조각이 일치하면 solve(index + 1)호출
				// 아니면 현재 퍼즐조각을 회전시킨다

				// 첫 번째 타일은 비교할 것이 없다
				if (index == 0) {
					if (!solve(index + 1)) {
						rotateTile(index);
					}
				}
				// 두 번째부터 아홉 번째 퍼즐의 경우
				// 현재 위치에 배치할 퍼즐의 가장자리가 이웃하는
				// 퍼즐의 가장자리와 일치해야 한다
				else if (edgesMatch(index)) {
					if (solve(index + 1)) {
						return true;
					}
				}
				// 다른 퍼즐을 배치하기 전에 현재 타일을 회전시켜 일치하는지 확인
				else {
					counter_rotateTile(index);
				}
			}
			// 솔루션이 없으면 swap을 통해 다음 퍼즐로 진행한다. 백트래킹
			swap(index, i);
		}
		return false;
	}
}

// 보드 전체를 회전시켜 다른 솔루션을 표시한다
void Magic_Tiles::rotateBoard() {
	// 회전된 보드를 임시로 저장
	Tile tempTileArray[9];
	// 모든 타일을 회전시킨다
	// 보드의 구성이 회전된 상태로 변경
	for (int i = 0; i < 9; i++)
		rotateTile(i);

	// 시계방향으로 회전(90도)
	tempTileArray[0] = tileArray[6];
	tempTileArray[1] = tileArray[3];
	tempTileArray[2] = tileArray[0];
	tempTileArray[3] = tileArray[7];
	tempTileArray[4] = tileArray[4];
	tempTileArray[5] = tileArray[1];
	tempTileArray[6] = tileArray[8];
	tempTileArray[7] = tileArray[5];
	tempTileArray[8] = tileArray[2];

	// 보드의 구성을 업데이트
	for (int j = 0; j < 9; j++)
		tileArray[j] = tempTileArray[j];
}

// 현재 보드를 출력
void Magic_Tiles::printBoard() {
	for (int i = 0; i < 9; i += 3) {
		cout << tileArray[i].name << "(" << tileArray[i].rotation << ") ";
		cout << tileArray[i + 1].name << "(" << tileArray[i + 1].rotation << ") ";
		cout << tileArray[i + 2].name << "(" << tileArray[i + 2].rotation << ") ";
	}
	cout << "\n";
}

// 현재 보드의 두 타일 위치를 변경한다.
// 인덱스 x와 y를 가진 두 타일
void Magic_Tiles::swap(int x, int y) {
	Tile temp = tileArray[x];
	tileArray[x] = tileArray[y];
	tileArray[y] = temp;
}


// 현재 사용중인 타일을 시계 방향으로 회전시킨다.
void Magic_Tiles::rotateTile(int tileNum) {
	// 현재 타일의 마지막 면(3번째)의 숫자를 temp에 저장
	int temp = tileArray[tileNum].numArray[3];
	// 뒤에서 두 번째부터 첫 번째까지 반복 
	for (int k = 3; k > 0; k--) {
		tileArray[tileNum].numArray[k] = tileArray[tileNum].numArray[k - 1];
	}
	// 첫 번째에 마지막 값을 넣어 회전시킨다.
	tileArray[tileNum].numArray[0] = temp;

	// 현재 타일의 회전상태가 3이라면 (전부 회전했다면) 0으로 초기화
	// 처음으로 돌아감
	if (tileArray[tileNum].rotation == 0)
		tileArray[tileNum].rotation = 3;
	// 아니라면 (0,1,2라면) 회전상태를 +1한다
	else
		tileArray[tileNum].rotation--;
}

// 현재 사용중인 타일을 반시계 방향으로 회전시킨다.
void Magic_Tiles::counter_rotateTile(int tileNum) {
	// 현재 타일의 마지막 면(3번째)의 숫자를 temp에 저장
	int temp = tileArray[tileNum].numArray[0];
	// 뒤에서 두 번째부터 첫 번째까지 반복 
	for (int k = 0; k < 3; k++) {
		tileArray[tileNum].numArray[k] = tileArray[tileNum].numArray[k + 1];
	}
	// 첫 번째에 마지막 값을 넣어 회전시킨다.
	tileArray[tileNum].numArray[3] = temp;

	// 현재 타일의 회전상태가 3이라면 (전부 회전했다면) 0으로 초기화
	// 처음으로 돌아감
	if (tileArray[tileNum].rotation == 3)
		tileArray[tileNum].rotation = 0;
	// 아니라면 (0,1,2라면) 회전상태를 +1한다
	else
		tileArray[tileNum].rotation++;
}

// 현재 배치하려는 타일의 가장자리(edge)를
// "배치된" 이웃한 타일의 가장자리와 비교
bool Magic_Tiles::edgesMatch(int position) {
	// position(0) : 첫번째 위치는 비교할 것이 없다.
	// 1부터 8까지만 비교
	switch (position) {

	case 1: return ((tileArray[0].numArray[1] == 1 && tileArray[1].numArray[3] == 2) ||		// 0번 우측 - 1번 좌측
		(tileArray[0].numArray[1] == 2 && tileArray[1].numArray[3] == 1) ||
		(tileArray[0].numArray[1] == 3 && tileArray[1].numArray[3] == 4) ||
		(tileArray[0].numArray[1] == 4 && tileArray[1].numArray[3] == 3) ||
		(tileArray[0].numArray[1] == 5 && tileArray[1].numArray[3] == 6) ||
		(tileArray[0].numArray[1] == 6 && tileArray[1].numArray[3] == 5) ||
		(tileArray[0].numArray[1] == 7 && tileArray[1].numArray[3] == 8) ||
		(tileArray[0].numArray[1] == 8 && tileArray[1].numArray[3] == 7));

	case 2: return ((tileArray[1].numArray[1] == 1 && tileArray[2].numArray[3] == 2) ||		// 1번 우측 - 2번 좌측 
		(tileArray[1].numArray[1] == 2 && tileArray[2].numArray[3] == 1) ||
		(tileArray[1].numArray[1] == 3 && tileArray[2].numArray[3] == 4) ||
		(tileArray[1].numArray[1] == 4 && tileArray[2].numArray[3] == 3) ||
		(tileArray[1].numArray[1] == 5 && tileArray[2].numArray[3] == 6) ||
		(tileArray[1].numArray[1] == 6 && tileArray[2].numArray[3] == 5) ||
		(tileArray[1].numArray[1] == 7 && tileArray[2].numArray[3] == 8) ||
		(tileArray[1].numArray[1] == 8 && tileArray[2].numArray[3] == 7));

	case 3: return ((tileArray[0].numArray[2] == 1 && tileArray[3].numArray[0] == 2) ||		// 0번 하단 - 3번 상단
		(tileArray[0].numArray[2] == 2 && tileArray[3].numArray[0] == 1) ||
		(tileArray[0].numArray[2] == 3 && tileArray[3].numArray[0] == 4) ||
		(tileArray[0].numArray[2] == 4 && tileArray[3].numArray[0] == 3) ||
		(tileArray[0].numArray[2] == 5 && tileArray[3].numArray[0] == 6) ||
		(tileArray[0].numArray[2] == 6 && tileArray[3].numArray[0] == 5) ||
		(tileArray[0].numArray[2] == 7 && tileArray[3].numArray[0] == 8) ||
		(tileArray[0].numArray[2] == 8 && tileArray[3].numArray[0] == 7));

	case 4: return (((tileArray[3].numArray[1] == 1 && tileArray[4].numArray[3] == 2) ||  // 3번 우측 - 4번 좌측
		(tileArray[3].numArray[1] == 2 && tileArray[4].numArray[3] == 1) ||			  // 1번 하단 - 4번 상단
		(tileArray[3].numArray[1] == 3 && tileArray[4].numArray[3] == 4) ||
		(tileArray[3].numArray[1] == 4 && tileArray[4].numArray[3] == 3) ||
		(tileArray[3].numArray[1] == 5 && tileArray[4].numArray[3] == 6) ||
		(tileArray[3].numArray[1] == 6 && tileArray[4].numArray[3] == 5) ||
		(tileArray[3].numArray[1] == 7 && tileArray[4].numArray[3] == 8) ||
		(tileArray[3].numArray[1] == 8 && tileArray[4].numArray[3] == 7)) &&
		((tileArray[1].numArray[2] == 1 && tileArray[4].numArray[0] == 2) ||
			(tileArray[1].numArray[2] == 2 && tileArray[4].numArray[0] == 1) ||
			(tileArray[1].numArray[2] == 3 && tileArray[4].numArray[0] == 4) ||
			(tileArray[1].numArray[2] == 4 && tileArray[4].numArray[0] == 3) ||
			(tileArray[1].numArray[2] == 5 && tileArray[4].numArray[0] == 6) ||
			(tileArray[1].numArray[2] == 6 && tileArray[4].numArray[0] == 5) ||
			(tileArray[1].numArray[2] == 7 && tileArray[4].numArray[0] == 8) ||
			(tileArray[1].numArray[2] == 8 && tileArray[4].numArray[0] == 7)));

	case 5: return (((tileArray[4].numArray[1] == 1 && tileArray[5].numArray[3] == 2) ||  // 4번 우측 - 5번 좌측
		(tileArray[4].numArray[1] == 2 && tileArray[5].numArray[3] == 1) ||		  // 2번 하단 - 5번 상단
		(tileArray[4].numArray[1] == 3 && tileArray[5].numArray[3] == 4) ||
		(tileArray[4].numArray[1] == 4 && tileArray[5].numArray[3] == 3) ||
		(tileArray[4].numArray[1] == 5 && tileArray[5].numArray[3] == 6) ||
		(tileArray[4].numArray[1] == 6 && tileArray[5].numArray[3] == 5) ||
		(tileArray[4].numArray[1] == 7 && tileArray[5].numArray[3] == 8) ||
		(tileArray[4].numArray[1] == 8 && tileArray[5].numArray[3] == 7)) &&
		((tileArray[2].numArray[2] == 1 && tileArray[5].numArray[0] == 2) ||
			(tileArray[2].numArray[2] == 2 && tileArray[5].numArray[0] == 1) ||
			(tileArray[2].numArray[2] == 3 && tileArray[5].numArray[0] == 4) ||
			(tileArray[2].numArray[2] == 4 && tileArray[5].numArray[0] == 3) ||
			(tileArray[2].numArray[2] == 5 && tileArray[5].numArray[0] == 6) ||
			(tileArray[2].numArray[2] == 6 && tileArray[5].numArray[0] == 5) ||
			(tileArray[2].numArray[2] == 7 && tileArray[5].numArray[0] == 8) ||
			(tileArray[2].numArray[2] == 8 && tileArray[5].numArray[0] == 7)));

	case 6: return (tileArray[3].numArray[2] == 1 && tileArray[6].numArray[0] == 2) ||		// 3번 하단 - 6번 상단
		(tileArray[3].numArray[2] == 2 && tileArray[6].numArray[0] == 1) ||
		(tileArray[3].numArray[2] == 3 && tileArray[6].numArray[0] == 4) ||
		(tileArray[3].numArray[2] == 4 && tileArray[6].numArray[0] == 3) ||
		(tileArray[3].numArray[2] == 5 && tileArray[6].numArray[0] == 6) ||
		(tileArray[3].numArray[2] == 6 && tileArray[6].numArray[0] == 5) ||
		(tileArray[3].numArray[2] == 7 && tileArray[6].numArray[0] == 8) ||
		(tileArray[3].numArray[2] == 8 && tileArray[6].numArray[0] == 7);

	case 7: return (((tileArray[6].numArray[1] == 1 && tileArray[7].numArray[3] == 2) ||  // 6번 우측 - 7번 좌측
		(tileArray[6].numArray[1] == 2 && tileArray[7].numArray[3] == 1) ||		  // 4번 하단 - 7번 상단
		(tileArray[6].numArray[1] == 3 && tileArray[7].numArray[3] == 4) ||
		(tileArray[6].numArray[1] == 4 && tileArray[7].numArray[3] == 3) ||
		(tileArray[6].numArray[1] == 5 && tileArray[7].numArray[3] == 6) ||
		(tileArray[6].numArray[1] == 6 && tileArray[7].numArray[3] == 5) ||
		(tileArray[6].numArray[1] == 7 && tileArray[7].numArray[3] == 8) ||
		(tileArray[6].numArray[1] == 8 && tileArray[7].numArray[3] == 7)) &&
		((tileArray[4].numArray[2] == 1 && tileArray[7].numArray[0] == 2) ||
			(tileArray[4].numArray[2] == 2 && tileArray[7].numArray[0] == 1) ||
			(tileArray[4].numArray[2] == 3 && tileArray[7].numArray[0] == 4) ||
			(tileArray[4].numArray[2] == 4 && tileArray[7].numArray[0] == 3) ||
			(tileArray[4].numArray[2] == 5 && tileArray[7].numArray[0] == 6) ||
			(tileArray[4].numArray[2] == 6 && tileArray[7].numArray[0] == 5) ||
			(tileArray[4].numArray[2] == 7 && tileArray[7].numArray[0] == 8) ||
			(tileArray[4].numArray[2] == 8 && tileArray[7].numArray[0] == 7)));

	case 8: return (((tileArray[7].numArray[1] == 1 && tileArray[8].numArray[3] == 2) ||  // 7번 우측 - 8번 좌측
		(tileArray[7].numArray[1] == 2 && tileArray[8].numArray[3] == 1) ||		  // 5번 하단 - 8번 상단
		(tileArray[7].numArray[1] == 3 && tileArray[8].numArray[3] == 4) ||
		(tileArray[7].numArray[1] == 4 && tileArray[8].numArray[3] == 3) ||
		(tileArray[7].numArray[1] == 5 && tileArray[8].numArray[3] == 6) ||
		(tileArray[7].numArray[1] == 6 && tileArray[8].numArray[3] == 5) ||
		(tileArray[7].numArray[1] == 7 && tileArray[8].numArray[3] == 8) ||
		(tileArray[7].numArray[1] == 8 && tileArray[8].numArray[3] == 7)) &&
		((tileArray[5].numArray[2] == 1 && tileArray[8].numArray[0] == 2) ||
			(tileArray[5].numArray[2] == 2 && tileArray[8].numArray[0] == 1) ||
			(tileArray[5].numArray[2] == 3 && tileArray[8].numArray[0] == 4) ||
			(tileArray[5].numArray[2] == 4 && tileArray[8].numArray[0] == 3) ||
			(tileArray[5].numArray[2] == 5 && tileArray[8].numArray[0] == 6) ||
			(tileArray[5].numArray[2] == 6 && tileArray[8].numArray[0] == 5) ||
			(tileArray[5].numArray[2] == 7 && tileArray[8].numArray[0] == 8) ||
			(tileArray[5].numArray[2] == 8 && tileArray[8].numArray[0] == 7)));

	default: return true; // 가장자리 비교를 수행하지 않아도 되는 것은 true 반환
	}
}

Magic_Tiles::~Magic_Tiles() {}


int main() {
	Magic_Tiles puzzle;
	for (int i = 0; i < 9; i++) {
		Tile aTile;
		aTile.name = to_string(i + 1); // 퍼즐의 번호
		for (int j = 0; j < 4; j++) {
			cin >> aTile.numArray[j]; // 각 면의 값 입력
		}
		puzzle.tileArray[i] = aTile;
	}
	cout << endl;
	puzzle.solve(0);

	// 하나의 솔루션 당 보드를 회전하면 총 4개의 솔루션이 생김
	// 보드를 회전시켜 각 솔루션 출력
	cout << solution_count * 4 << "\n";

	//for (int i = 1; i < 5; i++) {
	//	puzzle.printBoard();
	//	puzzle.rotateBoard();
	//}
	for (int i = 0; i < solution_count; i++) {
		for (int j = 0; j < 4; j++) {
			solutions[i].printBoard();
			solutions[i].rotateBoard();
		}
	}

	return 0;
}