#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tall[10];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> tall[i];
        sum += tall[i]; // ��ü ��
    }
    sort(tall, tall + 9); // �̸� ����
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - (tall[i] + tall[j]) == 100) {
                // 2���� �� ���� ���� 100�� �Ǹ�
                for (int z = 0; z < 9; z++) {
                    if (z != i && z != j) { // 2�� ���� ���
                        cout << tall[z] << '\n';
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}