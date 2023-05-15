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
        // ��� piece�� ����� ��� solution�� ����Ѵ�.
        cout << ++count_solutions << endl;
        for (int i = 0; i < 9; i++) {
            cout << pieces[solution[i]].id << "(" << pieces[solution[i]].sides[0] << ") ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (used[i]) continue; // �̹� ���� ������ �ǳʶڴ�.
        used[i] = true;
        for (int j = 0; j < 4; j++) {
            solution[depth] = i;
            if (depth == 3) { // 3��° piece�� ���
                // 1, 2��° piece�� �´��� Ȯ���Ѵ�.
                if (!pieces[solution[0]].is_match(pieces[solution[1]])) {
                    continue;
                }
            }
            else if (depth == 6) { // 6��° piece�� ���
                // 4, 5��° piece�� �´��� Ȯ���Ѵ�.
                if (!pieces[solution[3]].is_match(pieces[solution[4]])) {
                    continue;
                }
            }

            // ���� piece�� ����� �� �ִٸ� ���� depth�� �����Ѵ�.
            solve(depth + 1);
            pieces[i].rotate(); // ���� piece�� ȸ����Ų��.
        }
        used[i] = false; // ���� piece�� ������� �ʴ� ��� �ٽ� false�� ����
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