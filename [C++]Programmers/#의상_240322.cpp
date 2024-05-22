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

/*
#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int cloth_count = 1;
    unordered_map<string, int> map;
    for (auto i : clothes) {
        if (map.find(i[1]) == map.end()) // ���� ���� ������� �ʾҴٸ�
            map[i[1]] = 2; // �ش��ϴ� ������ ����� �� 2�� �ʱ�ȭ(�����ʴ� ��� ����)
        else
            map[i[1]]++; // ���� �ϳ� �� ���� ��, ����� �� 1 ����
    }
    for (auto i : map) {
        cloth_count *= i.second; // �� �������� ����� �� ����
    }
    return cloth_count - 1; // �ƹ��͵� ���� �ʴ� ����� �� ���� ���
}
*/