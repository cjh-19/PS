#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, Q;
vector<vector<int>> board;
vector<vector<tuple<int, int, int>>> micro;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 크기 -> 등록순 정렬
bool cmp(vector<tuple<int, int, int>> v1, vector<tuple<int, int, int>> v2) {
    if (v1.size() != v2.size()) return v1.size() > v2.size();
    return get<2>(v1[0]) < get<2>(v2[0]);
}

// 미생물 지우기
void microErase(int x, int y, int n) {
    for (int i = 0; i < micro.size(); ) {

        for (int j = 0; j < micro[i].size(); j++) {
            if (get<0>(micro[i][j]) == x && get<1>(micro[i][j]) == y && get<2>(micro[i][j]) == n) {
                micro[i].erase(micro[i].begin() + j);
                break;
            }
        }

        if (micro[i].empty()) {
            micro.erase(micro.begin() + i); // erase 했으면 i 유지
        }
        else {
            i++; // erase 안 했으면 i 증가
        }
    }
}

// 보드에 미생물 추가(+덮어씌우기)
void addBoard(int r1, int c1, int r2, int c2, int num) {
    vector<tuple<int, int, int>> tmp;
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            // 기존 미생물이 존재하면 해당 미생물 vector에서 삭제
            if (board[i][j] != 0) {
                microErase(i, j, board[i][j]);
            }
            // 덮어씌우기
            board[i][j] = num;
            tmp.push_back({ i, j, num });
        }
    }
    micro.push_back(tmp);
}

bool bfs(int num) {
    // micro의 num번째 인덱스의 미생물 bfs 실행
    int msize = micro[num].size();
    int x = get<0>(micro[num][0]);
    int y = get<1>(micro[num][0]);
    int idx = get<2>(micro[num][0]); // 미생물 번호
    bool visited[51][51] = { false, };

    int cnt = 1;

    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || board[nx][ny] != idx) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
            cnt++;
        }
    }

    return cnt == msize;
}

bool checkMove(int x, int y, int num) {
    // 1) 현재 미생물이 차지하는 최소(r1,c1)를 찾아서
    int r1 = INT_MAX, c1 = INT_MAX;
    for (auto& t : micro[num]) {
        r1 = min(r1, get<0>(t));
        c1 = min(c1, get<1>(t));
    }

    // 2) 실제 남아 있는 각 셀만 새 위치에 충돌 없이 들어갈 수 있는지 검사
    for (auto& t : micro[num]) {
        int oldX = get<0>(t);
        int oldY = get<1>(t);
        int newX = x + (oldX - r1);
        int newY = y + (oldY - c1);

        // 범위 벗어나거나 이미 다른 미생물이 있으면 실패
        if (newX < 0 || newX >= N || newY < 0 || newY >= N || board[newX][newY] != 0)
            return false;
    }
    return true;
}

void move(int x, int y, int num) {
    // 1) 덩어리의 최소 r1,c1 계산
    int r1 = INT_MAX, c1 = INT_MAX;
    for (auto& t : micro[num]) {
        r1 = min(r1, get<0>(t));
        c1 = min(c1, get<1>(t));
    }

    // 2) (x,y) 위치가 이 r1,c1 이 오도록 dx,dy 계산
    int dx = x - r1;
    int dy = y - c1;

    // 3) 각 좌표를 동일한 dx,dy 만큼 이동
    for (auto& t : micro[num]) {
        int oldX = get<0>(t), oldY = get<1>(t), id = get<2>(t);
        t = { oldX + dx, oldY + dy, id };
    }
}

bool moveMicro(int num) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (checkMove(i, j, num)) {
                move(i, j, num);
                return true;
            }
        }
    }
    return false;
}

int score() {
    int total = 0;
    int msize = micro.size();

    for (int i = 0; i < msize; i++) {
        for (int j = i + 1; j < msize; j++) {
            for (const auto& t1 : micro[i]) {
                int x1 = get<0>(t1);
                int y1 = get<1>(t1);
                for (const auto& t2 : micro[j]) {
                    int x2 = get<0>(t2);
                    int y2 = get<1>(t2);
                    if (abs(x1 - x2) + abs(y1 - y2) == 1) {
                        total += micro[i].size() * micro[j].size();
                        goto NEXT;
                    }
                }
            }
        NEXT:;
        }
    }

    return total;
}

int main() {
    cin >> N >> Q;
    board.resize(51, vector<int>(51));

    for (int i = 1; i <= Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // 1. 미생물 투입 (i번째 미생물)
        // 미생물 좌표에 기록하고, 분리된 미생물있는지 확인 -> 소멸
        addBoard(r1, c1, r2, c2, i);

        vector<int> eraselist;
        for (int j = 0; j < micro.size(); j++) {
            if (!bfs(j)) {
                eraselist.push_back(j);
            }
        }
        // 역순으로 삭제
        for (int j = eraselist.size() - 1; j >= 0; j--) {
            int num = eraselist[j];
            for (auto t1 : micro[num]) {
                int x = get<0>(t1);
                int y = get<1>(t1);
                board[x][y] = 0;
            }
            micro.erase(micro.begin() + num);
        }

        // 2. 배양 용기 이동
        // micro vector 정렬 => 크기 -> 등록순(2번 인덱스)으로 정렬
        // 보드 초기화 후, 재입력
        // 이동 못하는 미생물은 제거
        sort(micro.begin(), micro.end(), cmp);
        board.clear();
        board.resize(51, vector<int>(51, 0));
        eraselist.clear();
        for (int j = 0; j < micro.size(); j++) {
            if (moveMicro(j)) {
                for (auto& t : micro[j]) {
                    int x = get<0>(t), y = get<1>(t), id = get<2>(t);
                    board[x][y] = id;
                }
            }
            else {
                eraselist.push_back(j);
            }
        }
        sort(eraselist.begin(), eraselist.end());
        for (int j = eraselist.size() - 1; j >= 0; j--) {
            micro.erase(micro.begin() + eraselist[j]);
        }

        // 3. 실험 결과 기록
        // 모든 인접한 무리 쌍을 확인 & 각 쌍의 성과 더히고 출력
        cout << score() << "\n";
    }

    return 0;
}