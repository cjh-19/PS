#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Piece {
    int nums[4];
    int sides[4];
    int id;

    bool is_match(const Piece& other) const {
        for (int i = 0; i < 4; i++) {
            if (nums[sides[i]] != other.nums[other.sides[i]]) {
                return false;
            }
        }
        return true;
    }

    void rotate() {
        int temp = sides[0];
        sides[0] = sides[1];
        sides[1] = sides[3];
        sides[3] = sides[2];
        sides[2] = temp;
    }
};

int count_solutions = 0;
Piece pieces[9];
bool used[9];
int solution[9];

void solve(int depth) {
    if (depth == 9) {
        // 모든 piece를 사용한 경우 solution을 출력한다.
        cout << ++count_solutions << endl;
        for (int i = 0; i < 9; i++) {
            cout << pieces[solution[i]].id << "(" << pieces[solution[i]].sides[0] << ") ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (used[i]) continue; // 이미 사용된 조각은 건너뛴다.
        used[i] = true;
        for (int j = 0; j < 4; j++) {
            solution[depth] = i;
            if (depth == 3) { // 3번째 piece인 경우
                // 1, 2번째 piece와 맞는지 확인한다.
                if (!pieces[solution[0]].is_match(pieces[solution[1]])) {
                    continue;
                }
            }
            else if (depth == 6) { // 6번째 piece인 경우
                // 4, 5번째 piece와 맞는지 확인한다.
                if (!pieces[solution[3]].is_match(pieces[solution[4]])) {
                    continue;
                }
            }

            // 현재 piece를 사용할 수 있다면 다음 depth로 진행한다.
            solve(depth + 1);
            pieces[i].rotate(); // 현재 piece를 회전시킨다.
        }
        used[i] = false; // 현재 piece를 사용하지 않는 경우 다시 false로 변경
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        Piece p;
        cin >> p.nums[0] >> p.nums[1] >> p.nums[2] >> p.nums[3];
        p.id = i + 1;
        for (int j = 0; j < 4; j++) {
            p.sides[j] = j;
        }
        pieces[i] = p;
    }

    solve(0);

    return 0;
}