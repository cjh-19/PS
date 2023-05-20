#include <iostream>
#include <vector>

using namespace std;

struct PuzzlePiece {
	int id; // ���� ��ȣ
	vector<int> sides; // �� ���� ��
	int orientation; // ȸ�� ����
	int x; // ���� ��ġ
	int y; // ���� ��ġ
	// (x,y) = x�� y��
	PuzzlePiece(int id, const vector<int>& sides, int orientation, int x, int y) : id(id), sides(sides), orientation(orientation), x(x), y(y) {}
};

int count_solution = 0; // �ذ��� �� �ִ� ����� ��
vector<PuzzlePiece> pieces; // �Է����� �־��� 9���� �̹��� ������ �����ϴ� ����
vector<int> solution(9); // ������� ������ �������� ������ �����ϴ� ����
vector<bool> used(9, false); // �̹� ���� ������ ǥ���ϴ� ����

// ������ ���� ��ġ�� �̵��� �� �ִ��� Ȯ���ϴ� �Լ�
// ���� �����ʿ��� ��ġ���ִٸ� �̵��� �� �����Ƿ� false ��ȯ
bool nextLocal(int x, int width) {
	if (x < width - 1)
		return true;
	return false;
}

int getSide(PuzzlePiece piece, int side) {
	int num = piece.orientation;
	return piece.sides[(num + side - 1) % 4];
}

bool checkMove(vector<vector<PuzzlePiece>> puzzle, PuzzlePiece piece, int x, int y) {
	if (x > 0) {
		int side1 = getSide(puzzle[x - 1][y], 1);
		int side2 = getSide(piece, 3);
		if (!(side1 == 1 && side2 == 2) && !(side1 == 2 && side2 == 1) && !(side1 == 3 && side2 == 4) && !(side1 == 4 && side2 == 3) &&
			!(side1 == 5 && side2 == 6) && !(side1 == 6 && side2 == 5) && !(side1 == 7 && side2 == 8) && !(side1 == 8 && side2 == 7)) {
			return false;
		}
	}
	if (y > 0) {
		int side1 = getSide(puzzle[x][y - 1], 2);
		int side2 = getSide(piece, 0);
		if (!(side1 == 1 && side2 == 2) && !(side1 == 2 && side2 == 1) && !(side1 == 3 && side2 == 4) && !(side1 == 4 && side2 == 3) &&
			!(side1 == 5 && side2 == 6) && !(side1 == 6 && side2 == 5) && !(side1 == 7 && side2 == 8) && !(side1 == 8 && side2 == 7)) {
			return false;
		}
	}
	return true;
}

int getNumRows(vector<vector<PuzzlePiece>>& puzzle) {
	//if (puzzle.empty()) {
	//	return 0;
	//}
	cout << "x�� : " << puzzle.size() << "\n";
	return puzzle.size();
}

int getNumCols(vector<vector<PuzzlePiece>>& puzzle, int x) {
	
	return puzzle[x].size();
}

bool solvePuzzle(vector<vector<PuzzlePiece>>& puzzle, vector<PuzzlePiece>& pieces, int x, int y) {

	if (x == 3 && y == 3) {
		count_solution++;
		for (const auto& row : puzzle) {
			for (const auto& piece : row) {
				cout << piece.orientation + 1 << "(" << piece.orientation << ") ";
			}
			cout << endl;
		}
		//for (const auto& piece : pieces)
		//	cout << piece.orientation + 1 << "(" << piece.orientation << ")";
		//	
		//cout << "\n";
		return true;
	}

	for (int i = 0; i < pieces.size(); i++) {
		PuzzlePiece temp = pieces[i];

		if (temp.orientation != 0) {
			continue;
		}

		int curr_x = x;
		int curr_y = y;

		if (nextLocal(x, getNumCols(puzzle, x))) {
			x++;
		}
		else {
			y++;
			x = 0;
		}

		for (int j = 1; j <= 4; j++) {
			temp.orientation = j;
			if (checkMove(puzzle, temp, curr_x, curr_y)) {
				puzzle[curr_x][curr_y] = temp;
				if (solvePuzzle(puzzle, pieces, x, y)) {
					return true;
				}
				else {
					temp.orientation = 0;
				}
			}
		}
	}

	return false;
}

vector<vector<PuzzlePiece>> findSoln(vector<PuzzlePiece> pieces, int width) {
	vector<vector<PuzzlePiece>> soln;
	solvePuzzle(soln, pieces, 0, 0);

	cout << count_solution << "\n";

	return soln;
}

int main() {
	// ���� ���� �ޱ�
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		vector<int> sides(4);
		for (int j = 0; j < 4; j++)
			cin >> sides[j];
		pieces.emplace_back(i, sides, 0, x, y); // Piece ��ü�� �����ǰ� �ش� ��ü�� pieces ���Ͱ� �߰��ȴ�.
		x++;
		if (x == 4) {
			x = 0;
			y++;
		}
	}

	findSoln(pieces, 3);
	// solve(0);

	return 0;
}














