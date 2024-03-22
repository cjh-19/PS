#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    // �� �ǻ� ���� ���� ����
    for (auto i : clothes) {
        m[i[1]]++;
    }

    // ����� �� ����
    for (auto i : m) {
        answer *= i.second + 1; // �ǻ��� �������� �ʴ� ����� �� +1 �߰�
    }

    // �ƹ��͵� ���� �ʴ� ��� ����
    answer--;

    return answer;
}