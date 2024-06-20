#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string solution(string s) {
    string result = "";

    vector<int> v;
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            tmp += s[i];
        }
        else {
            v.push_back(stoi(tmp));
            tmp = "";
        }
    }
    v.push_back(stoi(tmp));

    sort(v.begin(), v.end());

    result = to_string(v.front()) + " " + to_string(v.back());
    return result;
}