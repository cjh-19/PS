#include <iostream>
#include <vector>

using namespace std;

struct PuzzlePiece {
    int id;
    int sides[4];
    int orientation;
};

int solutionCount = 0;

bool nextLocal(int x, int width) {
    if (x < width - 1) {
        return true;
    }
    return false;
}

int getSide(PuzzlePiece piece, int side) {
    int num = piece.orientation;
    return piece.sides[(num + side) % 4];
}

bool checkMove(vector<vector<PuzzlePiece>>& puzzle, PuzzlePiece piece, int x, int y) {
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

bool solvePuzzle(vector<vector<PuzzlePiece>>& puzzle, vector<PuzzlePiece>& pieces, int x, int y) {
    if (y == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << puzzle[j][i].id << "(" << puzzle[j][i].orientation << ") ";
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 9; i++) {
        PuzzlePiece temp = pieces[i];

        if (temp.orientation != 0) {
            continue;
        }

        int curr_x = x;
        int curr_y = y;

        

        if (nextLocal(x, 3)) {
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
                //solutionCount += solvePuzzle(puzzle, pieces, x, y);
                if (solvePuzzle(puzzle, pieces, x, y)) {
                    solutionCount++;
                    return true;//solutionCount++;
                }
                else
                    temp.orientation = 0;
                //puzzle[curr_x][curr_y].orientation = 0;
            }
        }
    }

    return false; // solutionCount;
}

void findSoln(vector<PuzzlePiece> pieces, int width) {
    vector<vector<PuzzlePiece>> puzzle(width, vector<PuzzlePiece>(width));
    int num = 0;
    if (solvePuzzle(puzzle, pieces, 0, 0)) {
        cout << "Number of solutions: " << solutionCount << endl;
    }

}

int main() {
    vector<PuzzlePiece> pieces(9);
    for (int i = 0; i < 9; i++) {
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        pieces[i].sides[0] = s1;
        pieces[i].sides[1] = s2;
        pieces[i].sides[2] = s3;
        pieces[i].sides[3] = s4;
        pieces[i].id = i;
        pieces[i].orientation = 0;
    }

    findSoln(pieces, 3);
    return 0;
}





//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//struct PuzzlePiece {
//    string sides[4];
//    int orientation;
//};
//
//vector<PuzzlePiece> P;
//
//bool nextLocal(int x, int width) {
//    if (x < width - 1) {
//        return true;
//    }
//    return false;
//}
//
//string getSide(PuzzlePiece piece, int side) {
//    int num = piece.orientation;
//    return piece.sides[(num + side - 1) % 4];
//}
//
//bool checkMove(PuzzlePiece puzzle[3][3], PuzzlePiece piece, int x, int y) {
//    if (x > 0) {
//        string side1 = getSide(puzzle[x - 1][y], 1);
//        string side2 = getSide(piece, 3);
//        cout << side1 << " " << side2 << x << y << "\n";
//        if (side1[0] != side2[0]) {
//            return false;
//        }
//        if (side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    if (y > 0) {
//        string side1 = getSide(puzzle[x][y - 1], 1);
//        string side2 = getSide(piece, 0);
//        cout << side1 << " " << side2 << x << y << "\n";
//
//        if (side1[0] != side2[0]) {
//            return false;
//        }
//        if (side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool solvePuzzle(PuzzlePiece puzzle[3][3], PuzzlePiece pieces[], int x, int y) {
//    if (y == 3) {
//        //for (int i = 0; i < 9; i++) {
//        //    for (int j = 0; j < 4; j++) {
//        //        cout << pieces[i].sides[j] << " ";
//        //    }
//        //    cout << "\n";
//        //}
//        return true;
//    }
//
//    for (int i = 0; i < 9; i++) {
//        PuzzlePiece temp = pieces[i];
//
//        if (temp.orientation != 0) {
//            continue;
//        }
//
//        int curr_x = x;
//        int curr_y = y;
//
//        if (nextLocal(x, 3)) {
//            x++;
//        }
//        else {
//            y++;
//            x = 0;
//        }
//
//        for (int j = 1; j <= 4; j++) {
//            temp.orientation = j;
//            if (checkMove(puzzle, temp, curr_x, curr_y)) {
//                puzzle[curr_x][curr_y] = temp;
//                if (solvePuzzle(puzzle, pieces, x, y)) {
//                   // P[x][y].sides = pieces.sides;
//                    return true;
//                }
//                else {
//                    temp.orientation = 0;
//                }
//            }
//        }
//    }
//
//    return false;
//}
//
//void findSoln(PuzzlePiece pieces[], int width) {
//    PuzzlePiece soln[3][3];
//    solvePuzzle(soln, pieces, 0, 0);
//}
//
//int main() {
//    PuzzlePiece pieces[9];
//    pieces[0] = { {"dl", "zr", "er", "el"}, 0 };
//    pieces[1] = { {"zl", "dl", "tr", "er"}, 0 };
//    pieces[2] = { {"dl", "tr", "el", "zl"}, 0 };
//    pieces[3] = { {"zr", "tr", "el", "dr"}, 0 };
//    pieces[4] = { {"tr", "zr", "dr", "er"}, 0 };
//    pieces[5] = { {"dl", "zl", "tl", "er"}, 0 };
//    pieces[6] = { {"tl", "zr", "dl", "er"}, 0 };
//    pieces[7] = { {"zl", "dr", "tl", "zr"}, 0 };
//    pieces[8] = { {"tl", "zl", "dl", "er"}, 0 };
//
//    findSoln(pieces, 3);
//    //for (int i = 0; i < 9; i++) {
//    //    for (int j = 0; j < 4; j++) {
//    //       cout << pieces[i].sides[j] << " ";
//    //    }
//    //    cout << "\n";
//    //}
//    return 0;
//}






