#include<string>
#include<stack>
#include<vector>

using namespace std;

int cnt = 0, Num0 = 0;

string del_zero(string s) {
    string str;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            str += s[i];
        else
            Num0++;
    }

    return str;
}

string binary_trans(string s) {
    int num = s.length();
    string str;
    while (num > 0) {
        str += num % 2 + '0';
        num /= 2;
    }
    cnt++;
    return str;
}

vector<int> solution(string s) {
    while (s != "1") {
        s = del_zero(s);
        s = binary_trans(s);
    }

    vector<int> result;
    result.push_back(cnt);
    result.push_back(Num0);
    return result;
}