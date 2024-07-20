#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    set<int> nset;

    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int tmp = stoi(numbers.substr(0, i));
            if (isPrime(tmp))
                nset.insert(tmp);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = nset.size();

    return answer;
}