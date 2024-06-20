// 1. unordered_map �ؽø� �̿��� ���� ���
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> map;

    // �� ��ȣ���� hash�� ����
    for (auto i : phone_book) {
        if (map.find(i) == map.end())
            map[i] = 1;
    }

    // �� ��ȣ�� �κ� ���ڿ��� �����ؼ� ���λ簡 �Ǵ� ���ڰ� �ִ��� Ȯ��
    for (auto i : map) {
        for (int j = 1; j < i.first.size(); j++) {
            string number = i.first.substr(0, j);
            if (map.find(number) != map.end())
                return false;
        }
    }

    return true;
}


// 2. ���İ� for ������ �̿��� ���� ���
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    // ���ڼ��� �ƴ϶� "������"���� ���ĵ�
    // i��°�� i+2��°�� ���� �ʿ䰡 ����
    // i���� ���ڿ��� i+2��° ���ڿ��� ���λ��� i+1��°�� i+2��°�� ���λ�� ������
    // substr(n,k): ���ڿ��� n�� �ε������� k����ŭ �ڸ�
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
            return false;
    }

    return true;
}
*/