//#include <iostream>
//#include <vector>
//#include <map>
//#include <sstream>
//
//using namespace std;
//
//enum class Part {
//	HEAD = 1,
//	TAIL = -1
//};
//
//enum class PartIndex {
//	ONE = 1,
//	TWO = 2,
//	THREE = 3,
//	FOUR = 4
//};
//
//class Side {
//private:
//	Part part;
//	PartIndex index;
//	
//public:
//	Side(Part part, PartIndex index) : part(part), index(index) {}
//
//	int getValue() const {
//		return static_cast<int>(part) * static_cast<int>(index);
//	}
//
//	bool canJoin(const Side& side) const {
//		if (&side == nullptr)
//			return true;
//		return getValue() + side.getValue() == 0;
//	}
//
//	string toString() const {
//		stringstream ss;
//		ss << static_cast<int>(part) << "-" << static_cast<int>(index);
//		return ss.str();
//	}
//
//	Side clone() const {
//		return Side(part, index);
//	}
//};
//
//class Card {
//private:
//	static int counter; // ���� ��� ������ ����Ͽ� ī�� �̸��� ���ϼ� ����
//	string name;
//	Side top;
//	Side left;
//	Side bottom;
//	Side right;
//
//public:
//	Card(Side top, Side left, Side bottom, Side right)
//		: name("Card" + to_string(counter++)), top(top), left(left), bottom(bottom), right(right) {}
//
//	// ���� ������
//	Card(const Card& other)
//		: name("Card" + to_string(counter++)),
//		top(other.top.clone()), left(other.left.clone()), bottom(other.bottom.clone()),right(other.right.clone()) {}
//	
//	// ���� ������
//	Card& operator=(const Card& other) {
//		if (this != &other) {
//			name = "Card" + to_string(counter++);
//			top = other.top.clone();
//			left = other.left.clone();
//			bottom = other.bottom.clone();
//			right = other.right.clone();
//		}
//		return *this;
//	}
//
//	bool isCompatible(const Card& leftCard, const Card& topCard) const {
//		if (&leftCard == nullptr && &topCard != nullptr) {
//			return top.canJoin(topCard.bottom);
//		}
//		else if (&left != nullptr && &topCard == nullptr) {
//			return left.canJoin(leftCard.right);
//		}
//		else if (&leftCard == nullptr && &topCard == nullptr) {
//			return true;
//		}
//		return left.canJoin(leftCard.right) && top.canJoin(topCard.bottom);
//	}
//
//	string toString() const {
//		return name;
//	}
//
//	Card clone() const {
//		return Card(top.clone(), left.clone(), bottom.clone(), right.clone());
//	}
//};
//
//int Card::counter = 1; // ���� ��� ���� �ʱ�ȭ
//
//class DraftSpace {
//private:
//	vector<vector<Card>> cards;
//	int dim;
//
//	int getRow(int pos) const {
//		return pos / dim;
//	}
//
//	int getColumn(int pos) const {
//		return pos % dim;
//	}
//
//	const Card* getLeftCard(int pos) const {
//		int r, c;
//		if (pos >= dim * dim) {
//			return nullptr;
//		}
//		r = getRow(pos);
//		c = getColumn(pos);
//		return &cards[r][c - 1];
//	}
//
//	const Card* getTopCard(int pos) const {
//		int r, c;
//		if (pos >= dim * dim) {
//			return nullptr;
//		}
//		r = getRow(pos);
//		c = getColumn(pos);
//		return &cards[r - 1][c];
//	}
//
//public:
//	DraftSpace(int dim) : dim(dim) {
//		cards.resize(dim, vector<Card>(dim));
//	}
//
//	bool tryAdd(const Card& card, int pos) {
//		const Card* l = getLeftCard(pos);
//		const Card* t = getTopCard(pos);
//		int r = getRow(pos);
//		int c = getColumn(pos);
//
//		if (card.isCompatible(*l, *t)) {
//			cards[r][c] = card.clone();
//			return true;
//		}
//		return false;
//	}
//};
//
//int main() {
//	// Card ��ü ����
//	Card card1(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card2(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card3(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card4(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card5(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card6(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card7(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card8(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//	Card card9(Side(Part::HEAD, PartIndex::ONE), Side(Part::TAIL, PartIndex::TWO),
//		Side(Part::HEAD, PartIndex::THREE), Side(Part::TAIL, PartIndex::FOUR));
//
//	// DraftSpace ��ü ����
//	DraftSpace draftSpace(3);
//
//	// ī�� �߰� �õ� �� �κ� �𸣰���
//
//	// ���ʿ� �̷��� �ڵ� ¥�°� ��¥ �ƴ� �� ����.
//
//	return 0;
//}