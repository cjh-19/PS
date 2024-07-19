#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 501;
int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // dp 배열에 최상단 숫자 추가
    dp[0][0] = triangle[0][0];
    // Bottom-up으로 dp 배열 채우기
    for (int i = 1; i < triangle.size(); i++) {
        // depth가 i면 너비도 i개이므로 i만큼 반복
        for (int j = 0; j <= i; j++) {
            // 맨 왼쪽일때
            if (j == 0) {
                // 바로 위까지의 합과 현재 위치 값의 합
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            // 맨 오른쪽일때
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            // 둘다 아닐때
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }

            // 현재 depth에서 가장 값이 큰 값 answer에 저장
            answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}