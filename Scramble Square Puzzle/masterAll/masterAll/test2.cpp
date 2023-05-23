#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tile {
	string name; // Ÿ���� ��ȣ
	int numArray[4]; // Ÿ���� �� ���� ��
	int rotation = 0; // �ݽð� ���� ȸ�� Ƚ��
};

// Ŭ���� ����
class Magic_Tiles {
public:
	Magic_Tiles();
	bool solve(int index); // ���� Ǫ�� �Լ�, ��Ʈ��ŷ
	void rotateBoard(); // ���� ��ü�� ȸ��
	void printBoard(); // ���� ������ ���� ���
	void swap(int x, int y); // �ΰ��� Ÿ�� ��ȯ
	void rotateTile(int tileNum); // Ÿ���� �ð� �������� ȸ��
	void conter_rotateTile(int tileNum); // Ÿ���� �ݽð� �������� ȸ��
	bool edgesMatch(int position); // �ֺ� Ÿ���� �����ڸ��� ���� ��
	~Magic_Tiles();

//private:
	//bool found = false;
	Tile tileArray[9]; // ���忡�� 9���� Ÿ�� ����
};

int solution_count = 0; // ���� ����, ���߿� *4 �ؼ� ���
vector<Magic_Tiles> solutions(512);

Magic_Tiles::Magic_Tiles() {
//	for (int i = 0; i < 9; i++) {
//		Tile aTile;
//		aTile.name = to_string(i + 1); // ������ ��ȣ
//		for (int j = 0; j < 4; j++) {
//			cin >> aTile.numArray[j]; // �� ���� �� �Է�
//		}
//		tileArray[i] = aTile;
//	}
//	cout << endl;
}

bool Magic_Tiles::solve(int index) {
	if (index == 9) {
		solution_count++;
		for (int i = 1; i < 5; i++) {
			printBoard();
			rotateBoard();
		}
		return true;

		//int check = 0;
		//if (solution_count == 0) {
		//	solution_count++;
		//	for (int i = 1; i < 5; i++) {
		//		printBoard();
		//		rotateBoard();
		//	}
		//	for (int i = 0; i < 9; i++) {
		//			solutions[solution_count].tileArray[i].name = tileArray[i].name;
		//			solutions[solution_count].tileArray[i].rotation = tileArray[i].rotation;
		//		for (int j = 0; j < 4; j++) {
		//			solutions[solution_count].tileArray[i].numArray[j] = tileArray[i].numArray[j];
		//		}
		//	}
		//	return true;
		//}
		//else {
		//	for (int k = 0; k < solution_count; k++) {
		//		for (int t = 0; t < 4; t++) {
		//			for (int i = 0; i < 9; i++) {
		//				for (int j = 0; j < 4; j++) {
		//					if ((solutions[k].tileArray[i].name != tileArray[i].name) ||
		//						(solutions[k].tileArray[i].numArray[j] != tileArray[i].rotation) ||
		//						(solutions[k].tileArray[i].rotation != tileArray[i].numArray[j]))
		//						check = 1;
		//					//return false;
		//				}
		//			}
		//			rotateBoard();
		//		}
		//	}
		//}
		//if (check == 0)
		//	return false;
		//else if (check == 1) {
		//	solution_count++;
		//	for (int i = 0; i < 9; i++) {
		//		solutions[solution_count].tileArray[i].name = tileArray[i].name;
		//		solutions[solution_count].tileArray[i].rotation = tileArray[i].rotation;
		//		for (int j = 0; j < 4; j++) {
		//			solutions[solution_count].tileArray[i].numArray[j] = tileArray[i].numArray[j];
		//		}
		//	}
		//	for (int i = 1; i < 5; i++) {
		//		printBoard();
		//		rotateBoard();
		//	}
		//	return true;
		//}
	}
	else {
		for (int i = index; i < 9; i++) {
			swap(index, i);
			for (int j = 0; j < 4; j++) {
				if (index == 0) {
					if (!solve(index + 1)) {
						rotateTile(index);
						return false;
					}
				}
				else if (edgesMatch(index)) {
					if (solve(index + 1)) {
						swap(index, i);
						return true;
					}
				}
				else {
					conter_rotateTile(index);
				}
			}
			swap(index, i);
		}
		return false;
	}
}



