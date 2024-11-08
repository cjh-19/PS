#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

string change(string num, int count) {
    // k�� �ٲ� ���ڿ��� �ٲ� ť
    queue<string> q;
    q.push(num);

    for (int i = 0; i < count; i++) {
        set<string> numset;
        // ť�� ��� ���ڵ��� �ϳ��� ������ �ٲ� �� �ִ� ��� ����� ���� �ٽ� ť�� ���
        // �̶�, ť�� ��� ���� �ٽ� ���� �ʵ��� ��(�ߺ� ����)
        int qsize = q.size();
        for (int j = 0; j < qsize; j++) {
            string current = q.front();
            q.pop();
            if (numset.find(current) != numset.end()) continue; // �̹� set�� ��� ���ڿ��̶�� �н�(�̹� �ش� ���ڿ��� ���� ��� ����� ���� ���Ѱ�)

            // ���� �ȴ��� ���ڿ��̶�� current ���ڿ� ��� ��� ����� �� ���ϱ�
            numset.insert(current);
            for (int k = 0; k < current.length() - 1; k++) {
                for (int h = k + 1; h < current.length(); h++) {
                    if (!(k == 0 && current[h] == '0')) { // �� �� ���ڰ� 0�� �ƴ� ��츸 �߰�
                        // ���� ��ȯ�� ���ڿ� ť�� ���
                        string tmp = current;
                        tmp[k] = current[h];
                        tmp[h] = current[k];
                        q.push(tmp);
                    }
                }
            }
        }
    }
    // for�� Ż���ϸ� ť�� k�� �ݺ��ؼ� �ٲ������� ��� ����� ������ �������
    int maxnum = 0;
    while (!q.empty()) {
        maxnum = max(maxnum, stoi(q.front()));
        q.pop();
    }
    if (maxnum == 0) {
        return "-1";
    }

    return to_string(maxnum);
}

int main()
{
    string num;
    int count;
    cin >> num >> count;
    if (num.length() <= 1) {
        cout << -1;
        return 0;
    }

    cout << change(num, count);

    return 0;
}