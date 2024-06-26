#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return stoi(a + b) > stoi(b + a);
}

string solution(vector<int> numbers) {
    vector<string> strNum;
    // ���ڿ��� ����
    for (int i = 0; i < numbers.size(); i++) {
        strNum.push_back(to_string(numbers[i]));
    }

    // �������� ���� -> �ٿ����� �� ū ���� ����
    sort(strNum.begin(), strNum.end(), cmp);

    string answer = "";
    if (strNum[0] == "0")
        answer = "0";
    else {
        for (auto i : strNum) {
            answer += i;
        }
    }

    return answer;
}