/// Scramble Square Puzzle Problem ///

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct PuzzlePiece {
//	vector<int> sides; // �� �鿡 ���� ��
//	int orientation; // ȸ�� ����
//
//	//PuzzlePiece(int orientation, const vector<int>& sides) : orientation(orientation), sides(sides) {}
//};
//
//bool nextLocal(int x, int width) {
//	if (x < width - 1)
//		return true;
//	return false;
//}
//
//int getSide(PuzzlePiece piece, int side) {
//	int num = piece.orientation;
//	return piece.sides[(num + side - 1) % 4];
//}	
//
//// Promising ���� �˻��ϴ� �κ�, ������ �ش� ��ġ�� ���� �� �ִ��� �����ʰ� ������ �˻�.
//bool checkMove(const vector<vector<PuzzlePiece>>& puzzle, const PuzzlePiece& piece, int x, int y) { // x�� y�� ���� ��ġ
//	if (x > 0) { // ���ʿ� ������ ���� �ִ� ���
//		//int side1 = puzzle[x - 1][y].sides[1]; // ������
//		//int side2 = piece.sides[3]; // ����
//		int side1 = getSide(puzzle[x - 1][y], 1);
//		int side2 = getSide(piece, 3);
//		int sum = side1 + side2;
//		if (sum != 3 && sum != 7 && sum != 11 && sum != 16)//(side1 !=  side2)
//			return false;
//	}
//	if (y > 0) {
//		//int side1 = puzzle[x][y - 1].sides[2]; // �Ʒ���
//		//int side2 = piece.sides[0]; // ����
//		int side1 = getSide(puzzle[x][y - 1], 2);
//		int side2 = getSide(piece, 0);
//		int sum = side1 + side2;
//		if (sum != 3 && sum != 7 && sum != 11 && sum != 16)//(side1 != side2)
//			return false;
//	}
//	return true;
//}
//
//bool solvePuzzle(vector<vector<PuzzlePiece>>& puzzle, vector<PuzzlePiece>& pieces, int x, int y, int& solutionCount) {
//	if (y == puzzle.size()) { // �ظ� ã���� ��� ���
//		solutionCount++;
//		if (solutionCount == 1)
//			cout << solutionCount << endl;
//		else
//			cout << endl;
//
//		for (const auto& row : puzzle) {
//			for (const auto& piece : row) {
//				cout << piece.orientation + 1 << "(" << piece.orientation << ") ";
//			}
//			cout << endl;
//		}
//		return true;
//	}
//
//	for (auto& piece : pieces) {
//		if (piece.orientation != 0) continue;
//
//		int curr_x = x;
//		int curr_y = y;
//
//		if (nextLocal(x, puzzle.size()))//(x < puzzle.size() - 1)
//			x++;
//		else {
//			y++;
//			x = 0;
//		}
//
//		for (int j = 0; j < 4; j++) {
//			piece.orientation = j;
//			if (checkMove(puzzle, piece, curr_x, curr_y)) {
//				if (curr_x < puzzle.size() && curr_y < puzzle.size())
//					puzzle[curr_x][curr_y] = piece;
//				if (solvePuzzle(puzzle, pieces, x, y, solutionCount))
//					return true;
//				else
//					piece.orientation = 0;
//			}
//		}
//	}
//	return false;
//}
//
//void findSolutions(vector<PuzzlePiece>& pieces, int width) {
//	vector<vector<PuzzlePiece>> puzzle(3, vector<PuzzlePiece>(3));
//	int solutionCount = 0;
//	solvePuzzle(puzzle, pieces, 0, 0, solutionCount);
//}
//
//int main() {
//	vector<PuzzlePiece> allPieces;
//	for (int i = 0; i < 9; i++) {
//		PuzzlePiece puzzlePiece;
//		for (int j = 0; j < 4; j++) {
//			int num;
//			cin >> num;
//			puzzlePiece.sides.push_back(num);
//		}
//		puzzlePiece.orientation = 0;
//		allPieces.push_back(puzzlePiece);
//	}
//
//	findSolutions(allPieces, 3);
//
//	return 0;
//}









//#include <iostream>
//#include <vector>
//#include <array>
//#include <algorithm>
//
//struct PuzzlePiece {
//    std::array<std::string, 4> sides;
//    int orientation;
//};
//
//bool checkMove(const std::vector<std::vector<PuzzlePiece>>& puzzle, const PuzzlePiece& piece, int x, int y) {
//    if (x > 0) {
//        std::string side1 = puzzle[x - 1][y].sides[1];
//        std::string side2 = piece.sides[3];
//        if (side1[0] != side2[0] || side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    if (y > 0) {
//        std::string side1 = puzzle[x][y - 1].sides[2];
//        std::string side2 = piece.sides[0];
//        if (side1[0] != side2[0] || side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void solvePuzzle(std::vector<std::vector<PuzzlePiece>>& puzzle, std::vector<PuzzlePiece>& pieces, int x, int y, int& solutionCount) {
//    if (y == puzzle.size()) {
//        solutionCount++;
//        if (solutionCount == 1) {
//            std::cout << solutionCount << std::endl;
//        }
//        else {
//            std::cout << std::endl;
//        }
//        for (const auto& row : puzzle) {
//            for (const auto& piece : row) {
//                std::cout << piece.orientation + 1 << "(" << piece.orientation << ") ";
//            }
//            std::cout << std::endl;
//        }
//        return;
//    }
//
//    for (auto& piece : pieces) {
//        if (piece.orientation != 0) {
//            continue;
//        }
//
//        int curr_x = x;
//        int curr_y = y;
//
//        if (x < puzzle.size() - 1) {
//            x++;
//        }
//        else {
//            y++;
//            x = 0;
//        }
//
//        for (int j = 0; j < 4; j++) {
//            piece.orientation = j;
//            if (checkMove(puzzle, piece, curr_x, curr_y)) {
//                puzzle[curr_x][curr_y] = piece;
//                solvePuzzle(puzzle, pieces, x, y, solutionCount);
//                piece.orientation = 0;
//            }
//        }
//    }
//}
//
//void findSolutions(std::vector<PuzzlePiece>& pieces, int width) {
//    std::vector<std::vector<PuzzlePiece>> puzzle(width, std::vector<PuzzlePiece>(width));
//    int solutionCount = 0;
//    solvePuzzle(puzzle, pieces, 0, 0, solutionCount);
//}
//
//int main() {
//    std::array<std::array<std::string, 4>, 9> pieceData = { {
//        {"dl", "zr", "er", "el"},
//        {"zl", "dl", "tr", "er"},
//        {"dl", "tr", "el", "zl"},
//        {"zr", "tr", "el", "dr"},
//        {"tr", "zr", "dr", "er"},
//        {"dl", "zl", "tl", "er"},
//        {"tl", "zr", "dl", "er"},
//        {"zl", "dr", "tl", "zr"},
//        {"tl", "zl", "dl", "er"}
//        } };
//    std::vector<PuzzlePiece> allPieces;
//    for (const auto& piece : pieceData) {
//        PuzzlePiece puzzlePiece;
//        for (int i = 0; i < 4; i++) {
//            puzzlePiece.sides[i] = piece[i];
//        }
//        puzzlePiece.orientation = 0;
//        allPieces.push_back(puzzlePiece);
//    }
//
//    findSolutions(allPieces, 3);
//
//    return 0;
//}













//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//
//using namespace std;
//
//struct Piece {
//    int id; // ���� ��ȣ
//    vector<int> nums; //������ �� �鿡 �ش��ϴ� ����
//
//    Piece(int id, const vector<int>& nums) : id(id), nums(nums) {}
//};
//
//int count_solutions = 0; // �ذ�� ����� ���� ���� ����
//vector<Piece> pieces; // �Է����� �־��� 9���� �̹��� ������ �����ϴ� ����
//vector<int> solution(9); // ������� ������ �������� ������ �����ϴ� ����
//vector<bool> used(9, false); // �̹� ���� ������ ǥ���ϴ� ����
//
//// �ΰ��� ������ ��ġ�ϴ��� �Ǻ��ϴ� �Լ�
////bool is_match(const Piece& p1, const Piece& p2, int side1, int side2) { // p1�� p2�� ���� �� ���� ����, side1�� side2�� ���� ���� �ε���
////    for (int i = 0; i < 3; i++) {
////        // p1.nums[side1 * 3 + i] �� p1 ������ side1�鿡�� i�� ��ġ ��
////        // p2�� 2 - i�� ��ġ ��, 2 - i �� i���� ������Ű�� ���� �ǹ�
////        if (p1.nums[i] != p2.nums[(2 - i)]) {
////            return false;
////        }
////    }
////    return true;
////}
//
//bool are_adjacent(const Piece& p1, int side1, const Piece& p2, int side2) {
//    for (int i = 0; i < 3; i++) {
//        if (p1.nums[side1* 3 + i] != p2.nums[side2 * 3 + (2 - i)]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool is_match(const Piece& p1, const Piece& p2) {
//    for (int side1 = 0; side1 < 4; side1++) {
//        for (int side2 = 0; side2 < 4; side2++) {
//            if (side1 == side2) continue;  // ���� ���� ������ ����
//
//            if (are_adjacent(p1, side1, p2, side2)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//
//
//// ��Ʈ��ŷ�� �����ϴ� �Լ�
//void solve(int depth) { // depth�� ������� ������ ������ ����
//    if (depth == 9) {
//        // ��� piece�� ����� ��� solution�� ����Ѵ�.
//        cout << ++count_solutions << endl;
//        for (int i = 0; i < 9; i++) {
//            cout << solution[i] + 1 << "(" << solution[i] / 4 << ") ";
//        }
//        cout << endl;
//        return;
//    }
//
//    for (int i = 0; i < 9; i++) {
//        if (used[i]) continue; // �̹� ���� ������ �ǳʶڴ�.
//
//        used[i] = true;
//        solution[depth] = i;
//
//        for (int j = 0; j < 4; j++) {
//            // 1. ù��° ������ �����ϴ� ���
//            // 2. ������ ���õ� ������ ���� ������ ��
//            // 3. 1(�����ʸ�) 3(���ʸ�)�� �Է��Ѵ�
//            if (depth == 0 || is_match(pieces[solution[depth - 1]], pieces[i])) {
//                solve(depth + 1); // ��� ȣ��
//            }
//            // ���� i�� 0���� 2������ ��Ҹ� 3��° ��Ҹ� �������� �ݽð���� ȸ��
//            rotate(pieces[i].nums.begin(), pieces[i].nums.begin() + 3, pieces[i].nums.end()); // �ݽð�������� ������ ȸ���Ѵ�.
//        }
//
//        used[i] = false;
//    }
//}
//
//int main() {
//    // �̹��� ���� �ʱ�ȭ
//    for (int i = 0; i < 9; i++) {
//
//        vector<int> nums(15, 0);
//        for (int j = 0; j < 4; j++) {
//            cin >> nums[j];
//        }
//
//        pieces.emplace_back(i, nums); // Piece ��ü�� �����ǰ� �ش� ��ü�� piece ���Ϳ� �߰��ȴ�.
//    }
//	
//    solve(0);
//
//    return 0;
//}











//#include <iostream>
//#include <vector>
//#include <array>
//#include <algorithm>
//
//using namespace std;
//
//struct PuzzlePiece {
//    std::array<std::string, 4> sides;
//    int orientation;
//};
//
//bool checkMove(const std::vector<std::vector<PuzzlePiece>>& puzzle, const PuzzlePiece& piece, int x, int y) {
//    if (x > 0) {
//        std::string side1 = puzzle[x - 1][y].sides[1];
//        std::string side2 = piece.sides[3];
//        if (side1[0] != side2[0] || side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    if (y > 0) {
//        std::string side1 = puzzle[x][y - 1].sides[2];
//        std::string side2 = piece.sides[0];
//        if (side1[0] != side2[0] || side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void solvePuzzle(std::vector<std::vector<PuzzlePiece>>& puzzle, std::vector<PuzzlePiece>& pieces, int x, int y, int& solutionCount) {
//    if (y == puzzle.size()) {
//        solutionCount++;
//        if (solutionCount == 1) {
//            std::cout << solutionCount << std::endl;
//        }
//        else {
//            std::cout << std::endl;
//        }
//        for (const auto& row : puzzle) {
//            for (const auto& piece : row) {
//                std::cout << piece.orientation + 1 << "(" << piece.orientation << ") ";
//            }
//            std::cout << std::endl;
//        }
//        return;
//    }
//
//    for (auto& piece : pieces) {
//        if (piece.orientation != 0) {
//            continue;
//        }
//
//        int curr_x = x;
//        int curr_y = y;
//
//        if (x < puzzle.size() - 1) {
//            x++;
//        }
//        else {
//            y++;
//            x = 0;
//        }
//
//        for (int j = 0; j < 4; j++) {
//            piece.orientation = j;
//            if (checkMove(puzzle, piece, curr_x, curr_y)) {
//                puzzle[curr_x][curr_y] = piece;
//                solvePuzzle(puzzle, pieces, x, y, solutionCount);
//                piece.orientation = 0;
//            }
//        }
//    }
//}
//
//void findSolutions(std::vector<PuzzlePiece>& pieces, int width) {
//    std::vector<std::vector<PuzzlePiece>> puzzle(width, std::vector<PuzzlePiece>(width));
//    int solutionCount = 0;
//    solvePuzzle(puzzle, pieces, 0, 0, solutionCount);
//}
//
//int main() {
//    int id = 0;
//    // �̹��� ���� �ʱ�ȭ
//    vector<PuzzlePiece> allPieces;
//    for (int i = 0; i < 9; i++) {
//        PuzzlePiece puzzlePiece;
//        for (int i = 0; i < 4; i++) {
//            int num;
//            cin >> num;
//            puzzlePiece.sides[i] = num;
//        }
//        puzzlePiece.orientation = 0;
//        allPieces.push_back(puzzlePiece);
//    }
//
//    findSolutions(allPieces, 3);
//
//    return 0;
//}


//#include <iostream>
//#include "console.h"
//#include "grid.h"
//#include "vector.h"
//using namespace std;
//
//// �� ������ 4���� ���� ������ �� ������ �̹����� ������
//struct puzzlepiece {
//    string sides[4];
//    int orientation; // ������ ȸ�����¸� ��Ÿ����
//};
//
//// ���� ��ġ�� ������ �ʺ� �޾Ƽ� ���� ��ġ�� �̵��� �� �ִ��� ���� �ľ�
//bool nextlocal(int x, int width) { 
//    if (x < width - 1) {
//        return true;
//    }
//    return false;
//}
//
//// ���� ������ ���� �ε����� �̿��Ͽ� ���� �̹��� ������ �����´�.
//string getSide(puzzlepiece piece, int side) { 
//    int num = piece.orientation;
//    return piece.sides[(num + side - 1) % 4];
//}
//
//// �־��� ������ ���� ��ġ�� �´��� Ȯ��. ������ ���� ������ �̹��� ������ ��ġ�ϴ���
//bool checkMove(Grid<puzzlepiece> puzzle, puzzlepiece piece, int x, int y) { 
//    if (x > 0) {
//        string side1 = getSide(puzzle[x - 1][y], 1);
//        string side2 = getSide(piece, 3);
//        if (side1[0] != side2[0]) {
//            return false;
//        }
//        if (side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    if (y > 0) {
//        string side1 = getSide(puzzle[x][y - 1], 1);
//        string side2 = getSide(piece, 0);
//        if (side1[0] != side2[0]) {
//            return false;
//        }
//        if (side1[1] != side2[1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// ��Ʈ��ŷ�� ����Ͽ� ���� �ذ�, ��� ȣ��, ���� ��ġ���� ������ ��� ������ ȸ�� ���¸� �õ�, ������ �����ϴ� ������ �����Ͽ� ���� ��ġ�Ѵ�.
//// ��������� ���� ��ġ�� �̵��Ͽ� ���� �ذ�
//bool solvePuzzle(Grid<puzzlepiece>& puzzle, Vector<puzzlepiece>& pieces, int x, int y) { //
//
//    if (y == puzzle.numRows()) {
//        return true;
//    }
//
//    for (int i = 0; i < pieces.size(); i++) {
//        puzzlepiece temp = pieces[i];
//
//        if (temp.orientation != 0) {
//            continue;
//        }
//
//        int curr_x = x;
//        int curr_y = y;
//
//        if (nextlocal(x, puzzle.numCols())) {
//            x++;
//        }
//        else {
//            y++;
//            x = 0;
//        }
//
//        for (int j = 1; j <= 4; j++) {
//            temp.orientation = j;
//            if (checkMove(puzzle, temp, curr_x, curr_y)) {
//                puzzle[curr_x][curr_y] = temp;
//                if (solvePuzzle(puzzle, pieces, x, y)) {
//                    return true;
//                }
//                else {
//                    temp.orientation = 0;
//                }
//            }
//        }
//    }
//
//    return false;
//}
//
//// ��� ���� ������ ������ �ʺ� ���ڷ� �޾Ƽ� ������ �ذ��� �����  Grid<puzzlepiece>�� ��ȯ
//// solvePuzzle�� ȣ���Ͽ� ������ �ذ�
//Grid<puzzlepiece> findSoln(Vector<puzzlepiece> pieces, int width) {
//    Grid<puzzlepiece> soln(3, 3);
//    solvePuzzle(soln, pieces, 0, 0);
//    return soln;
//}
//
//int main() {
//    string pieces[9][4] = {
//            {"dl", "zr", "er", "el"},
//            {"zl", "dl", "tr", "er"},
//            {"dl", "tr", "el", "zl"},
//            {"zr", "tr", "el", "dr"},
//            {"tr", "zr", "dr", "er"},
//            {"dl", "zl", "tl", "er"},
//            {"tl", "zr", "dl", "er"},
//            {"zl", "dr", "tl", "zr"},
//            {"tl", "zl", "dl", "er"} };
//
//
//    Vector<puzzlepiece> allpieces;
//    for (int i = 0; i < 9; i++) {
//        puzzlepiece piece;
//        for (string str : pieces[i]) {
//            piece.sides[i] = str; // piece ��ü�� �� ������ �� �Է�
//        }
//        piece.orientation = 0; // ������ ȸ������ 0���� ����
//    }
//
//    findSoln(allpieces, 3);
//    return 0;
//}

