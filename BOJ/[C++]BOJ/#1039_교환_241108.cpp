#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

string change(string num, int count) {
    // k번 바꿀 문자열을 바꿀 큐
    queue<string> q;
    q.push(num);

    for (int i = 0; i < count; i++) {
        set<string> numset;
        // 큐에 담긴 숫자들을 하나씩 꺼내서 바꿀 수 있는 모든 경우의 수를 다시 큐에 담기
        // 이때, 큐에 담긴 것은 다시 담지 않도록 함(중복 제거)
        int qsize = q.size();
        for (int j = 0; j < qsize; j++) {
            string current = q.front();
            q.pop();
            if (numset.find(current) != numset.end()) continue; // 이미 set에 담긴 문자열이라면 패스(이미 해당 문자열에 대한 모든 경우의 수를 구한것)

            // 아직 안담은 문자열이라면 current 문자열 담고 모든 경우의 수 구하기
            numset.insert(current);
            for (int k = 0; k < current.length() - 1; k++) {
                for (int h = k + 1; h < current.length(); h++) {
                    if (!(k == 0 && current[h] == '0')) { // 맨 앞 숫자가 0이 아닌 경우만 추가
                        // 서로 변환한 문자열 큐에 담기
                        string tmp = current;
                        tmp[k] = current[h];
                        tmp[h] = current[k];
                        q.push(tmp);
                    }
                }
            }
        }
    }
    // for문 탈출하면 큐에 k번 반복해서 바꿨을때의 모든 경우의 수들이 담겨있음
    int maxnum = 0;
    while (!q.empty()) {
        maxnum = max(maxnum, stoi(q.front()));
        q.pop();
    }
    if (maxnum == 0) {
        return "-1";
    }

    return to_string(maxnum);
}

int main()
{
    string num;
    int count;
    cin >> num >> count;
    if (num.length() <= 1) {
        cout << -1;
        return 0;
    }

    cout << change(num, count);

    return 0;
}