//void Magic_Tiles::solve(int index) {
//	if (found) { // found��� ��͸� �����ϰ� �Լ��� ��ȯ�Ѵ�
//		//found == false;
//		return;
//	}
//
//	// index �� 9�� �����ϸ� ��� �񱳴� ������ �ǰ� �ذ� �߰ߵȴ�.
//	// ����� ����ϰ� found�� ������ �ϰ� ��ȯ�Ѵ�.
//	else if (index == 9) {
//		// ù��° �ַ�� ���
//		solution_count++;
//		for (int i = 1; i < 5; i++) {
//			printBoard();
//			rotateBoard();
//		}
//		found = true;
//		return;
//	}
//
//	else {
//		for (int i = index; i < 9; i++) {
//			swap(index, i);
//			for (int j = 0; j < 4; j++) {
//				// ����Ÿ���� ��ġ�ϸ� solve(index + 1) ȣ��
//				// �ƴϸ� ���� Ÿ���� ȸ����Ų��.
//
//				// ù ��° Ÿ���� ���� ���� ����
//				if (index == 0) {
//					solve(index + 1);
//					if (!found)
//						rotateTile(index);
//				}
//				// �� ��°���� ��ȩ ��° Ÿ���� ���
//				// ���� ��ġ�� ��ġ�� Ÿ���� �����ڸ��� �̿��ϴ�
//				// Ÿ���� �����ڸ��� ��ġ�ؾ� �Ѵ�
//				else if (edgesMatch(index)) {
//					found == false;
//					solve(index + 1);
//				}
//				// �ٸ� Ÿ���� ��ġ�ϱ� ���� ���� Ÿ���� ȸ������ ��ġ�ϴ��� Ȯ��
//				else
//					conter_rotateTile(index);
//			}
//
//			// �ַ���� �߰ߵǸ� ��� ��ȯ
//			if (found) {
//				//found == false;
//				return;
//			}
//			// �ַ���� ������ swap ȣ���Ͽ� ���� Ÿ�Ϸ� ����
//			else
//				swap(index, i);
//		}
//	}
//}

// ���� ��ü�� ȸ������ �ٸ� �ַ���� ǥ���Ѵ�
void Magic_Tiles::rotateBoard() {
	// ȸ���� ���带 �ӽ÷� ����
	Tile tempTileArray[9];
	// ��� Ÿ���� ȸ����Ų��
	// ������ ������ ȸ���� ���·� ����
	for (int i = 0; i < 9; i++)
		rotateTile(i);

	// �ð�������� ȸ��(90��)
	tempTileArray[0] = tileArray[6];
	tempTileArray[1] = tileArray[3];
	tempTileArray[2] = tileArray[0];
	tempTileArray[3] = tileArray[7];
	tempTileArray[4] = tileArray[4];
	tempTileArray[5] = tileArray[1];
	tempTileArray[6] = tileArray[8];
	tempTileArray[7] = tileArray[5];
	tempTileArray[8] = tileArray[2];

	// ������ ������ ������Ʈ
	for (int j = 0; j < 9; j++)
		tileArray[j] = tempTileArray[j];
}

// ���� ���带 ���
void Magic_Tiles::printBoard() {
	for (int i = 0; i < 9; i += 3) {
		cout << tileArray[i].name << "(" << tileArray[i].rotation << ") ";
		cout << tileArray[i + 1].name << "(" << tileArray[i + 1].rotation << ") ";
		cout << tileArray[i + 2].name << "(" << tileArray[i + 2].rotation << ") ";
	}
	cout << "\n";
}

// ���� ������ �� Ÿ�� ��ġ�� �����Ѵ�.
// �ε��� x�� y�� ���� �� Ÿ��
void Magic_Tiles::swap(int x, int y) {
	Tile temp = tileArray[x];
	tileArray[x] = tileArray[y];
	tileArray[y] = temp;
}


