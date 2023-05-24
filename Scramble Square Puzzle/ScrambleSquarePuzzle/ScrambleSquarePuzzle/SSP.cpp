#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Puzzle {
	string name; // ������ ��ȣ
	int numArray[4]; // ������ �� ���� ��
	int rotation = 0; // �ݽð� ���� ȸ�� Ƚ��
};

// Ŭ���� ����
class Board {
public:
	Board(); // ������
	bool solve(int index); // ���� Ǫ�� �Լ�, ��Ʈ��ŷ
	void rotateBoard(); // ���� ��ü�� ȸ��
	void printBoard(); // ���� ������ ���� ���
	void swap(int x, int y); // �ΰ��� ���� ��ȯ
	void rotatePuzzle(int tileNum); // ������ �ð� �������� ȸ��
	void counter_rotatePuzzle(int tileNum); // ������ �ݽð� �������� ȸ��
	bool edgesMatch(int position); // �ֺ� ������ �����ڸ��� ���� ��
	~Board(); // �Ҹ���

	Puzzle puzzleArray[9]; // ���忡�� 9���� ���� ����
};

// ��������
// ���� ����, ���߿� *4 �ؼ� ���
int solution_count = 0;
// �ذ� �Ǵ� ���񺸵带 ����, �ִ� 2^9 ������ ������ �� �ֵ��� ����
vector<Board> solutions(512);

Board::Board() { }

// ��Ʈ��ŷ�� �̿��Ͽ� ������ ���ߴ� �ظ� ����
bool Board::solve(int index) {
	if (index == 9) {
		int check = 0;
		if (solution_count == 0) { // ù��° �ض�� �񱳾��� �ٷ� �߰�
			for (int i = 0; i < 9; i++) { // 9���� ���� ������ solutions ���Ϳ� �߰�
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
			for (int k = 0; k < solution_count; k++) { // ���� ����� solutions���Ϳ� �ִ� ���带 ��
				for (int t = 0; t < 4; t++) {
					int boardCheck = 0;
					for (int i = 0; i < 9; i++) {
						int sideCheck = 0;
						for (int j = 0; j < 4; j++) {
							if ((solutions[k].puzzleArray[i].name == puzzleArray[i].name) ||
								(solutions[k].puzzleArray[i].numArray[j] == puzzleArray[i].numArray[j]) ||
								(solutions[k].puzzleArray[i].rotation == puzzleArray[i].rotation)) {
								sideCheck++; // ���� ���� �´ٸ� ����
							}
						}
						if (sideCheck == 4) // ��� ���� ���� ���
							boardCheck++;
					}
					rotateBoard(); // 4�� ȸ���ϸ� ��� �ٸ��� üũ
					if (boardCheck == 9) { // 9���� ������ ��� ���� ���
						check = 1; // �߰����� ����
					}
				}
			}
		}
		if (check == 1)
			return true; // �߰����� �ʰ� ��ȯ
		else if (check == 0) { // ���� �ʴٸ� �߰�
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
				// ���� ���������� ��ġ�ϸ� solve(index + 1)ȣ��
				// �ƴϸ� ���� ���������� ȸ����Ų��

				// ù ��° ������ ���� ���� ����
				if (index == 0) {
					if (!solve(index + 1)) {
						rotatePuzzle(index);
					}
				}
				// �� ��°���� ��ȩ ��° ������ ���
				// ���� ��ġ�� ��ġ�� ������ �����ڸ��� �̿��ϴ�
				// ������ �����ڸ��� ��ġ�ؾ� �Ѵ�
				else if (edgesMatch(index)) {
					if (solve(index + 1)) {
						return true;
					}
				}
				// �ٸ� ������ ��ġ�ϱ� ���� ���� ������ ȸ������ ��ġ�ϴ��� Ȯ��
				else {
					counter_rotatePuzzle(index);
				}
			}
			// �ַ���� ������ swap�� ���� ���� ����� ����
			swap(index, i);
		}
		return false;
	}
}

// ���� ��ü�� ȸ������ �ٸ� �ַ���� ǥ���Ѵ�
void Board::rotateBoard() {
	// ȸ���� ���带 �ӽ÷� ����
	Puzzle tempPuzzleArray[9];
	// ��� ������ ȸ����Ų��
	// ������ ������ ȸ���� ���·� ����
	for (int i = 0; i < 9; i++)
		rotatePuzzle(i);

	// �ð�������� ȸ��(90��)
	tempPuzzleArray[0] = puzzleArray[6];
	tempPuzzleArray[1] = puzzleArray[3];
	tempPuzzleArray[2] = puzzleArray[0];
	tempPuzzleArray[3] = puzzleArray[7];
	tempPuzzleArray[4] = puzzleArray[4];
	tempPuzzleArray[5] = puzzleArray[1];
	tempPuzzleArray[6] = puzzleArray[8];
	tempPuzzleArray[7] = puzzleArray[5];
	tempPuzzleArray[8] = puzzleArray[2];

	// ������ ������ ������Ʈ
	for (int j = 0; j < 9; j++)
		puzzleArray[j] = tempPuzzleArray[j];
}

