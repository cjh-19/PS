#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    // ���� ���� �ܾ� ����
    int count = 0;

    for (int i = 0; i < babbling.size(); i++) {
        bool check = true;
        string tmp = "";
        for (int j = 0; j < babbling[i].size(); j++) {
            if (babbling[i].substr(j, 3) == "aya") {
                if (tmp == "aya")
                    check = false;
                j += 2; // 2ĭ �� & �ݺ��� j + 1
                tmp = "aya";
            }
            else if (babbling[i].substr(j, 2) == "ye") {
                if (tmp == "ye")
                    check = false;
                j += 1;
                tmp = "ye";
            }
            else if (babbling[i].substr(j, 3) == "woo") {
                if (tmp == "woo")
                    check = false;
                j += 2;
                tmp = "woo";
            }
            else if (babbling[i].substr(j, 2) == "ma") {
                if (tmp == "ma")
                    check = false;
                j += 1;
                tmp = "ma";
            }
            else // ���� �Ұ����̸�
                check = false;
        }

        if (check == true)
            count += 1;
    }

    return count;
}