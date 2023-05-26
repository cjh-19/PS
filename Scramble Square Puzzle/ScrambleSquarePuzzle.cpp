#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Puzzle {
	string name; // 퍼즐의 번호
	int numArray[4]; // 퍼즐의 각 면의 값
	int rotation = 0; // 반시계 방향 회전 횟수
};

// 클래스 정의
class Board {
public:
	Board(); // 생성자
	bool solve(int index); // 퍼즐를 푸는 함수, 백트래킹
	void rotateBoard(); // 보드 전체를 회전
	void printBoard(); // 현재 보드의 구성 출력
	void swap(int x, int y); // 두개의 퍼즐 교환
	void rotatePuzzle(int tileNum); // 퍼즐을 시계 방향으로 회전
	void counter_rotatePuzzle(int tileNum); // 퍼즐을 반시계 방향으로 회전
	bool edgesMatch(int position); // 주변 퍼즐의 가장자리와 값을 비교
	~Board(); // 소멸자

	Puzzle puzzleArray[9]; // 보드에는 9개의 퍼즐 존재
};

// 전역변수
// 해의 개수, 나중에 *4 해서 출력
int solution_count = 0;
// 해가 되는 퍼즐보드를 저장, 최대 2^9 개까지 저장할 수 있도록 설정
vector<Board> solutions(512);

Board::Board() { }