// ���� ���带 ���
void Board::printBoard() {
	for (int i = 0; i < 9; i += 3) {
		cout << puzzleArray[i].name << "(" << puzzleArray[i].rotation << ") ";
		cout << puzzleArray[i + 1].name << "(" << puzzleArray[i + 1].rotation << ") ";
		cout << puzzleArray[i + 2].name << "(" << puzzleArray[i + 2].rotation << ") ";
	}
	cout << "\n";
}

// ���� ������ �� ���� ��ġ�� �����Ѵ�.
// �ε��� x�� y�� ���� �� ����
void Board::swap(int x, int y) {
	Puzzle temp = puzzleArray[x];
	puzzleArray[x] = puzzleArray[y];
	puzzleArray[y] = temp;
}


// ���� ������� ������ �ð� �������� ȸ����Ų��.
void Board::rotatePuzzle(int tileNum) {
	// ���� ������ ������ ��(3��°)�� ���ڸ� temp�� ����
	int temp = puzzleArray[tileNum].numArray[3];
	// �ڿ��� �� ��°���� ù ��°���� �ݺ� 
	for (int k = 3; k > 0; k--) {
		puzzleArray[tileNum].numArray[k] = puzzleArray[tileNum].numArray[k - 1];
	}
	// ù ��°�� ������ ���� �־� ȸ����Ų��.
	puzzleArray[tileNum].numArray[0] = temp;

	// ���� ������ ȸ�����°� 3�̶�� (���� ȸ���ߴٸ�) 0���� �ʱ�ȭ
	// ó������ ���ư�
	if (puzzleArray[tileNum].rotation == 0)
		puzzleArray[tileNum].rotation = 3;
	// �ƴ϶�� (0,1,2���) ȸ�����¸� +1�Ѵ�
	else
		puzzleArray[tileNum].rotation--;
}

// ���� ������� ������ �ݽð� �������� ȸ����Ų��.
void Board::counter_rotatePuzzle(int tileNum) {
	// ���� ������ ������ ��(3��°)�� ���ڸ� temp�� ����
	int temp = puzzleArray[tileNum].numArray[0];
	// �ڿ��� �� ��°���� ù ��°���� �ݺ� 
	for (int k = 0; k < 3; k++) {
		puzzleArray[tileNum].numArray[k] = puzzleArray[tileNum].numArray[k + 1];
	}
	// ù ��°�� ������ ���� �־� ȸ����Ų��.
	puzzleArray[tileNum].numArray[3] = temp;

	// ���� ������ ȸ�����°� 3�̶�� (���� ȸ���ߴٸ�) 0���� �ʱ�ȭ
	// ó������ ���ư�
	if (puzzleArray[tileNum].rotation == 3)
		puzzleArray[tileNum].rotation = 0;
	// �ƴ϶�� (0,1,2���) ȸ�����¸� +1�Ѵ�
	else
		puzzleArray[tileNum].rotation++;
}

