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
	//if (puzzle.empty()) {
	//	return 0;
	//}
	cout << "y�� : " << puzzle[x].size() << "\n";
	return puzzle[x].size();
}

bool solvePuzzle(vector<vector<PuzzlePiece>>& puzzle, vector<PuzzlePiece>& pieces, int x, int y) {
	if (y == getNumRows(puzzle)) {
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
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <map>
//
//enum class Part {
//    HEAD = 1,
//    TAIL = -1
//};
//
//enum class PartColor {
//    RED = 1,
//    YELLOW = 2,
//    BLUE = 3,
//    GREEN = 4
//};
//
//class Side {
//private:
//    Part part;
//    PartColor color;
//
//public:
//    Side(Part part, PartColor color) : part(part), color(color) {}
//
//    int getValue() const {
//        return static_cast<int>(part) * static_cast<int>(color);
//    }
//
//    bool canJoin(const Side& side) const {
//        if (&side == nullptr)
//            return true;
//        return getValue() + side.getValue() == 0;
//    }
//
//    std::string toString() const {
//        std::stringstream ss;
//        ss << static_cast<int>(part) << "-" << static_cast<int>(color);
//        return ss.str();
//    }
//
//    Side clone() const {
//        return Side(part, color);
//    }
//};
//
//class Card {
//private:
//    static int counter; // ���� ��� ������ ����Ͽ� ī�� �̸��� ���ϼ� ����
//    std::string name;
//    Side top;
//    Side left;
//    Side bottom;
//    Side right;
//
//public:
//    Card(Side top, Side left, Side bottom, Side right)
//        : name("Card" + std::to_string(counter++)), top(top), left(left), bottom(bottom), right(right) {}
//
//    // ���� ������
//    Card(const Card& other)
//        : name("Card" + std::to_string(counter++)),
//        top(other.top.clone()), left(other.left.clone()), bottom(other.bottom.clone()), right(other.right.clone()) {}
//
//    // ���� ������
//    Card& operator=(const Card& other) {
//        if (this != &other) {
//            name = "Card" + std::to_string(counter++);
//            top = other.top.clone();
//            left = other.left.clone();
//            bottom = other.bottom.clone();
//            right = other.right.clone();
//        }
//        return *this;
//    }
//
//    bool isCompatible(const Card& leftCard, const Card& topCard) const {
//        if (&leftCard == nullptr && &topCard != nullptr) {
//            return top.canJoin(topCard.bottom);
//        }
//        else if (&leftCard != nullptr && &topCard == nullptr) {
//            return left.canJoin(leftCard.right);
//        }
//        else if (&leftCard == nullptr && &topCard == nullptr) {
//            return true;
//        }
//        return left.canJoin(leftCard.right) && top.canJoin(topCard.bottom);
//    }
//
//    std::string toString() const {
//        return name;
//    }
//
//    Card clone() const {
//        return Card(top.clone(), left.clone(), bottom.clone(), right.clone());
//    }
//};
//
//int Card::counter = 1; // ���� ��� ���� �ʱ�ȭ
//
//class DraftSpace {
//private:
//    std::vector<std::vector<Card>> cards;
//    int dim;
//
//    int getRow(int pos) const {
//        return pos / dim;
//    }
//
//    int getColumn(int pos) const {
//        return pos % dim;
//    }
//
//    const Card* getLeftCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r][c - 1];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//    const Card* getTopCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r - 1][c];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//public:
//    DraftSpace(int dim) : dim(dim) {
//        cards.resize(dim, std::vector<Card>(dim));
//    }
//
//    bool tryAdd(const Card& card, int pos) {
//        const Card* l = getLeftCard(pos);
//        const Card* t = getTopCard(pos);
//        int r = getRow(pos);
//        int c = getColumn(pos);
//
//        if (card.isCompatible(*l, *t)) {
//            cards[r][c] = card.clone();
//            return true;
//        }
//
//        return false;
//    }
//};
//
//int main() {
//    // Card ��ü ����
//    Card card1(Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE),
//        Side(Part::HEAD, PartColor::GREEN), Side(Part::TAIL, PartColor::YELLOW));
//    Card card2(Side(Part::HEAD, PartColor::YELLOW), Side(Part::TAIL, PartColor::GREEN),
//        Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE));
//
//    // DraftSpace ��ü ����
//    DraftSpace draftSpace(3);
//
//    // ī�� �߰� �õ�
//    bool success = draftSpace.tryAdd(card1, 0);
//    if (success) {
//        std::cout << card1.toString() << " added successfully!" << std::endl;
//    }
//    else {
//        std::cout << card1.toString() << " cannot be added!" << std::endl;
//    }
//
//    success = draftSpace.tryAdd(card2, 1);
//    if (success) {
//        std::cout << card2.toString() << " added successfully!" << std::endl;
//    }
//    else {
//        std::cout << card2.toString() << " cannot be added!" << std::endl;
//    }
//
//    return 0;
//}








//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <map>
//
//enum class Part {
//    HEAD = 1,
//    TAIL = -1
//};
//
//enum class PartColor {
//    RED = 1,
//    YELLOW = 2,
//    BLUE = 3,
//    GREEN = 4
//};
//
//class Side {
//private:
//    Part part;
//    PartColor color;
//
//public:
//    Side(Part part, PartColor color) : part(part), color(color) {}
//
//    int getValue() const {
//        return static_cast<int>(part) * static_cast<int>(color);
//    }
//
//    bool canJoin(const Side& side) const {
//        if (&side == nullptr)
//            return true;
//        return getValue() + side.getValue() == 0;
//    }
//
//    std::string toString() const {
//        std::stringstream ss;
//        ss << static_cast<int>(part) << "-" << static_cast<int>(color);
//        return ss.str();
//    }
//
//    Side clone() const {
//        return Side(part, color);
//    }
//};
//
//class Card {
//private:
//    std::string name;
//    Side top;
//    Side left;
//    Side bottom;
//    Side right;
//
//public:
//    Card(std::string name, Side top, Side left, Side bottom, Side right)
//        : name(name), top(top), left(left), bottom(bottom), right(right) {}
//
//    bool isCompatible(const Card& leftCard, const Card& topCard) const {
//        if (&leftCard == nullptr && &topCard != nullptr) {
//            return top.canJoin(topCard.bottom);
//        }
//        else if (&leftCard != nullptr && &topCard == nullptr) {
//            return left.canJoin(leftCard.right);
//        }
//        else if (&leftCard == nullptr && &topCard == nullptr) {
//            return true;
//        }
//        return left.canJoin(leftCard.right) && top.canJoin(topCard.bottom);
//    }
//
//    std::string toString() const {
//        return "Card" + name;
//    }
//
//    Card clone() const {
//        return Card(name, top.clone(), left.clone(), bottom.clone(), right.clone());
//    }
//};
//
//class DraftSpace {
//private:
//    std::vector<std::vector<Card>> cards;
//    int dim;
//
//    int getRow(int pos) const {
//        return pos / dim;
//    }
//
//    int getColumn(int pos) const {
//        return pos % dim;
//    }
//
//    const Card* getLeftCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r][c - 1];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//    const Card* getTopCard(int pos) const {
//        int r, c;
//        if (pos >= dim * dim) {
//            return nullptr;
//        }
//        r = getRow(pos);
//        c = getColumn(pos);
//        try {
//            return &cards[r - 1][c];
//        }
//        catch (const std::exception&) {
//            return nullptr;
//        }
//    }
//
//public:
//    DraftSpace(int dim) : dim(dim) {
//        cards.resize(dim, std::vector<Card>(dim));
//    }
//
//    bool tryAdd(const Card& card, int pos) {
//        const Card* l = getLeftCard(pos);
//        const Card* t = getTopCard(pos);
//        int r = getRow(pos);
//        int c = getColumn(pos);
//
//        if (card.isCompatible(*l, *t)) {
//            cards[r][c] = card.clone();
//            return true;
//        }
//
//        return false;
//    }
//};
//
//int main() {
//    // Card ��ü ����
//    Card card1("Card1", Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE),
//        Side(Part::HEAD, PartColor::GREEN), Side(Part::TAIL, PartColor::YELLOW));
//    Card card2("Card2", Side(Part::HEAD, PartColor::YELLOW), Side(Part::TAIL, PartColor::GREEN),
//        Side(Part::HEAD, PartColor::RED), Side(Part::TAIL, PartColor::BLUE));
//
//    // DraftSpace ��ü ����
//    DraftSpace draftSpace(3);
//
//    // ī�� �߰� �õ�
//    bool success = draftSpace.tryAdd(card1, 0);
//    if (success) {
//        std::cout << "Card1 added successfully!" << std::endl;
//    }
//    else {
//        std::cout << "Card1 cannot be added!" << std::endl;
//    }
//
//    success = draftSpace.tryAdd(card2, 1);
//    if (success) {
//        std::cout << "Card2 added successfully!" << std::endl;
//    }
//    else {
//        std::cout << "Card2 cannot be added!" << std::endl;
//    }
//
//    return 0;
//}
