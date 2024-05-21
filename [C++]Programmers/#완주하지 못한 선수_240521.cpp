// �ؽ� �˰��� ��� ��� - unordered_map
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> map;

    for (auto i : participant) {
        // participant[i]�� map�� ����Ǿ����� ������ �����ϰ� �� 1 ����
        if (map.find(i) == map.end())
            map[i] = 1;
        else // �����ϸ� 1 ����
            map[i]++;
    }
    for (auto i : completion) {
        map[i]--; // ������ ��� map���� ����
    }
    for (auto i : map) {
        if (i.second != 0) // �������� ���� ���
            return i.first;
    }
}

// ���� ���

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i]; // �ٸ� ��Ҹ� �߰����ڸ��� ��ȯ�ؾ���
    }

    return participant[participant.size() - 1];
}
*/