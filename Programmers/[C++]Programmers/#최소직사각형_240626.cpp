#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��������
bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<vector<int>> sizes) {
    // �� ������ ������������ ����
    for (int i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end(), cmp);
    }

    // ���ο��� ���� ū ���� ���ο��� ���� ū �� Ž��
    int xMax = 0, yMax = 0;
    for (int i = 0; i < sizes.size(); i++) {
        // ����
        xMax = max(xMax, sizes[i][0]);
        // ����
        yMax = max(yMax, sizes[i][1]);
    }

    return xMax * yMax;
}