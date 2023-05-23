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
//	vector<int> sides; // 각 면에 대한 값
//	int orientation; // 회전 상태
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
//// Promising 한지 검사하는 부분, 퍼즐을 해당 위치에 놓을 수 있는지 오른쪽과 위쪽을 검사.
//bool checkMove(const vector<vector<PuzzlePiece>>& puzzle, const PuzzlePiece& piece, int x, int y) { // x와 y는 현재 위치
//	if (x > 0) { // 왼쪽에 인접한 면이 있는 경우
//		//int side1 = puzzle[x - 1][y].sides[1]; // 오른쪽
//		//int side2 = piece.sides[3]; // 왼쪽
//		int side1 = getSide(puzzle[x - 1][y], 1);
//		int side2 = getSide(piece, 3);
//		int sum = side1 + side2;
//		if (sum != 3 && sum != 7 && sum != 11 && sum != 16)//(side1 !=  side2)
//			return false;
//	}
//	if (y > 0) {
//		//int side1 = puzzle[x][y - 1].sides[2]; // 아래쪽
//		//int side2 = piece.sides[0]; // 위쪽
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
//	if (y == puzzle.size()) { // 해를 찾았을 경우 출력
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
//    int id; // 조각 번호
//    vector<int> nums; //조각의 각 면에 해당하는 숫자
//
//    Piece(int id, const vector<int>& nums) : id(id), nums(nums) {}
//};
//
//int count_solutions = 0; // 해결된 경우의 수를 세는 변수
//vector<Piece> pieces; // 입력으로 주어진 9개의 이미지 조각을 저장하는 벡터
//vector<int> solution(9); // 현재까지 구성된 조각들의 순서를 저장하는 벡터
//vector<bool> used(9, false); // 이미 사용된 조각을 표시하는 벡터
//
//// 두개의 조각이 일치하는지 판별하는 함수
////bool is_match(const Piece& p1, const Piece& p2, int side1, int side2) { // p1과 p2는 비교할 두 개의 조각, side1과 side2는 비교할 면의 인덱스
////    for (int i = 0; i < 3; i++) {
////        // p1.nums[side1 * 3 + i] 는 p1 조각의 side1면에서 i의 위치 값
////        // p2는 2 - i의 위치 값, 2 - i 는 i값을 반전시키는 것을 의미
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
//            if (side1 == side2) continue;  // 같은 면은 비교하지 않음
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
//// 백트래킹을 수행하는 함수
//void solve(int depth) { // depth는 현재까지 구성된 조각의 개수
//    if (depth == 9) {
//        // 모든 piece를 사용한 경우 solution을 출력한다.
//        cout << ++count_solutions << endl;
//        for (int i = 0; i < 9; i++) {
//            cout << solution[i] + 1 << "(" << solution[i] / 4 << ") ";
//        }
//        cout << endl;
//        return;
//    }
//
//    for (int i = 0; i < 9; i++) {
//        if (used[i]) continue; // 이미 사용된 조각은 건너뛴다.
//
//        used[i] = true;
//        solution[depth] = i;
//
//        for (int j = 0; j < 4; j++) {
//            // 1. 첫번째 조각을 선택하는 경우
//            // 2. 이전의 선택된 조각과 현재 조각을 비교
//            // 3. 1(오른쪽면) 3(왼쪽면)을 입력한다
//            if (depth == 0 || is_match(pieces[solution[depth - 1]], pieces[i])) {
//                solve(depth + 1); // 재귀 호출
//            }
//            // 조각 i의 0부터 2까지의 요소를 3번째 요소를 기준으로 반시계방향 회전
//            rotate(pieces[i].nums.begin(), pieces[i].nums.begin() + 3, pieces[i].nums.end()); // 반시계방향으로 조각을 회전한다.
//        }
//
//        used[i] = false;
//    }
//}
//
//int main() {
//    // 이미지 조각 초기화
//    for (int i = 0; i < 9; i++) {
//
//        vector<int> nums(15, 0);
//        for (int j = 0; j < 4; j++) {
//            cin >> nums[j];
//        }
//
//        pieces.emplace_back(i, nums); // Piece 객체가 생성되고 해당 객체는 piece 벡터에 추간된다.
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
//    // 이미지 조각 초기화
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
//// 각 조각은 4개의 변을 가지고 각 변마다 이미지를 가진다
//struct puzzlepiece {
//    string sides[4];
//    int orientation; // 조각의 회전상태를 나타낸다
//};
//
//// 현재 위치와 퍼즐의 너비를 받아서 다음 위치로 이동할 수 있는지 여부 파악
//bool nextlocal(int x, int width) { 
//    if (x < width - 1) {
//        return true;
//    }
//    return false;
//}
//
//// 퍼즐 조각과 변의 인덱스를 이용하여 변의 이미지 조각을 가져온다.
//string getSide(puzzlepiece piece, int side) { 
//    int num = piece.orientation;
//    return piece.sides[(num + side - 1) % 4];
//}
//
//// 주어진 조각이 현재 위치에 맞는지 확인. 인접한 퍼즐 조각이 이미지 조각에 일치하는지
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
//// 백트래킹을 사용하여 퍼즐 해결, 재귀 호출, 현재 위치에서 가능한 모든 조각의 회전 상태를 시도, 조건을 만족하는 조각을 선택하여 퍼즐에 배치한다.
//// 재귀적으로 다음 위치로 이동하여 퍼즐 해결
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
//// 모든 퍼즐 조각과 퍼즐의 너비를 인자로 받아서 퍼즐을 해결한 결과인  Grid<puzzlepiece>를 반환
//// solvePuzzle을 호출하여 퍼즐을 해결
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
//            piece.sides[i] = str; // piece 객체에 각 조각의 변 입력
//        }
//        piece.orientation = 0; // 조각의 회전수는 0으로 설정
//    }
//
//    findSoln(allpieces, 3);
//    return 0;
//}

