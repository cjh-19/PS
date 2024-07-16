#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// NN(idx==1), NNN(idx==1) ... 같은 형태를 만드는 함수
int Nset(int N, int idx) {
    int tmp = N;
    for (int i = 1; i <= idx; i++) {
        tmp = tmp * 10 + N;
    }
    return tmp;
}

int solution(int N, int number) {
    if (N == number) return 1;
    vector<unordered_set<int>> dp(8); // dp 배열, 중복 제거를 위해 unordered_set

    dp[0].insert(N);

    for (int k = 1; k < 8; k++) {
        // N(k==0), NN(k==1), NNN ... 추가
        dp[k].insert(Nset(N, k));

        // 사칙연산 결과 추가
        // k이전에 넣은 값을 이용(0번째부터 k-1번째까지)
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i + j + 1 != k) continue;

                // i+j+1 == k 일때
                for (int a : dp[i]) {
                    for (int b : dp[j]) {
                        dp[k].insert(a + b);
                        dp[k].insert(a - b);
                        dp[k].insert(a * b);
                        if (b != 0)
                            dp[k].insert(a / b);
                    }
                }
            }
        }

        // dp에 number의 값이 있다면 k+1 반환
        if (dp[k].find(number) != dp[k].end())
            return k + 1;
    }

    return -1;
}