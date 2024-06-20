// unordered_map, pair, custom sort ��� �̿�

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// ���Ƚ���� ������ �ε��� ��������, �⺻�����δ� Ƚ�� �������� ����
bool cmp(pair<int, int> v1, pair<int, int> v2) {
    if (v1.first == v2.first)
        return v1.second < v2.second; // �ε��� ��������
    else
        return v1.first > v2.first; // Ƚ�� ��������
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> map1; // �帣, �帣�� �� Ƚ��
    unordered_map<string, vector<pair<int, int>>> map2; // �帣, <Ƚ��, �ε���>

    for (int i = 0; i < genres.size(); i++) {
        map1[genres[i]] += plays[i];
        map2[genres[i]].push_back({ plays[i], i });
    }

    for (int k = 0; k < map1.size(); k++) {
        string max_gen;
        int max = 0;
        // �� Ƚ���� ���� ���� �帣 ã��
        for (auto i : map1) {
            if (i.second > max) {
                max = i.second;
                max_gen = i.first;
            }
        }
        map1[max_gen] = 0; // ���� ���� �帣�� Ƚ�� 0���� �ʱ�ȭ

        // &ió�� &�� ����ؾ� �ϴ� ����: ���� ��Ҹ� ���� �����Ͽ� ���� ������ ��Ҹ� �����ϱ� ���ؼ��̴�.
        // ���� ������ �����ϱ� ����. "i"�� �׳� ����ϰ� �Ǹ� ���纻�� �۾��ϹǷ� ���� �ʿ� �ƹ��� ������ ���� ���Ѵ�.
        // map2���� max_gen�� �ش��ϴ� vector ���� �� 1,2 ���� ����
        for (auto &i : map2) {
            if (i.first == max_gen) {
                // �̰��� ���� �����ϴ� ���� �ƴ� �� ������ vector�� �����ϴ� ��
                sort(i.second.begin(), i.second.end(), cmp);
                answer.push_back(i.second[0].second);
                if (i.second.size() > 1) { // �帣�� ���� ���� �ΰ� �̻��̶��
                    answer.push_back(i.second[1].second);
                }
            }
        }
    }

    return answer;
}