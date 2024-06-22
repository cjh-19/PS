#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    // 사라진 인형 수
    int count = 0;
    // 담은 인형
    stack<int> doll;

    // 크레인 이동 반복
    for (int i = 0; i < moves.size(); i++) {
        int point = moves[i] - 1;

        // 0이 아닌 값까지 반복
        for (int j = 0; j < board.size(); j++) {
            if (board[j][point] != 0) {
                if (!doll.empty()) {
                    // 바구니의 최상단과 같은 인형인지 확인
                    if (board[j][point] == doll.top()) {
                        doll.pop();
                        count += 2;
                    }
                    else {
                        doll.push(board[j][point]);
                    }
                }
                else {
                    doll.push(board[j][point]);
                }
                // 꺼냈으므로 0 처리
                board[j][point] = 0;
                break;
            }
        }
    }

    return count;
}