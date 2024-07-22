#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    // next_permutation으로 모든 순열 조합을 얻기 위해서는 정렬
    sort(dungeons.begin(), dungeons.end());

    // 던전 순서를 순열로 돌며 탐색
    do {
        int ktmp = k; // 피로도
        int max = 0;
        for (int i = 0; i < dungeons.size(); i++) {
            // 현재 피로도 >= 던전 최소 피로도
            if (ktmp >= dungeons[i][0]) {
                ktmp -= dungeons[i][1]; // 피로도 소모
                max++;
            }
        }
        if (max > answer) answer = max;
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}