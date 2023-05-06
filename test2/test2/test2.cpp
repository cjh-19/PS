//unordered_map을 이용하여 음수인덱스도 처리한 방법
//가장 최신의 구현 파일

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;

const ll NUMEROUS = ULONG_MAX;

//ll countPartitions(vector<int>& nums) {
//    int n = nums.size();
//    int sum_neg = 0, sum_pos = 0;
//    for (int num : nums)
//    {
//        if (num < 0)
//            sum_neg += num;
//        else
//            sum_pos += num;
//    }
//
//    // Total sum of the array.
//    int sum = sum_pos + sum_neg;
//
//    //합이 홀수 일때 subset을 나눔
//    //sum /= 2;
//    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
//    //초기화
//    /*for (int i = 0; i <= n; i++)
//        dp[i][0] = 1;
//    for (int i = 0; i <= sum; i++)
//        dp[0][i] = 0;
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = sum_neg; j <= sum_pos; j++) {
//            if (j - nums[i - 1] >= sum_neg) {
//                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//                cout << dp[i][j] << " ";
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];
//                cout << dp[i][j] << " ";
//            }
//        }
//        cout << "\n";
//    }*/
//        
//    
//    for (int i = 1; i < n; i++)
//    {
//        // Iterate on all possible subset sum.
//        for (int j = sum_neg; j <= sum_pos; j++)
//        {
//            // dp state-transition:
//
//            // 1) state(i, j) = state(i - 1, j) without taking current element.
//            dp[i][j] = dp[i - 1][j];
//
//            // 2) if j == nums[i], just taking i-th element is sufficient.
//            if (j == nums[i])
//                dp[i][j] += 1;
//            else if (j - nums[i] >= sum_neg)
//            {
//                // 3) state(i, j) = state(i - 1, j - nums[i]) when taking current element.
//                dp[i][j] = dp[i-1][j] + dp[i - 1][j - nums[i]];
//            }
//            cout << dp[i][j] << ' ';
//        }
//        cout << "\n";
//    }
//
//    sum /= 2;
//    ll ans = dp[n][sum];
//    cout << ans;
//    return 0;
//}

vector<bool> equal_subset_sum_partition(vector<int>& nums)
{
    // Store min and max sum possible for given array.
    //음수의 합과 양수의 합을 따로 나눈다. 모든 합의 경우를 구하기 위해서. dp[i][val] 에서 val의 시작점과 끝점을 이렇게 정한다.
    int sum_neg = 0, sum_pos = 0, count = 0;
    for (auto val : nums)
    {
        if (val < 0)
            sum_neg += val;
        else
            sum_pos += val;
    }

    // Total sum of the array.
    // 모든 항목의 합
    int sum = sum_pos + sum_neg;
    // Partition not possible.
    // 두 부분집합의 합이 홀수 인 경우
    if (sum & 1)
    {
        return vector<bool>();
    }

    int n = nums.size();

    // dp state
    unordered_map<int, int> *dp = new unordered_map<int, int>[n];
    // dp2는 subset 합이 다를경우
    unordered_map<int, bool> *dp2 = new unordered_map<int, bool>[n];

    // Base state:
    // for idx 0 only one sum nums[0] is possible
    dp[0][nums[0]] = 0; //dp[i][j] : i번째 인덱스까지 고려한 배열의 부분집합 중에서 합이 j인 것이 존재한다면 +1 이다.
    dp2[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        // Iterate on all possible subset sum.
        for (int val = sum_neg; val <= sum_pos; val++)
        {
            // dp state-transition:

            // 1) state(i, val) = state(i - 1, val) without taking current element.
            dp[i][val] = dp[i - 1][val];
            dp2[i][val] = dp2[i - 1][val];

            // 2) if val == s[i], just taking i-th element is sufficient.
            if (val == nums[i]) {
                dp[i][val] += 1; // 합이 val인 것이 존재한다면 +1 한다
                dp2[i][val] = true;
                cout << "[" << i << ' ' << val << "]" << dp[i][val] << " ";
            }
            else if (val - nums[i] >= sum_neg)
            {
                // 3) state(i, val) = state(i - 1, val - s[i]) when taking current element.
                dp[i][val] = dp[i-1][val] + dp[i - 1][val - nums[i]];
                dp2[i][val] |= dp2[i - 1][val - nums[i - 1]];
                cout << "[" << i << ' ' << val << "]" << dp[i][val] << " ";
            }
        }
        cout << "\n";
    }
    
    int required = sum / 2;
    int idx = n - 1;
    //count : 모든 부분집합의 경우의 수
    count = dp[idx][required];
    // Parition not possible. //subset 합이 같지 않은 경우
    if (!dp[idx][required])
    {
        //vector<bool> ret;
        //return ret;
        
        // Initialize difference of two sums.
        int diff = INT_MAX;

        // Find the largest j such that dp2[n][j]
        // is true where j loops from sum/2 t0 0
        // sum/2 부터 0까지의 j루프
        // dp2[n][j]에 가장 가까운 j값을 찾는 것?
        // diff는 두 합의 가장 작은 차이
        // 그러면 sum - j - j
        // 두 집합의 합을 각 s1 s2라고 하면
        // |s1 - s2| == sum - (j + j)
        // 만약 sum을 11 이라고 한다.
        // 그러면 diff 를 3이라했을때
        // 4와7밖에 없다.
        // sum = 11, 2*j = 8 이다. j=4
        // j가 4인 이유는?
        // 우리가 할 것은 dp2[n][j]를 이용하여 최소가
        // 될 때의 집합을 찾는 것이다.
        for (int j = required; j >= 0; j--) {
            // Find the
            if (dp2[n][j] == true) {
                diff = sum - 2 * j;
                break;
            }
        }
    }

    // Tracks partition elements.
    vector<bool> result_subset(nums.size(), 0);
    // Tracks count of elements included in S1.
    int cnt = 0;
    while (idx >= 0)
    {
        if (idx != 0)
        {
            // Reverse dp transition.
            if (dp[idx][required] and !dp[idx - 1][required])
            {
                result_subset[idx] = 1;
                cnt++;
                required -= nums[idx];
                if (required == 0)
                    break;
            }
        }
        else
        {
            result_subset[idx] = 1;
            cnt++;
        }
        idx--;
    }

    // Checks whether all elements are included in S1.
    // All elements will be in S1 if total_sum = 0
    // case when s = [-2, 2]
    // partition is not possible in this case.

    if (cnt == n)
    {
        result_subset.clear();
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            if (i != n - 1) {
                cout << ", ";
            }
        }
        cout << " } { }\n";
        return result_subset;
    }


    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        //cout << result_subset[i] << " ";
        if (result_subset[i] == 0)
            s1.push_back(nums[i]);
        else
            s2.push_back(nums[i]);
       
    }
    if (s1[0] < s2[0]) {
        cout << "{ ";
        for (int i = 0; i < s1.size(); i++) {
            cout << s1[i];
            if (i != s1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < s2.size(); i++) {
            cout << s2[i];
            if (i != s2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
        cout << "개수 : " << count << "\n";
        return result_subset;
    }
    else {
        cout << "{ ";
        for (int i = 0; i < s2.size(); i++) {
            cout << s2[i];
            if (i != s2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < s1.size(); i++) {
            cout << s1[i];
            if (i != s1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
        cout << "개수 : " << count << "\n";
        return result_subset;
    }


    delete[] dp;
    delete[] dp2;

    return result_subset;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            cout << nums[i] << ' ';
        cout << " \n";
        //countPartitions(nums);
        equal_subset_sum_partition(nums);
    }
    return 0;
}