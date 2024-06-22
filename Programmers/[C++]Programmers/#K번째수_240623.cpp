// 2�� Ǯ��
// vector�� .begin()�� �̿��Ͽ� �ڸ��� �Ͱ� ��� ���� ���ÿ� �����Ͽ� ����ȭ
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // command ������ŭ �ݺ� (return �迭 ��� ����)
    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0], // ������
            end = commands[i][1], // ����
            point = commands[i][2];

        // i-1���� j���� tmp�� ���
        vector<int> tmp(array.begin() + start - 1, array.begin() + end);

        // tmp ����
        sort(tmp.begin(), tmp.end());

        // k��° ���� �߰�
        answer.push_back(tmp[point - 1]);
    }

    return answer;
}


// 1�� Ǯ��
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // command ������ŭ �ݺ� (return �迭 ��� ����)
    for (int i = 0; i < commands.size(); i++) {
        // �ڸ� ���� ���� ����
        vector<int> tmp;
        // i-1���� j���� tmp�� ���
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            tmp.push_back(array[j]);
        }
        // tmp ����
        sort(tmp.begin(), tmp.end());
        // k��° ���� �߰�
        answer.push_back(tmp[commands[i][2] - 1]);
    }

    return answer;
}
*/