// ���� ������� Ÿ���� �ð� �������� ȸ����Ų��.
void Magic_Tiles::rotateTile(int tileNum) {
	// ���� Ÿ���� ������ ��(3��°)�� ���ڸ� temp�� ����
	int temp = tileArray[tileNum].numArray[3];
	// �ڿ��� �� ��°���� ù ��°���� �ݺ� 
	for (int k = 3; k > 0; k--) {
		tileArray[tileNum].numArray[k] = tileArray[tileNum].numArray[k - 1];
	}
	// ù ��°�� ������ ���� �־� ȸ����Ų��.
	tileArray[tileNum].numArray[0] = temp;

	// ���� Ÿ���� ȸ�����°� 3�̶�� (���� ȸ���ߴٸ�) 0���� �ʱ�ȭ
	// ó������ ���ư�
	if (tileArray[tileNum].rotation == 0)
		tileArray[tileNum].rotation = 3;
	// �ƴ϶�� (0,1,2���) ȸ�����¸� +1�Ѵ�
	else
		tileArray[tileNum].rotation--;
}

// ���� ������� Ÿ���� �ݽð� �������� ȸ����Ų��.
void Magic_Tiles::conter_rotateTile(int tileNum) {
	// ���� Ÿ���� ������ ��(3��°)�� ���ڸ� temp�� ����
	int temp = tileArray[tileNum].numArray[0];
	// �ڿ��� �� ��°���� ù ��°���� �ݺ� 
	for (int k = 0; k < 3; k++) {
		tileArray[tileNum].numArray[k] = tileArray[tileNum].numArray[k + 1];
	}
	// ù ��°�� ������ ���� �־� ȸ����Ų��.
	tileArray[tileNum].numArray[3] = temp;

	// ���� Ÿ���� ȸ�����°� 3�̶�� (���� ȸ���ߴٸ�) 0���� �ʱ�ȭ
	// ó������ ���ư�
	if (tileArray[tileNum].rotation == 3)
		tileArray[tileNum].rotation = 0;
	// �ƴ϶�� (0,1,2���) ȸ�����¸� +1�Ѵ�
	else
		tileArray[tileNum].rotation++;
}

