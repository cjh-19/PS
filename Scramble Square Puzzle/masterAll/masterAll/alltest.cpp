#include <iostream>
#include <string>

using namespace std;

struct Tile {
	string name;
	int numArray[4];
	int rotation = 0;
};

int solution_count = 0;

// 클래스 정의
class Magic_Tiles {
public:
	Magic_Tiles();
	void solve(int index); // 퍼즐를 푸는 함수, 백트래킹
	void rotateBoard(); // 보드 전체를 회전
	void printBoard(); // 현재 보드의 구성 출력
	void swap(int x, int y); // 두개의 타일 교환
	void rotateTile(int tileNum); // 타일을 시계 방향으로 회전
	void conter_rotateTile(int tileNum); // 타일을 반시계 방향으로 회전
	bool edgesMatch(int position); // 주변 타일의 가장자리와 값을 비교
	void Six_case(Magic_Tiles puzzle);
	~Magic_Tiles();

private:
	bool found = false;
	Tile tileArray[9];
};

Magic_Tiles::Magic_Tiles() {
	for (int i = 0; i < 9; i++) {
		Tile aTile;
		aTile.name = to_string(i + 1); // 퍼즐의 번호
		for (int j = 0; j < 4; j++) {
			cin >> aTile.numArray[j]; // 각 면의 값 입력
		}
		tileArray[i] = aTile;
	}
	cout << endl;
}

void Magic_Tiles::solve(int index) {
	if (found) { // found라면 재귀를 종료하고 함수를 반환한다
		return;
	}

	// index 가 9에 도달하면 모든 비교는 참으로 되고 해가 발견된다.
	// 결과를 출력하고 found를 참으로 하고 반환한다.
	else if (index == 9) {
		// 첫번째 솔루션 출력
		solution_count++;
		found = true;
		return;
	}

	else {
		for (int i = index; i < 9; i++) {
			swap(index, i);
			for (int j = 0; j < 4; j++) {
				// 현재타일이 일치하면 solve(index + 1) 호출
				// 아니면 현재 타일을 회전시킨다.

				// 첫 번째 타일은 비교할 것이 없다
				if (index == 0) {
					solve(index + 1);
					if (!found)
						rotateTile(index);
				}
				// 두 번째부터 아홉 번째 타일의 경우
				// 현재 위치에 배치할 타일의 가장자리가 이웃하는
				// 타일의 가장자리와 일치해야 한다
				else if (edgesMatch(index)) {
					solve(index + 1);
				}
				// 다른 타일을 배치하기 전에 현재 타일을 회전시켜 일치하는지 확인
				else
					conter_rotateTile(index); // rotateTile(index);
			}

			// 솔루션이 발견되면 즉시 반환
			if (found) {
				return;
			}
			// 솔루션이 없으면 swap 호출하여 다음 타일로 진행
			else
				swap(index, i);
		}
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
void Magic_Tiles::conter_rotateTile(int tileNum) {
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
			(tileArray[3].numArray[1] == 8 && tileArray[4].numArray[3] == 7))&&
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

void Magic_Tiles::Six_case(Magic_Tiles puzzle) {
	Magic_Tiles Ptemp1 = puzzle;
	// case 1
	puzzle.solve(0);
	for (int i = 1; i < 5; i++) {
		puzzle.printBoard();
		puzzle.rotateBoard();
	}

	// case 2
	Ptemp1.swap(2, 4);
	Ptemp1.swap(3, 7);
	Ptemp1.swap(6, 8);
	Magic_Tiles Ptemp2 = Ptemp1;
	Ptemp1.solve(0);
	for (int i = 1; i < 5; i++) {
		Ptemp1.printBoard();
		Ptemp1.rotateBoard();
	}

	// case 3
	Ptemp2.swap(2, 6);
	Ptemp2.swap(1, 9);
	Ptemp2.swap(4, 8);
	Magic_Tiles Ptemp3 = Ptemp2;
	Ptemp2.solve(0);
	for (int i = 1; i < 5; i++) {
		Ptemp2.printBoard();
		Ptemp2.rotateBoard();
	}

	// case 4
	Ptemp3.swap(2, 4);
	Ptemp3.swap(3, 7);
	Ptemp3.swap(6, 8);
	Magic_Tiles Ptemp4 = Ptemp3;
	Ptemp3.solve(0);
	for (int i = 1; i < 5; i++) {
		Ptemp3.printBoard();
		Ptemp3.rotateBoard();
	}

	// case 5
	Ptemp4.swap(1, 7);
	Ptemp4.swap(2, 8);
	Ptemp4.swap(3, 9);
	Magic_Tiles Ptemp5 = Ptemp4;
	Ptemp4.solve(0);
	for (int i = 1; i < 5; i++) {
		Ptemp4.printBoard();
		Ptemp4.rotateBoard();
	}

	// case 6
	Ptemp5.swap(2, 6);
	Ptemp5.swap(1, 9);
	Ptemp5.swap(4, 8);
	Magic_Tiles Ptemp6 = Ptemp5;
	Ptemp5.solve(0);
	for (int i = 1; i < 5; i++) {
		Ptemp5.printBoard();
		Ptemp5.rotateBoard();
	}

	return;
}

Magic_Tiles::~Magic_Tiles() {}


int main() {
	char moreSolutions;
	Magic_Tiles puzzle;
	puzzle.Six_case(puzzle);
	//puzzle.solve(0);

	// 하나의 솔루션 당 보드를 회전하면 총 4개의 솔루션이 생김
	// 보드를 회전시켜 각 솔루션 출력
	cout << solution_count * 4 << "\n";
	//for (int i = 1; i < 5; i++) {
	//	//cout << "\nSolution " << i << " of 4:\n";
	//	puzzle.printBoard();
	//	puzzle.rotateBoard();
	//}

	return 0;
}