#include <bits/stdc++.h>

using namespace std;

int world[501][501];
int H, W;

int waterCal() {
    int water = 0;
    // �ٴ� ����� Ž��
    // ��� - ��� ������ ĭ�� ����ϰ� �����ٸ� ���ϱ�
    for (int h = H - 1; h >= 0; h--) {
        int startblock = -1;
        int endblock = -1;
        for (int w = 0; w < W; w++) {
            // ����̶��
            if (world[w][h] == 1) {
                // ���ۺ���� �߰����� ���� ���¶��
                if (startblock == -1) {
                    startblock = w;
                }
                else {
                    endblock = w;

                    // ���� �߰�
                    water += endblock - startblock - 1;

                    // ���� ��� �ʱ�ȭ
                    startblock = w;
                }
            }
        }
    }
    return water;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        int depth;
        cin >> depth;
        for (int j = H - 1; j > H - 1 - depth; j--) {
            world[i][j] = 1; // 1�̸� ��� ����
        }
    }

    int result = waterCal();

    return 0;
}