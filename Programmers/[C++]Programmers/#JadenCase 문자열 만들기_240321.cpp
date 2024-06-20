#include<string>

using namespace std;

string solution(string s) {
    string result;
    int check = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (check == 0) {
                result += toupper(s[i]);
                check = 1;
            }
            else
                result += tolower(s[i]);
        }
        else {
            check = 0;
            result += ' ';
        }
    }
    return result;
}