#include<queue>
#include<string>

using namespace std;

bool solution(string s) {
    queue<char> Q;
    for (int i = 0; i < s.length(); i++) {
        Q.push(s[i]);
    }
    string tmp;

    if (s[0] == ')' || s[s.length() - 1] == '(')
        return false;

    int count = 0;
    while (!Q.empty()) {
        if (Q.front() == '(')
            count++;
        else
            count--;
        Q.pop();
        if (count < 0)
            return false;
    }

    if (count == 0)
        return true;
    else
        return false;
}