// ���� ��ġ�Ϸ��� Ÿ���� �����ڸ�(edge)��
// "��ġ��" �̿��� Ÿ���� �����ڸ��� ��
bool Magic_Tiles::edgesMatch(int position) {
	// position(0) : ù��° ��ġ�� ���� ���� ����.
	// 1���� 8������ ��
	switch (position) {

	case 1: return ((tileArray[0].numArray[1] == 1 && tileArray[1].numArray[3] == 2) ||		// 0�� ���� - 1�� ����
		(tileArray[0].numArray[1] == 2 && tileArray[1].numArray[3] == 1) ||
		(tileArray[0].numArray[1] == 3 && tileArray[1].numArray[3] == 4) ||
		(tileArray[0].numArray[1] == 4 && tileArray[1].numArray[3] == 3) ||
		(tileArray[0].numArray[1] == 5 && tileArray[1].numArray[3] == 6) ||
		(tileArray[0].numArray[1] == 6 && tileArray[1].numArray[3] == 5) ||
		(tileArray[0].numArray[1] == 7 && tileArray[1].numArray[3] == 8) ||
		(tileArray[0].numArray[1] == 8 && tileArray[1].numArray[3] == 7));

	case 2: return ((tileArray[1].numArray[1] == 1 && tileArray[2].numArray[3] == 2) ||		// 1�� ���� - 2�� ���� 
		(tileArray[1].numArray[1] == 2 && tileArray[2].numArray[3] == 1) ||
		(tileArray[1].numArray[1] == 3 && tileArray[2].numArray[3] == 4) ||
		(tileArray[1].numArray[1] == 4 && tileArray[2].numArray[3] == 3) ||
		(tileArray[1].numArray[1] == 5 && tileArray[2].numArray[3] == 6) ||
		(tileArray[1].numArray[1] == 6 && tileArray[2].numArray[3] == 5) ||
		(tileArray[1].numArray[1] == 7 && tileArray[2].numArray[3] == 8) ||
		(tileArray[1].numArray[1] == 8 && tileArray[2].numArray[3] == 7));

	case 3: return ((tileArray[0].numArray[2] == 1 && tileArray[3].numArray[0] == 2) ||		// 0�� �ϴ� - 3�� ���
		(tileArray[0].numArray[2] == 2 && tileArray[3].numArray[0] == 1) ||
		(tileArray[0].numArray[2] == 3 && tileArray[3].numArray[0] == 4) ||
		(tileArray[0].numArray[2] == 4 && tileArray[3].numArray[0] == 3) ||
		(tileArray[0].numArray[2] == 5 && tileArray[3].numArray[0] == 6) ||
		(tileArray[0].numArray[2] == 6 && tileArray[3].numArray[0] == 5) ||
		(tileArray[0].numArray[2] == 7 && tileArray[3].numArray[0] == 8) ||
		(tileArray[0].numArray[2] == 8 && tileArray[3].numArray[0] == 7));

	case 4: return (((tileArray[3].numArray[1] == 1 && tileArray[4].numArray[3] == 2) ||  // 3�� ���� - 4�� ����
		(tileArray[3].numArray[1] == 2 && tileArray[4].numArray[3] == 1) ||			  // 1�� �ϴ� - 4�� ���
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

	case 5: return (((tileArray[4].numArray[1] == 1 && tileArray[5].numArray[3] == 2) ||  // 4�� ���� - 5�� ����
		(tileArray[4].numArray[1] == 2 && tileArray[5].numArray[3] == 1) ||		  // 2�� �ϴ� - 5�� ���
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

	case 6: return (tileArray[3].numArray[2] == 1 && tileArray[6].numArray[0] == 2) ||		// 3�� �ϴ� - 6�� ���
		(tileArray[3].numArray[2] == 2 && tileArray[6].numArray[0] == 1) ||
		(tileArray[3].numArray[2] == 3 && tileArray[6].numArray[0] == 4) ||
		(tileArray[3].numArray[2] == 4 && tileArray[6].numArray[0] == 3) ||
		(tileArray[3].numArray[2] == 5 && tileArray[6].numArray[0] == 6) ||
		(tileArray[3].numArray[2] == 6 && tileArray[6].numArray[0] == 5) ||
		(tileArray[3].numArray[2] == 7 && tileArray[6].numArray[0] == 8) ||
		(tileArray[3].numArray[2] == 8 && tileArray[6].numArray[0] == 7);

	case 7: return (((tileArray[6].numArray[1] == 1 && tileArray[7].numArray[3] == 2) ||  // 6�� ���� - 7�� ����
		(tileArray[6].numArray[1] == 2 && tileArray[7].numArray[3] == 1) ||		  // 4�� �ϴ� - 7�� ���
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

	case 8: return (((tileArray[7].numArray[1] == 1 && tileArray[8].numArray[3] == 2) ||  // 7�� ���� - 8�� ����
		(tileArray[7].numArray[1] == 2 && tileArray[8].numArray[3] == 1) ||		  // 5�� �ϴ� - 8�� ���
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

	default: return true; // �����ڸ� �񱳸� �������� �ʾƵ� �Ǵ� ���� true ��ȯ
	}
}

Magic_Tiles::~Magic_Tiles() {}


int main() {
	Magic_Tiles puzzle;
	for (int i = 0; i < 9; i++) {
		Tile aTile;
		aTile.name = to_string(i + 1); // ������ ��ȣ
		for (int j = 0; j < 4; j++) {
			cin >> aTile.numArray[j]; // �� ���� �� �Է�
		}
		puzzle.tileArray[i] = aTile;
	}
	cout << endl;
	puzzle.solve(0);

	// �ϳ��� �ַ�� �� ���带 ȸ���ϸ� �� 4���� �ַ���� ����
	// ���带 ȸ������ �� �ַ�� ���
	cout << solution_count * 4 << "\n";

	//for (int i = 1; i < 5; i++) {
	//	puzzle.printBoard();
	//	puzzle.rotateBoard();
	//}

	return 0;
}