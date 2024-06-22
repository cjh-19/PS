#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    // ����� ���� ��
    int count = 0;
    // ���� ����
    stack<int> doll;

    // ũ���� �̵� �ݺ�
    for (int i = 0; i < moves.size(); i++) {
        int point = moves[i] - 1;

        // 0�� �ƴ� ������ �ݺ�
        for (int j = 0; j < board.size(); j++) {
            if (board[j][point] != 0) {
                if (!doll.empty()) {
                    // �ٱ����� �ֻ�ܰ� ���� �������� Ȯ��
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
                // �������Ƿ� 0 ó��
                board[j][point] = 0;
                break;
            }
        }
    }

    return count;
}