#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;

const ll NUMEROUS = ULONG_MAX;

ll countPartitions(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    if (sum % 2 != 0) { // 전체 합이 짝수가 아니면 불가능
        return 0;
    }

    // sum 이 0 일때
    if (sum == 0) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            if (i != n - 1) {
                cout << ", ";
            }
        }
        cout << " } { }\n";
        return 0;
    }

    sum /= 2; // 두 subset의 합이 전체 합의 절반과 같아야 함

    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    ll ans = dp[n][sum];
    if (ans == 0) { // 불가능한 경우
        //cout << "No same-sum partition found. Closest-sum partition: ";
        // 두 subset의 합의 차이를 최소화하는 partition 출력
        vector<ll> subset1, subset2;
        int s1 = 0, s2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s1 <= s2) {
                subset1.push_back(nums[i]);
                s1 += nums[i];
            }
            else {
                subset2.push_back(nums[i]);
                s2 += nums[i];
            }
        }
        sort(subset1.begin(), subset1.end());
        sort(subset2.begin(), subset2.end());
        cout << "{ ";
        for (int i = 0; i < subset1.size(); i++) {
            cout << subset1[i];
            if (i != subset1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < subset2.size(); i++) {
            cout << subset2[i];
            if (i != subset2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
        return 0;
    }
    else if (ans > NUMEROUS) {
        cout << "NUMEROUS\n";
        return 0;
    }
    else {
        // 가능한 경우, 한 개 이상의 partition을 찾아 출력
        cout << /*"Number of partitions: " << */ans << "\n";
        //cout << "Possible partitions:\n";
        vector<int> p1, p2;
        int s = sum;
        for (int i = n - 1; i >= 0; i--) {
            if (s >= nums[i] && dp[i][s - nums[i]] > 0) { // 현재 원소를 p1에 넣을 수 있는 경우
                p1.push_back(nums[i]);
                s -= nums[i];
            }
            else { // 넣을 수 없는 경우 p
                p2.push_back(nums[i]);
            }
        }
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        cout << "{ ";
        for (int i = 0; i < p1.size(); i++) {
            cout << p1[i];
            if (i != p1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < p2.size(); i++) {
            cout << p2[i];
            if (i != p2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
        return ans;
    }
}

int main() {
    int n;
    while (1) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        countPartitions(nums);
    }
    return 0;
}