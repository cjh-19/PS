#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int min = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < A.size(); i++) {
        int tmp = A[i] * B[i];
        min += tmp;
    }

    return min;
}