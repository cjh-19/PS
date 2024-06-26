#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 내림차순
bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<vector<int>> sizes) {
    // 각 명함을 내림차순으로 정렬
    for (int i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end(), cmp);
    }

    // 가로에서 가장 큰 수와 세로에서 가장 큰 수 탐색
    int xMax = 0, yMax = 0;
    for (int i = 0; i < sizes.size(); i++) {
        // 가로
        xMax = max(xMax, sizes[i][0]);
        // 세로
        yMax = max(yMax, sizes[i][1]);
    }

    return xMax * yMax;
}