// ���� ��ġ�Ϸ��� ������ �����ڸ�(edge)��
// "��ġ��" �̿��� ������ �����ڸ��� ��
bool Board::edgesMatch(int position) {
	// position(0) : ù��° ��ġ�� ���� ���� ����.
	// 1���� 8������ ��
	switch (position) {

	case 1: return ((puzzleArray[0].numArray[1] == 1 && puzzleArray[1].numArray[3] == 2) ||		// 0�� ���� - 1�� ����
		(puzzleArray[0].numArray[1] == 2 && puzzleArray[1].numArray[3] == 1) ||
		(puzzleArray[0].numArray[1] == 3 && puzzleArray[1].numArray[3] == 4) ||
		(puzzleArray[0].numArray[1] == 4 && puzzleArray[1].numArray[3] == 3) ||
		(puzzleArray[0].numArray[1] == 5 && puzzleArray[1].numArray[3] == 6) ||
		(puzzleArray[0].numArray[1] == 6 && puzzleArray[1].numArray[3] == 5) ||
		(puzzleArray[0].numArray[1] == 7 && puzzleArray[1].numArray[3] == 8) ||
		(puzzleArray[0].numArray[1] == 8 && puzzleArray[1].numArray[3] == 7));

	case 2: return ((puzzleArray[1].numArray[1] == 1 && puzzleArray[2].numArray[3] == 2) ||		// 1�� ���� - 2�� ���� 
		(puzzleArray[1].numArray[1] == 2 && puzzleArray[2].numArray[3] == 1) ||
		(puzzleArray[1].numArray[1] == 3 && puzzleArray[2].numArray[3] == 4) ||
		(puzzleArray[1].numArray[1] == 4 && puzzleArray[2].numArray[3] == 3) ||
		(puzzleArray[1].numArray[1] == 5 && puzzleArray[2].numArray[3] == 6) ||
		(puzzleArray[1].numArray[1] == 6 && puzzleArray[2].numArray[3] == 5) ||
		(puzzleArray[1].numArray[1] == 7 && puzzleArray[2].numArray[3] == 8) ||
		(puzzleArray[1].numArray[1] == 8 && puzzleArray[2].numArray[3] == 7));

	case 3: return ((puzzleArray[0].numArray[2] == 1 && puzzleArray[3].numArray[0] == 2) ||		// 0�� �ϴ� - 3�� ���
		(puzzleArray[0].numArray[2] == 2 && puzzleArray[3].numArray[0] == 1) ||
		(puzzleArray[0].numArray[2] == 3 && puzzleArray[3].numArray[0] == 4) ||
		(puzzleArray[0].numArray[2] == 4 && puzzleArray[3].numArray[0] == 3) ||
		(puzzleArray[0].numArray[2] == 5 && puzzleArray[3].numArray[0] == 6) ||
		(puzzleArray[0].numArray[2] == 6 && puzzleArray[3].numArray[0] == 5) ||
		(puzzleArray[0].numArray[2] == 7 && puzzleArray[3].numArray[0] == 8) ||
		(puzzleArray[0].numArray[2] == 8 && puzzleArray[3].numArray[0] == 7));

	case 4: return (((puzzleArray[3].numArray[1] == 1 && puzzleArray[4].numArray[3] == 2) ||  // 3�� ���� - 4�� ����
		(puzzleArray[3].numArray[1] == 2 && puzzleArray[4].numArray[3] == 1) ||			  // 1�� �ϴ� - 4�� ���
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

	case 5: return (((puzzleArray[4].numArray[1] == 1 && puzzleArray[5].numArray[3] == 2) ||  // 4�� ���� - 5�� ����
		(puzzleArray[4].numArray[1] == 2 && puzzleArray[5].numArray[3] == 1) ||		  // 2�� �ϴ� - 5�� ���
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

	case 6: return (puzzleArray[3].numArray[2] == 1 && puzzleArray[6].numArray[0] == 2) ||		// 3�� �ϴ� - 6�� ���
		(puzzleArray[3].numArray[2] == 2 && puzzleArray[6].numArray[0] == 1) ||
		(puzzleArray[3].numArray[2] == 3 && puzzleArray[6].numArray[0] == 4) ||
		(puzzleArray[3].numArray[2] == 4 && puzzleArray[6].numArray[0] == 3) ||
		(puzzleArray[3].numArray[2] == 5 && puzzleArray[6].numArray[0] == 6) ||
		(puzzleArray[3].numArray[2] == 6 && puzzleArray[6].numArray[0] == 5) ||
		(puzzleArray[3].numArray[2] == 7 && puzzleArray[6].numArray[0] == 8) ||
		(puzzleArray[3].numArray[2] == 8 && puzzleArray[6].numArray[0] == 7);

	case 7: return (((puzzleArray[6].numArray[1] == 1 && puzzleArray[7].numArray[3] == 2) ||  // 6�� ���� - 7�� ����
		(puzzleArray[6].numArray[1] == 2 && puzzleArray[7].numArray[3] == 1) ||		  // 4�� �ϴ� - 7�� ���
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

	case 8: return (((puzzleArray[7].numArray[1] == 1 && puzzleArray[8].numArray[3] == 2) ||  // 7�� ���� - 8�� ����
		(puzzleArray[7].numArray[1] == 2 && puzzleArray[8].numArray[3] == 1) ||		  // 5�� �ϴ� - 8�� ���
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

	default: return true; // �ش� ������ �ƴϸ� true ��ȯ
	}
}

Board::~Board() {}


int main() {
	// �ڵ��� �ӵ��� �� ������ �ϱ� ���� �۾�
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Board puzzle;
	for (int i = 0; i < 9; i++) {
		Puzzle tPuzzle;
		tPuzzle.name = to_string(i + 1); // ������ ��ȣ
		for (int j = 0; j < 4; j++) {
			cin >> tPuzzle.numArray[j]; // �� ���� �� �Է�
		}
		puzzle.puzzleArray[i] = tPuzzle;
	}
	cout << endl;
	puzzle.solve(0);

	// �ϳ��� �ַ�� �� ���带 ȸ���ϸ� �� 4���� �ַ���� ����
	// ���带 ȸ������ �� �ַ�� ���
	cout << solution_count * 4 << "\n";
	for (int i = 0; i < solution_count; i++) {
		for (int j = 0; j < 4; j++) {
			solutions[i].printBoard();
			solutions[i].rotateBoard();
		}
	}

	return 0;
}