// 백트래킹을 이용하여 퍼즐을 맞추는 해를 구함
bool Board::solve(int index) {
	if (index == 9) {
		int check = 0;
		if (solution_count == 0) { // 첫번째 해라면 비교없이 바로 추가
			for (int i = 0; i < 9; i++) { // 9개의 퍼즐 조각을 solutions 벡터에 추가
				solutions[solution_count].puzzleArray[i].name = puzzleArray[i].name;
				solutions[solution_count].puzzleArray[i].rotation = puzzleArray[i].rotation;
				for (int j = 0; j < 4; j++) {
					solutions[solution_count].puzzleArray[i].numArray[j] = puzzleArray[i].numArray[j];
				}
			}
			solution_count++;
			return true;
		}
		else {
			for (int k = 0; k < solution_count; k++) { // 현재 보드와 solutions벡터에 있는 보드를 비교
				for (int t = 0; t < 4; t++) {
					int boardCheck = 0;
					for (int i = 0; i < 9; i++) {
						int sideCheck = 0;
						for (int j = 0; j < 4; j++) {
							if ((solutions[k].puzzleArray[i].name == puzzleArray[i].name) ||
								(solutions[k].puzzleArray[i].numArray[j] == puzzleArray[i].numArray[j]) ||
								(solutions[k].puzzleArray[i].rotation == puzzleArray[i].rotation)) {
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
				solutions[solution_count].puzzleArray[i].name = puzzleArray[i].name;
				solutions[solution_count].puzzleArray[i].rotation = puzzleArray[i].rotation;
				for (int j = 0; j < 4; j++) {
					solutions[solution_count].puzzleArray[i].numArray[j] = puzzleArray[i].numArray[j];
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

				// 첫 번째 퍼즐은 비교할 것이 없다
				if (index == 0) {
					if (!solve(index + 1)) {
						rotatePuzzle(index);
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
				// 다른 퍼즐을 배치하기 전에 현재 퍼즐을 회전시켜 일치하는지 확인
				else {
					counter_rotatePuzzle(index);
				}
			}
			// 솔루션이 없으면 swap을 통해 다음 퍼즐로 진행
			swap(index, i);
		}
		return false;
	}
}

// 보드 전체를 회전시켜 다른 솔루션을 표시한다
void Board::rotateBoard() {
	// 회전된 보드를 임시로 저장
	Puzzle tempPuzzleArray[9];
	// 모든 퍼즐을 회전시킨다
	// 보드의 구성이 회전된 상태로 변경
	for (int i = 0; i < 9; i++)
		rotatePuzzle(i);

	// 시계방향으로 회전(90도)
	tempPuzzleArray[0] = puzzleArray[6];
	tempPuzzleArray[1] = puzzleArray[3];
	tempPuzzleArray[2] = puzzleArray[0];
	tempPuzzleArray[3] = puzzleArray[7];
	tempPuzzleArray[4] = puzzleArray[4];
	tempPuzzleArray[5] = puzzleArray[1];
	tempPuzzleArray[6] = puzzleArray[8];
	tempPuzzleArray[7] = puzzleArray[5];
	tempPuzzleArray[8] = puzzleArray[2];

	// 보드의 구성을 업데이트
	for (int j = 0; j < 9; j++)
		puzzleArray[j] = tempPuzzleArray[j];
}

// 현재 보드를 출력
void Board::printBoard() {
	for (int i = 0; i < 9; i += 3) {
		cout << puzzleArray[i].name << "(" << puzzleArray[i].rotation << ") ";
		cout << puzzleArray[i + 1].name << "(" << puzzleArray[i + 1].rotation << ") ";
		cout << puzzleArray[i + 2].name << "(" << puzzleArray[i + 2].rotation << ") ";
	}
	cout << "\n";
}

// 현재 보드의 두 퍼즐 위치를 변경한다.
// 인덱스 x와 y를 가진 두 퍼즐
void Board::swap(int x, int y) {
	Puzzle temp = puzzleArray[x];
	puzzleArray[x] = puzzleArray[y];
	puzzleArray[y] = temp;
}


// 현재 사용중인 퍼즐을 시계 방향으로 회전시킨다.
void Board::rotatePuzzle(int tileNum) {
	// 현재 퍼즐의 마지막 면(3번째)의 숫자를 temp에 저장
	int temp = puzzleArray[tileNum].numArray[3];
	// 뒤에서 두 번째부터 첫 번째까지 반복 
	for (int k = 3; k > 0; k--) {
		puzzleArray[tileNum].numArray[k] = puzzleArray[tileNum].numArray[k - 1];
	}
	// 첫 번째에 마지막 값을 넣어 회전시킨다.
	puzzleArray[tileNum].numArray[0] = temp;

	// 현재 퍼즐의 회전상태가 3이라면 (전부 회전했다면) 0으로 초기화
	// 처음으로 돌아감
	if (puzzleArray[tileNum].rotation == 0)
		puzzleArray[tileNum].rotation = 3;
	// 아니라면 (0,1,2라면) 회전상태를 +1한다
	else
		puzzleArray[tileNum].rotation--;
}

// 현재 사용중인 퍼즐을 반시계 방향으로 회전시킨다.
void Board::counter_rotatePuzzle(int tileNum) {
	// 현재 퍼즐의 마지막 면(3번째)의 숫자를 temp에 저장
	int temp = puzzleArray[tileNum].numArray[0];
	// 뒤에서 두 번째부터 첫 번째까지 반복 
	for (int k = 0; k < 3; k++) {
		puzzleArray[tileNum].numArray[k] = puzzleArray[tileNum].numArray[k + 1];
	}
	// 첫 번째에 마지막 값을 넣어 회전시킨다.
	puzzleArray[tileNum].numArray[3] = temp;

	// 현재 퍼즐의 회전상태가 3이라면 (전부 회전했다면) 0으로 초기화
	// 처음으로 돌아감
	if (puzzleArray[tileNum].rotation == 3)
		puzzleArray[tileNum].rotation = 0;
	// 아니라면 (0,1,2라면) 회전상태를 +1한다
	else
		puzzleArray[tileNum].rotation++;
}

// 현재 배치하려는 퍼즐의 가장자리(edge)를
// "배치된" 이웃한 퍼즐의 가장자리와 비교
bool Board::edgesMatch(int position) {
	// position(0) : 첫번째 위치는 비교할 것이 없다.
	// 1부터 8까지만 비교
	switch (position) {

	case 1: return ((puzzleArray[0].numArray[1] == 1 && puzzleArray[1].numArray[3] == 2) ||		// 0번 우측 - 1번 좌측
		(puzzleArray[0].numArray[1] == 2 && puzzleArray[1].numArray[3] == 1) ||
		(puzzleArray[0].numArray[1] == 3 && puzzleArray[1].numArray[3] == 4) ||
		(puzzleArray[0].numArray[1] == 4 && puzzleArray[1].numArray[3] == 3) ||
		(puzzleArray[0].numArray[1] == 5 && puzzleArray[1].numArray[3] == 6) ||
		(puzzleArray[0].numArray[1] == 6 && puzzleArray[1].numArray[3] == 5) ||
		(puzzleArray[0].numArray[1] == 7 && puzzleArray[1].numArray[3] == 8) ||
		(puzzleArray[0].numArray[1] == 8 && puzzleArray[1].numArray[3] == 7));

	case 2: return ((puzzleArray[1].numArray[1] == 1 && puzzleArray[2].numArray[3] == 2) ||		// 1번 우측 - 2번 좌측 
		(puzzleArray[1].numArray[1] == 2 && puzzleArray[2].numArray[3] == 1) ||
		(puzzleArray[1].numArray[1] == 3 && puzzleArray[2].numArray[3] == 4) ||
		(puzzleArray[1].numArray[1] == 4 && puzzleArray[2].numArray[3] == 3) ||
		(puzzleArray[1].numArray[1] == 5 && puzzleArray[2].numArray[3] == 6) ||
		(puzzleArray[1].numArray[1] == 6 && puzzleArray[2].numArray[3] == 5) ||
		(puzzleArray[1].numArray[1] == 7 && puzzleArray[2].numArray[3] == 8) ||
		(puzzleArray[1].numArray[1] == 8 && puzzleArray[2].numArray[3] == 7));

	case 3: return ((puzzleArray[0].numArray[2] == 1 && puzzleArray[3].numArray[0] == 2) ||		// 0번 하단 - 3번 상단
		(puzzleArray[0].numArray[2] == 2 && puzzleArray[3].numArray[0] == 1) ||
		(puzzleArray[0].numArray[2] == 3 && puzzleArray[3].numArray[0] == 4) ||
		(puzzleArray[0].numArray[2] == 4 && puzzleArray[3].numArray[0] == 3) ||
		(puzzleArray[0].numArray[2] == 5 && puzzleArray[3].numArray[0] == 6) ||
		(puzzleArray[0].numArray[2] == 6 && puzzleArray[3].numArray[0] == 5) ||
		(puzzleArray[0].numArray[2] == 7 && puzzleArray[3].numArray[0] == 8) ||
		(puzzleArray[0].numArray[2] == 8 && puzzleArray[3].numArray[0] == 7));

	case 4: return (((puzzleArray[3].numArray[1] == 1 && puzzleArray[4].numArray[3] == 2) ||  // 3번 우측 - 4번 좌측
		(puzzleArray[3].numArray[1] == 2 && puzzleArray[4].numArray[3] == 1) ||			  // 1번 하단 - 4번 상단
		(puzzleArray[3].numArray[1] == 3 && puzzleArray[4].numArray[3] == 4) ||
		(puzzleArray[3].numArray[1] == 4 && puzzleArray[4].numArray[3] == 3) ||
		(puzzleArray[3].numArray[1] == 5 && puzzleArray[4].numArray[3] == 6) ||
		(puzzleArray[3].numArray[1] == 6 && puzzleArray[4].numArray[3] == 5) ||
		(puzzleArray[3].numArray[1] == 7 && puzzleArray[4].numArray[3] == 8) ||
		(puzzleArray[3].numArray[1] == 8 && puzzleArray[4].numArray[3] == 7)) &&
		((puzzleArray[1].numArray[2] == 1 && puzzleArray[4].numArray[0] == 2) ||
			(puzzleArray[1].numArray[2] == 2 && puzzleArray[4].numArray[0] == 1) ||
			(puzzleArray[1].numArray[2] == 3 && puzzleArray[4].numArray[0] == 4) ||
			(puzzleArray[1].numArray[2] == 4 && puzzleArray[4].numArray[0] == 3) ||
			(puzzleArray[1].numArray[2] == 5 && puzzleArray[4].numArray[0] == 6) ||
			(puzzleArray[1].numArray[2] == 6 && puzzleArray[4].numArray[0] == 5) ||
			(puzzleArray[1].numArray[2] == 7 && puzzleArray[4].numArray[0] == 8) ||
			(puzzleArray[1].numArray[2] == 8 && puzzleArray[4].numArray[0] == 7)));

	case 5: return (((puzzleArray[4].numArray[1] == 1 && puzzleArray[5].numArray[3] == 2) ||  // 4번 우측 - 5번 좌측
		(puzzleArray[4].numArray[1] == 2 && puzzleArray[5].numArray[3] == 1) ||		  // 2번 하단 - 5번 상단
		(puzzleArray[4].numArray[1] == 3 && puzzleArray[5].numArray[3] == 4) ||
		(puzzleArray[4].numArray[1] == 4 && puzzleArray[5].numArray[3] == 3) ||
		(puzzleArray[4].numArray[1] == 5 && puzzleArray[5].numArray[3] == 6) ||
		(puzzleArray[4].numArray[1] == 6 && puzzleArray[5].numArray[3] == 5) ||
		(puzzleArray[4].numArray[1] == 7 && puzzleArray[5].numArray[3] == 8) ||
		(puzzleArray[4].numArray[1] == 8 && puzzleArray[5].numArray[3] == 7)) &&
		((puzzleArray[2].numArray[2] == 1 && puzzleArray[5].numArray[0] == 2) ||
			(puzzleArray[2].numArray[2] == 2 && puzzleArray[5].numArray[0] == 1) ||
			(puzzleArray[2].numArray[2] == 3 && puzzleArray[5].numArray[0] == 4) ||
			(puzzleArray[2].numArray[2] == 4 && puzzleArray[5].numArray[0] == 3) ||
			(puzzleArray[2].numArray[2] == 5 && puzzleArray[5].numArray[0] == 6) ||
			(puzzleArray[2].numArray[2] == 6 && puzzleArray[5].numArray[0] == 5) ||
			(puzzleArray[2].numArray[2] == 7 && puzzleArray[5].numArray[0] == 8) ||
			(puzzleArray[2].numArray[2] == 8 && puzzleArray[5].numArray[0] == 7)));

	case 6: return (puzzleArray[3].numArray[2] == 1 && puzzleArray[6].numArray[0] == 2) ||		// 3번 하단 - 6번 상단
		(puzzleArray[3].numArray[2] == 2 && puzzleArray[6].numArray[0] == 1) ||
		(puzzleArray[3].numArray[2] == 3 && puzzleArray[6].numArray[0] == 4) ||
		(puzzleArray[3].numArray[2] == 4 && puzzleArray[6].numArray[0] == 3) ||
		(puzzleArray[3].numArray[2] == 5 && puzzleArray[6].numArray[0] == 6) ||
		(puzzleArray[3].numArray[2] == 6 && puzzleArray[6].numArray[0] == 5) ||
		(puzzleArray[3].numArray[2] == 7 && puzzleArray[6].numArray[0] == 8) ||
		(puzzleArray[3].numArray[2] == 8 && puzzleArray[6].numArray[0] == 7);

	case 7: return (((puzzleArray[6].numArray[1] == 1 && puzzleArray[7].numArray[3] == 2) ||  // 6번 우측 - 7번 좌측
		(puzzleArray[6].numArray[1] == 2 && puzzleArray[7].numArray[3] == 1) ||		  // 4번 하단 - 7번 상단
		(puzzleArray[6].numArray[1] == 3 && puzzleArray[7].numArray[3] == 4) ||
		(puzzleArray[6].numArray[1] == 4 && puzzleArray[7].numArray[3] == 3) ||
		(puzzleArray[6].numArray[1] == 5 && puzzleArray[7].numArray[3] == 6) ||
		(puzzleArray[6].numArray[1] == 6 && puzzleArray[7].numArray[3] == 5) ||
		(puzzleArray[6].numArray[1] == 7 && puzzleArray[7].numArray[3] == 8) ||
		(puzzleArray[6].numArray[1] == 8 && puzzleArray[7].numArray[3] == 7)) &&
		((puzzleArray[4].numArray[2] == 1 && puzzleArray[7].numArray[0] == 2) ||
			(puzzleArray[4].numArray[2] == 2 && puzzleArray[7].numArray[0] == 1) ||
			(puzzleArray[4].numArray[2] == 3 && puzzleArray[7].numArray[0] == 4) ||
			(puzzleArray[4].numArray[2] == 4 && puzzleArray[7].numArray[0] == 3) ||
			(puzzleArray[4].numArray[2] == 5 && puzzleArray[7].numArray[0] == 6) ||
			(puzzleArray[4].numArray[2] == 6 && puzzleArray[7].numArray[0] == 5) ||
			(puzzleArray[4].numArray[2] == 7 && puzzleArray[7].numArray[0] == 8) ||
			(puzzleArray[4].numArray[2] == 8 && puzzleArray[7].numArray[0] == 7)));

	case 8: return (((puzzleArray[7].numArray[1] == 1 && puzzleArray[8].numArray[3] == 2) ||  // 7번 우측 - 8번 좌측
		(puzzleArray[7].numArray[1] == 2 && puzzleArray[8].numArray[3] == 1) ||		  // 5번 하단 - 8번 상단
		(puzzleArray[7].numArray[1] == 3 && puzzleArray[8].numArray[3] == 4) ||
		(puzzleArray[7].numArray[1] == 4 && puzzleArray[8].numArray[3] == 3) ||
		(puzzleArray[7].numArray[1] == 5 && puzzleArray[8].numArray[3] == 6) ||
		(puzzleArray[7].numArray[1] == 6 && puzzleArray[8].numArray[3] == 5) ||
		(puzzleArray[7].numArray[1] == 7 && puzzleArray[8].numArray[3] == 8) ||
		(puzzleArray[7].numArray[1] == 8 && puzzleArray[8].numArray[3] == 7)) &&
		((puzzleArray[5].numArray[2] == 1 && puzzleArray[8].numArray[0] == 2) ||
			(puzzleArray[5].numArray[2] == 2 && puzzleArray[8].numArray[0] == 1) ||
			(puzzleArray[5].numArray[2] == 3 && puzzleArray[8].numArray[0] == 4) ||
			(puzzleArray[5].numArray[2] == 4 && puzzleArray[8].numArray[0] == 3) ||
			(puzzleArray[5].numArray[2] == 5 && puzzleArray[8].numArray[0] == 6) ||
			(puzzleArray[5].numArray[2] == 6 && puzzleArray[8].numArray[0] == 5) ||
			(puzzleArray[5].numArray[2] == 7 && puzzleArray[8].numArray[0] == 8) ||
			(puzzleArray[5].numArray[2] == 8 && puzzleArray[8].numArray[0] == 7)));

	default: return true; // 해당 조건이 아니면 true 반환
	}
}

Board::~Board() {}


int main() {
	// 코드의 속도를 더 빠르게 하기 위한 작업
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Board puzzle;
	for (int i = 0; i < 9; i++) {
		Puzzle tPuzzle;
		tPuzzle.name = to_string(i + 1); // 퍼즐의 번호
		for (int j = 0; j < 4; j++) {
			cin >> tPuzzle.numArray[j]; // 각 면의 값 입력
		}
		puzzle.puzzleArray[i] = tPuzzle;
	}
	cout << endl;
	puzzle.solve(0);

	// 하나의 솔루션 당 보드를 회전하면 총 4개의 솔루션이 생김
	// 보드를 회전시켜 각 솔루션 출력
	cout << solution_count * 4 << "\n";
	for (int i = 0; i < solution_count; i++) {
		for (int j = 0; j < 4; j++) {
			solutions[i].printBoard();
			solutions[i].rotateBoard();
		}
	}

	return 0;
}