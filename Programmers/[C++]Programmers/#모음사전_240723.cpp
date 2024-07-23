#include <string>
#include <vector>

using namespace std;

vector<char> alp = { 'A', 'E', 'I', 'O', 'U' };
int answer = 0;
int cnt = 0;
string target;

// ""부터 시작해서 target(word)과 같을때, 종료
// 실행할때마다 cnt++
void dfs(string start) {
    cnt++;

    if (start == target) {
        answer = cnt;
        return;
    }

    if (start.length() == 5) {
        return;
    }

    for (int i = 0; i < alp.size(); i++) {
        dfs(start + alp[i]);
    }
}

int solution(string word) {
    target = word;
    // dfs로 탐색
    dfs("");

    return answer - 1; // ""도 카운트 됐으므로 제외
}