#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tall[10];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> tall[i];
        sum += tall[i]; // 전체 합
    }
    sort(tall, tall + 9); // 미리 정렬
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - (tall[i] + tall[j]) == 100) {
                // 2명을 뺀 값의 합이 100이 되면
                for (int z = 0; z < 9; z++) {
                    if (z != i && z != j) { // 2명 빼고 출력
                        cout << tall[z] << '\n';
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}