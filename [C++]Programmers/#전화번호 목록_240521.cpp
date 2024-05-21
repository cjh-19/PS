// ���İ� for ������ �̿��� ���� ���

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    // i��°�� i+2��°�� ���� �ʿ䰡 ����
    // i���� ���ڿ��� i+2��° ���ڿ��� ���λ��� i+1��°�� i+2��°�� ���λ�� ������
    // substr(n,k): ���ڿ��� n�� �ε������� k����ŭ �ڸ�
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
            return false;
    }

    return true;
}