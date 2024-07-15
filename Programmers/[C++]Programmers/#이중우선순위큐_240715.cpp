#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v; // 값 담을 백터

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            string tmp = operations[i].substr(2);
            v.push_back(stoi(tmp));
            sort(v.begin(), v.end());
        }
        else if (operations[i] == "D 1") { // 최댓값 삭제
            if (!v.empty())
                v.erase(v.begin() + v.size() - 1);
        }
        else if (operations[i] == "D -1") { // 최솟값 삭제
            if (!v.empty())
                v.erase(v.begin() + 0);
        }
    }
    if (v.empty())
        return { 0,0 };
    return { v[v.size() - 1], v[0] };
}