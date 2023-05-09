//test2를 코딩하기 위해 참고할 코드들

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;

const ll NUMEROUS = ULONG_MAX;


ll findMin(vector<int>& nums);
ll countPartitions(vector<int>& nums);

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        countPartitions(nums);
    }
    return 0;
}

ll findMin(vector<int>& nums)
{
    int n = nums.size();
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    // Create an array to store results of subproblems
    //bool dp[n + 1][sum + 1];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    cout << diff << "\n";
    return diff;
}

//ll findMin(vector<int>& nums) {
//    int n = nums.size();
//    // Calculate sum of all elements
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//        sum += nums[i];
//
//    // Create an array to store results of subproblems
//    bool** dp = new bool*[n + 1];
//    for (int i = 0; i < n; i++) {
//        dp[i] = new bool[sum + 1];
//    }
//    //bool dp[n + 1][sum + 1];
//    //vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
//
//    // Initialize first column as true. 0 sum is possible
//    // with all elements.
//    for (int i = 0; i <= n; i++)
//        dp[i][0] = true;
//
//    // Initialize top row, except dp[0][0], as false. With
//    // 0 elements, no other sum except 0 is possible
//    for (int i = 1; i <= sum; i++)
//        dp[0][i] = false;
//
//    // Fill the partition table in bottom up manner
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= sum; j++) {
//            // If i'th element is excluded
//            dp[i][j] = dp[i - 1][j];
//
//            // If i'th element is included
//            if (nums[i - 1] <= j)
//                dp[i][j] |= dp[i - 1][j - nums[i - 1]];
//        }
//    }
//
//    // Initialize difference of two sums.
//    ll diff = ULONG_MAX;
//
//    // Find the largest j such that dp[n][j]
//    // is true where j loops from sum/2 t0 0
//    for (int j = sum / 2; j >= 0; j--) {
//        // Find the
//        if (dp[n][j] == true) {
//            diff = sum - 2 * j;
//            /*
//            vector<int> p1, p2;
//            int s = sum;
//            for (int i = n - 1; i >= 0; i--) {
//                if (nums[i] < 0) {
//                    if (s >= -nums[i] && dp[i][s + nums[i]] == true) { // 현재 원소를 p1에 넣을 수 있는 경우
//                        p1.push_back(nums[i]);
//                        s += nums[i];
//                    }
//                    else { // 넣을 수 없는 경우 p
//                        p2.push_back(nums[i]);
//                    }
//                }
//                else {
//                    if (s >= nums[i] && dp[i][s - nums[i]] == true) { // 현재 원소를 p1에 넣을 수 있는 경우
//                        p1.push_back(nums[i]);
//                        s -= nums[i];
//                    }
//                    else { // 넣을 수 없는 경우 p
//                        p2.push_back(nums[i]);
//                    }
//                }
//            }
//            sort(p1.begin(), p1.end());
//            sort(p2.begin(), p2.end());
//            cout << "{ ";
//            for (int i = 0; i < p1.size(); i++) {
//                cout << p1[i];
//                if (i != p1.size() - 1) {
//                    cout << ", ";
//                }
//            }
//            cout << " } { ";
//            for (int i = 0; i < p2.size(); i++) {
//                cout << p2[i];
//                if (i != p2.size() - 1) {
//                    cout << ", ";
//                }
//            }
//            cout << " }\n";*/
//            break;
//        }
//    }
//    for (int i = 0; i < n; i++)
//        delete[] dp[i];
//    delete[] dp;
//    cout << diff << "\n";
//    return diff;
//}

ll countPartitions(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    //홀수 체크 할 때 tmp 사용
    int tmp = sum;

    //합이 음수일 때
    if (sum < 0) {
        sum *= -1;
        //for (int i = 0; i < n; i++)
        //    nums[i] *= -1;
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
    // unordered_map<int, bool> *dp = new unordered_map<int, bool>[n];
    //초기화
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (nums[i - 1] < 0) {
                if (j >= -nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j + nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
                cout << dp[i][j] << ' ';
            }
            else {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
                cout << dp[i][j] << ' ';
            }
        }
        cout << "\n";
    }

    ll ans = dp[n][sum];
    //헷갈림 잘 확인할 것
    if (ans == 0 || tmp % 2 != 0) { // 불가능한 경우, 합이 홀수인경우
        cout << "No same-sum partition found. Closest-sum partition: ";
        //findMin(nums);
        // 두 subset의 합의 차이를 최소화하는 partition 출력
        vector<ll> subset1, subset2;
        int s1 = 0, s2 = 0;
        if (tmp < 0) {
            for (int i = 0; i <= n - 1; i++) {
                if (s1 >= s2) {
                    subset1.push_back(nums[i]);
                    s1 += nums[i];
                }
                else {
                    subset2.push_back(nums[i]);
                    s2 += nums[i];
                }
            }
        }
        else {
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
    //음수가 들어가면 딴길로 샘, dp[i][1] = 0 인데 1이 생김. 이게 문제인가?
    else {
        // 가능한 경우, 한 개 이상의 partition을 찾아 출력
        cout << "Number of partitions: " << ans << "\n";
        cout << "Possible partitions:\n";
        vector<int> p1, p2;
        int s = sum;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < 0) {
                if (s >= -nums[i] && dp[i][s + nums[i]] > 0) { // 현재 원소를 p1에 넣을 수 있는 경우
                    p1.push_back(nums[i]);
                    s += nums[i];
                }
                else { // 넣을 수 없는 경우 p
                    p2.push_back(nums[i]);
                }
            }
            else {
                if (s >= nums[i] && dp[i][s - nums[i]] > 0) { // 현재 원소를 p1에 넣을 수 있는 경우
                    p1.push_back(nums[i]);
                    s -= nums[i];
                }
                else { // 넣을 수 없는 경우 p
                    p2.push_back(nums[i]);
                }
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






//음수 입력 고려하려다가 코드이해가 안되서 포기

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//using ll = long long;
//
//const ll NUMEROUS = ULONG_MAX;
//
//ll countPartitions(vector<int>& nums) {
//    int n = nums.size();
//    
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
//    if (sum % 2 != 0) {
//        sum /= 2;
//        vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
//        //초기화
//        for (int i = 0; i <= n; i++)
//            dp[i][0] = 1;
//        for (int i = 0; i <= sum; i++)
//            dp[0][i] = 0;
//
//        /*for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= sum; j++) {
//                if (j >= nums[i - 1]) {
//                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//                }
//                else {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }*/
//
//        for (int i = 1; i < n; i++)
//        {
//            // Iterate on all possible subset sum.
//            for (int j = sum_neg; j <= sum_pos; j++)
//            {
//                // dp state-transition:
//
//                // 1) state(i, val) = state(i - 1, val) without taking current element.
//                dp[i][j] = dp[i - 1][j];
//
//                // 2) if val == s[i], just taking i-th element is sufficient.
//                if (j == nums[i])
//                    dp[i][j] = true;
//                else if (j - nums[i] >= sum_neg)
//                {
//                    // 3) state(i, val) = state(i - 1, val - s[i]) when taking current element.
//                    dp[i][j] |= dp[i - 1][j - nums[i]];
//                }
//            }
//        }
//
//        ll ans = dp[n][sum];
//
//        cout << "No same-sum partition found. Closest-sum partition: ";
//        // 두 subset의 합의 차이를 최소화하는 partition 출력
//        vector<ll> subset1, subset2;
//        int s1 = 0, s2 = 0;
//        for (int i = n - 1; i >= 0; i--) {
//            if (s1 <= s2) {
//                subset1.push_back(nums[i]);
//                s1 += nums[i];
//            }
//            else {
//                subset2.push_back(nums[i]);
//                s2 += nums[i];
//            }
//        }
//        sort(subset1.begin(), subset1.end());
//        sort(subset2.begin(), subset2.end());
//        cout << "{ ";
//        for (int i = 0; i < subset1.size(); i++) {
//            cout << subset1[i];
//            if (i != subset1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < subset2.size(); i++) {
//            cout << subset2[i];
//            if (i != subset2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//        return 0;
//    }
//
//    // sum 이 0 일때
//    if (sum == 0) {
//        cout << "{ ";
//        for (int i = 0; i < n; i++) {
//            cout << nums[i];
//            if (i != n - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { }\n";
//        return 0;
//    }
//
//    sum /= 2; // 두 subset의 합이 전체 합의 절반과 같아야 함
//
//    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
//    //초기화
//    for (int i = 0; i <= n; i++)
//        dp[i][0] = 1;
//    for (int i = 0; i <= sum; i++)
//        dp[0][i] = 0;
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= sum; j++) {
//            if (j >= nums[i - 1]) {
//                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    ll ans = dp[n][sum];
//    if (ans == 0) { // 불가능한 경우
//        cout << "No same-sum partition found. Closest-sum partition: ";
//        // 두 subset의 합의 차이를 최소화하는 partition 출력
//        vector<ll> subset1, subset2;
//        int s1 = 0, s2 = 0;
//        for (int i = n - 1; i >= 0; i--) {
//            if (s1 <= s2) {
//                subset1.push_back(nums[i]);
//                s1 += nums[i];
//            }
//            else {
//                subset2.push_back(nums[i]);
//                s2 += nums[i];
//            }
//        }
//        sort(subset1.begin(), subset1.end());
//        sort(subset2.begin(), subset2.end());
//        cout << "{ ";
//        for (int i = 0; i < subset1.size(); i++) {
//            cout << subset1[i];
//            if (i != subset1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < subset2.size(); i++) {
//            cout << subset2[i];
//            if (i != subset2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//        return 0;
//    }
//    else if (ans > NUMEROUS) {
//        cout << "NUMEROUS\n";
//        return 0;
//    }
//    else {
//        // 가능한 경우, 한 개 이상의 partition을 찾아 출력
//        cout << "Number of partitions: " << ans << "\n";
//        cout << "Possible partitions:\n";
//        vector<int> p1, p2;
//        int s = sum;
//        for (int i = n - 1; i >= 0; i--) {
//            if (s >= nums[i] && dp[i][s - nums[i]] > 0) { // 현재 원소를 p1에 넣을 수 있는 경우
//                p1.push_back(nums[i]);
//                s -= nums[i];
//            }
//            else { // 넣을 수 없는 경우 p
//                p2.push_back(nums[i]);
//            }
//        }
//        sort(p1.begin(), p1.end());
//        sort(p2.begin(), p2.end());
//        cout << "{ ";
//        for (int i = 0; i < p1.size(); i++) {
//            cout << p1[i];
//            if (i != p1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < p2.size(); i++) {
//            cout << p2[i];
//            if (i != p2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//        return ans;
//    }
//}
//
//int main() {
//    int n;
//    while (cin >> n) {
//        vector<int> nums(n);
//        for (int i = 0; i < n; i++) {
//            cin >> nums[i];
//        }
//        sort(nums.begin(), nums.end());
//        countPartitions(nums);
//    }
//    return 0;
//}




///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////












//Asymptotic complexity in terms of the length of \`s\` (\`n\`) and the absolute difference between
//the maximum sum and the minimum sum possible in the given input array \`s\` (\`range_sum\`):
//* Time: O(n * range_sum).
//* Auxiliary space: O(n * range_sum).
//* Total space: O(n * range_sum).

//vector<bool> equal_subset_sum_partition(vector<int>& s)
//{
//    // Store min and max sum possible for given array.
//    int sum_neg = 0, sum_pos = 0;
//    for (auto val : s)
//    {
//        if (val < 0)
//            sum_neg += val;
//        else
//            sum_pos += val;
//    }
//
//    // Total sum of the array.
//    int sum = sum_pos + sum_neg;
//    // Partition not possible.
//    if (sum & 1)
//    {
//        return vector<bool>();
//    }
//
//    int n = s.size();
//
//    // dp state
//    unordered_map<int, bool> dp[n];
//
//    // Base state:
//    // for idx 0 only one sum s[0] is possible
//    dp[0][s[0]] = true;
//
//    for (int i = 1; i < n; i++)
//    {
//        // Iterate on all possible subset sum.
//        for (int val = sum_neg; val <= sum_pos; val++)
//        {
//            // dp state-transition:
//
//            // 1) state(i, val) = state(i - 1, val) without taking current element.
//            dp[i][val] = dp[i - 1][val];
//
//            // 2) if val == s[i], just taking i-th element is sufficient.
//            if (val == s[i])
//                dp[i][val] = true;
//            else if (val - s[i] >= sum_neg)
//            {
//                // 3) state(i, val) = state(i - 1, val - s[i]) when taking current element.
//                dp[i][val] |= dp[i - 1][val - s[i]];
//            }
//        }
//    }
//
//    int required = sum / 2;
//    int idx = n - 1;
//
//    // Parition not possible.
//    if (!dp[idx][required])
//    {
//        vector<bool> ret;
//        return ret;
//    }
//
//    // Tracks partition elements.
//    vector<bool> result_subset(s.size(), 0);
//    // Tracks count of elements included in S1.
//    int cnt = 0;
//    while (idx >= 0)
//    {
//        if (idx != 0)
//        {
//            // Reverse dp transition.
//            if (dp[idx][required] and !dp[idx - 1][required])
//            {
//                result_subset[idx] = 1;
//                cnt++;
//                required -= s[idx];
//                if (required == 0)
//                    break;
//            }
//        }
//        else
//        {
//            result_subset[idx] = 1;
//            cnt++;
//        }
//        idx--;
//    }
//
//    // Checks whether all elements are included in S1.
//    // All elements will be in S1 if total_sum = 0
//    // case when s = [-2, 2]
//    // partition is not possible in this case.
//    if (cnt == n)
//    {
//        result_subset.clear();
//    }
//    return result_subset;
//}


















//가장 참고할만 한 코드

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//using ll = long long;
//
//ll countPartitions(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (int num : nums) {
//        sum += num;
//    }
//
//    if (sum % 2 != 0) { // 전체 합이 짝수가 아니면 불가능
//        return 0;
//    }
//
//    sum /= 2; // 두 subset의 합이 전체 합의 절반과 같아야 함
//
//    unordered_map<int, ll> dp;
//    dp[0] = 1; // 빈 subset으로 만들 수 있는 경우의 수는 1
//
//    for (int num : nums) {
//        for (int s = sum; s >= num; s--) {
//            dp[s] += dp[s - num];
//        }
//    }
//
//    if (dp[sum] == 0) { // 불가능한 경우
//        return 0;
//    }
//
//    // 가능한 경우, 한 개 이상의 partition을 찾아 출력
//    cout << "Possible partitions:\n";
//    vector<int> p1, p2;
//    int s = sum;
//    for (int i = n - 1; i >= 0; i--) {
//        if (s >= nums[i] && dp[s - nums[i]] > 0) { // 현재 원소를 p1에 넣을 수 있는 경우
//            p1.push_back(nums[i]);
//            s -= nums[i];
//        }
//        else { // 넣을 수 없는 경우 p2에 넣음
//            p2.push_back(nums[i]);
//        }
//    }
//
//    // p1, p2 출력
//    cout << "{ ";
//    for (int i = 0; i < p1.size(); i++) {
//        cout << p1[i];
//        if (i != p1.size() - 1) {
//            cout << ", ";
//        }
//    }
//    cout << " } { ";
//    for (int i = 0; i < p2.size(); i++) {
//        cout << p2[i];
//        if (i != p2.size() - 1) {
//            cout << ", ";
//        }
//    }
//    cout << " }\n";
//
//    return dp[sum];
//}
//
//int main() {
//    int n;
//    while (cin >> n) {
//        if (n == 0) {
//            break;
//        }
//        vector<int> nums(n);
//        for (int i = 0; i < n; i++) {
//            cin >> nums[i];
//        }
//        ll ans = countPartitions(nums);
//        if (ans > 0) {
//            cout << "Number of partitions: " << ans << "\n";
//        }
//        else {
//            cout << "No same-sum partition found. Closest-sum partition: ";
//            // 어느 subset에 들어가야할지 모르므로 전체를 p1에 넣음
//            for (int num : nums) {
//                cout << num << " ";
//            }
//            cout << "\n";
//        }
//    }
//    return 0;
//}












//참고 할만한 코드.

//#include <iostream>
//#include <cstring>
//#include <climits>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAX_N = 500;
//const int MAX_SUM = 500 * 100 + 1;
//
//int n;
//int nums[MAX_N];
//bool dp[MAX_SUM];
//
//ll countPartitions() {
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += nums[i];
//    }
//
//    if (sum % 2 != 0) {
//        return 0; // No partition exists
//    }
//
//    memset(dp, false, sizeof(dp));
//    dp[0] = true;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = sum / 2; j >= nums[i]; j--) {
//            dp[j] |= dp[j - nums[i]];
//        }
//    }
//
//    if (!dp[sum / 2]) {
//        return 0; // No partition exists
//    }
//
//    ll numPartitions = 1;
//    vector<int> partition1, partition2;
//
//    int diff = sum;
//    int i = n - 1, j = sum / 2;
//    while (j > 0) {
//        if (j >= nums[i] && dp[j - nums[i]]) {
//            partition1.push_back(nums[i]);
//            j -= nums[i];
//        }
//        else {
//            partition2.push_back(nums[i]);
//        }
//        i--;
//    }
//
//    sort(partition1.begin(), partition1.end());
//    sort(partition2.begin(), partition2.end());
//
//    cout << numPartitions << "\n";
//    cout << "{";
//    for (int i = 0; i < partition1.size(); i++) {
//        cout << partition1[i];
//        if (i != partition1.size() - 1) {
//            cout << ",";
//        }
//    }
//    cout << "}, {";
//    for (int i = 0; i < partition2.size(); i++) {
//        cout << partition2[i];
//        if (i != partition2.size() - 1) {
//            cout << ",";
//        }
//    }
//    cout << "}\n";
//
//    return numPartitions;
//}
//
//int main() {
//    while (cin >> n) {
//        if (n == 0) {
//            break;
//        }
//
//        for (int i = 0; i < n; i++) {
//            cin >> nums[i];
//        }
//
//        ll numPartitions = countPartitions();
//        if (numPartitions == 0) {
//            cout << "0, {";
//            int sum = 0;
//            for (int i = 0; i < n; i++) {
//                sum += nums[i];
//            }
//            int target = sum / 2;
//            vector<int> partition;
//            for (int i = n - 1; i >= 0; i--) {
//                if (nums[i] <= target) {
//                    partition.push_back(nums[i]);
//                    target -= nums[i];
//                }
//            }
//            sort(partition.begin(), partition.end());
//            for (int i = 0; i < partition.size(); i++) {
//                cout << partition[i];
//                if (i != partition.size() - 1) {
//                    cout << ",";
//                }
//            }
//            cout << "}\n";
//        }
//    }
//    return 0;
//}










////Dynamic Programming Solution
////SubSet Sum Problem
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isSubsetSum(vector<int>& nums, int sum) {
//	int n = nums.size();
//	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
//
//	for (int i = 0; i <= n; i++) {
//		dp[i][0] = true;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= sum; j++) {
//			if (j < nums[i - 1]) {
//				dp[i][j] = dp[i - 1][j];
//			}
//			else {
//				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
//			}
//		}
//	}
//
//	//return dp[n][sum];
//	if (!dp[n][sum]) {
//		cout << "No subset with given sum";
//		return false;
//	}
//
//	cout << "Found a subset with given sum: ";
//	vector<int> subset;
//	int i = n, j = sum;
//	while (i > 0 && j > 0) {
//		if (dp[i - 1][j]) {
//			i--;
//		}
//		else {
//			subset.push_back(nums[i - 1]);
//			j -= nums[i - 1];
//			i--;
//		}
//	}
//	for (int i = subset.size() - 1; i >= 0; i--) {
//		cout << subset[i] << " ";
//	}
//	cout << endl;
//
//	return true;
//}
//
//int main() {
//	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
//	int sum = 14;
//
//	/*int num, set, sum = 0;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> set;
//		nums[i] = set;
//		sum += set;
//	}*/
//
//	isSubsetSum(nums, sum);
//
//	/*if (isSubsetSum(nums, num)) {
//		cout << "Found a subset with given sum";
//	}
//	else {
//		cout << "No subset with given sum";
//	}*/
//
//	return 0;
//}






//
//
//
//#include<iostream>
//
//using namespace std;
//
//bool isSubsetSum(int set[], int n, int sum) {
//	bool subset[n + 1][sum + 1];
//
//	for (int i = 0; i <= n; i++)
//		subset[i][0] = true;
//
//	for (int i = 1; i <= sum; i++)
//		subset[0][i] = false;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= sum; j++) {
//			if (j < set[i - 1])
//				subset[i][j] = subset[i - 1][j];
//			if (j >= set[i - 1])
//				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
//		}
//	}
//
//	return subset[n][sum];
//}
//
//int main() {
//	int set[] = { 3, 34, 4, 12, 5, 2 };
//	int sum = 9;
//	int n = sizeof(set) / sizeof(set[0]);
//	if (isSubsetSum(set, n, sum) == true)
//		cout << "Found a subset with given sum";
//	else
//		cout << "No subset with given sum";
//
//	return 0;
//}
//
//
//
//





///*
//#define MAX 500
//int MEMO[MAX][MAX];
//int SUBSET[MAX][MAX];
//
//
//int check_subset_sum(int m, int n);
//
//int main() {
//
//
//	return 0;
//}
//
//int check_subset_sum(int m, int n) {
//	for (int i = 0; i <= n; i++) {
//		MEMO[i][0] = 1;
//	}
//	for (int i = 1; i <= m; i++) {
//		MEMO[0][i] = 0;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			MEMO[i][j] = 0;
//
//			if (j >= SUBSET[i - 1]) {
//				if (MEMO[i - 1][j - SUBSET[i - 1]] == 1)
//					MEMO[i][j] = 1;
//			}
//		}
//	}
//	
//}*/


//minimum partition 코드

//pair<vector<int>, vector<int>> partition2(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (int num : nums) {
//        sum += num;
//    }
//
//    // dp[i][j] = whether it is possible to get sum j with elements from 0 to i
//    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
//
//    // base case
//    dp[0][nums[0] + sum] = true;
//    dp[0][-nums[0] + sum] = true;
//
//    // dp
//    for (int i = 1; i < n; i++) {
//        for (int j = -sum; j <= sum; j++) {
//            if (dp[i - 1][j + sum]) {
//                dp[i][j + nums[i] + sum] = true;
//                dp[i][j - nums[i] + sum] = true;
//            }
//        }
//    }
//
//    // find the closest partition
//    int closest_sum = 0;
//    for (int j = 0; j <= sum; j++) {
//        if (dp[n - 1][j]) {
//            closest_sum = j;
//            break;
//        }
//    }
//
//    // construct the partitions
//    vector<int> partition1, partition2;
//    int i = n - 1;
//    int j = closest_sum;
//    while (i >= 0) {
//        if (j - nums[i] >= -sum && dp[i - 1][j - nums[i] + sum]) {
//            partition1.push_back(nums[i]);
//            j -= nums[i];
//        }
//        else {
//            partition2.push_back(nums[i]);
//        }
//        i--;
//    }
//
//    return make_pair(partition1, partition2);
//}






//pair<vector<int>, vector<int>> minAbsDifference(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += nums[i];
//    }
//
//    int target = sum / 2;
//    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= target; j++) {
//            if (nums[i - 1] <= j) {
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    int diff = abs(sum - 2 * dp[n][target]);
//    vector<int> set1, set2;
//    int i = n, j = target;
//    while (i > 0 && j >= 0) {
//        if (dp[i][j] == dp[i - 1][j]) {
//            set2.push_back(nums[i - 1]);
//        }
//        else {
//            set1.push_back(nums[i - 1]);
//            j -= nums[i - 1];
//        }
//        i--;
//    }
//    while (i > 0) {
//        set2.push_back(nums[i - 1]);
//        i--;
//    }
//
//    cout << "Set 1: ";
//    for (int i = 0; i < set1.size(); i++) {
//        cout << set1[i] << " ";
//    }
//    cout << endl;
//    cout << "Set 2: ";
//    for (int i = 0; i < set2.size(); i++) {
//        cout << set2[i] << " ";
//    }
//    cout << endl;
//
//    return make_pair(set1, set2);
//}







//vector<int> findPartition(vector<int>& nums) {
//    int n = nums.size();
//    int min_value = *min_element(nums.begin(), nums.end()); // 최소값 찾기
//
//    // 모든 값에서 최소값 빼기
//    for (int i = 0; i < n; i++) {
//        nums[i] -= min_value;
//    }
//
//    int target = accumulate(nums.begin(), nums.end(), 0) / 2; // 목표 합 구하기
//    vector<bool> dp(target + 1, false);
//    vector<int> result;
//
//    dp[0] = true;
//    for (int num : nums) {
//        for (int j = target; j >= num; j--) {
//            dp[j] = dp[j] || dp[j - num];
//        }
//    }
//
//    int i = target;
//    while (!dp[i]) {
//        i--;
//    }
//
//    int sum1 = i, sum2 = accumulate(nums.begin(), nums.end(), 0) - sum1;
//    int diff = abs(sum1 - sum2);
//
//    // 결과 벡터 구하기
//    for (int num : nums) {
//        if (sum1 >= num) {
//            result.push_back(num + min_value);
//            sum1 -= num;
//        }
//        else {
//            sum2 -= num;
//        }
//    }
//    cout << "Partition 1: ";
//    for (int x : result) {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    cout << "Partition 2: ";
//    for (int x : nums) {
//        if (find(result.begin(), result.end(), x) == result.end()) {
//            cout << x << " ";
//        }
//    }
//    cout << endl;
//
//    return result;
//}






//void minimumAbsDifference(vector<int>& nums) {
//    int n = nums.size();
//    int sum = 0;
//    int sum_neg = 0, sum_pos = 0, count = 0;
//    for (auto val : nums)
//    {
//        if (val < 0)
//            sum_neg += val;
//        else
//            sum_pos += val;
//    }
//    sum = sum_pos + sum_neg;
//
//    // dp[i][j] = true if there is a subset of elements that has a sum of j among the first i elements of the nums array
//    //vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
//    unordered_map<int, bool>* dp = new unordered_map<int, bool>[n];
//    dp[0][nums[0]] = true;
//
//    // compute the dp table
//    for (int i = 1; i < n; i++) {
//        for (int j = sum_neg; j <= sum_pos; j++) {
//            dp[i][j] = dp[i - 1][j];  // case 1: do not include the i-th element in the subset
//            if (j - nums[i - 1] >= sum_neg) {
//                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];  // case 2: include the i-th element in the subset
//            }
//        }
//    }
//
//    // find the largest index j such that dp[n][j] = true
//    int j = sum / 2;
//    while (!dp[n - 1][j]) {
//        j--;
//    }
//
//    // construct the two subsets
//    vector<int> set1, set2;
//    int i = n;
//    while (i > 0 && j > 0) {
//        if (dp[i - 1][j]) {  // case 1: the i-th element is not in the subset
//            i--;
//        }
//        else {  // case 2: the i-th element is in the subset
//            set1.push_back(nums[i - 1]);
//            j -= nums[i - 1];
//            i--;
//        }
//    }
//    while (i > 0) {
//        set1.push_back(nums[i - 1]);
//        i--;
//    }
//
//    // compute the second subset
//    for (int k = 0; k < n; k++) {
//        if (find(set1.begin(), set1.end(), nums[k]) == set1.end()) {
//            set2.push_back(nums[k]);
//        }
//    }
//
//    cout << "[ ";
//    for (auto num : set1) {
//        cout << num << " ";
//    }
//    cout << "] and [ ";
//    for (auto num : set2) {
//        cout << num << " ";
//    }
//    cout << "]" << endl;
//
//    return;
//}






//void findMinDiff(vector<int>& nums) {
//    int n = nums.size();
//
//    int sum_neg = 0, sum_pos = 0, count = 0;
//    for (auto val : nums)
//    {
//        if (val < 0)
//            sum_neg += val;
//        else
//            sum_pos += val;
//    }
//
//    // Total sum of the array.
//    // 모든 항목의 합
//    int sum = sum_pos + sum_neg;
//    //int sum = accumulate(nums.begin(), nums.end(), 0);
//
//    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
//
//    for (int i = 0; i <= n; i++) {
//        dp[i][0] = true;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = sum_neg; j <= sum_pos; j++) {
//            dp[i][j] = dp[i - 1][j];
//            if (nums[i - 1] <= j) {
//                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//            }
//        }
//    }
//
//    int diff = sum;
//    int first_set_sum = 0;
//    for (int j = sum / 2; j >= 0; j--) {
//        if (dp[n][j]) {
//            first_set_sum = j;
//            break;
//        }
//    }
//
//    int second_set_sum = sum - first_set_sum;
//    diff = abs(first_set_sum - second_set_sum);
//
//    vector<int> first_set;
//    vector<int> second_set;
//    int i = n;
//    int j = second_set_sum;
//    while (i > 0 && j > 0) {
//        if (dp[i - 1][j]) {
//            i--;
//        }
//        else {
//            first_set.push_back(nums[i - 1]);
//            j -= nums[i - 1];
//            i--;
//        }
//    }
//
//    for (int k = n - 1; k >= 0; k--) {
//        if (find(first_set.begin(), first_set.end(), nums[k]) == first_set.end()) {
//            second_set.push_back(nums[k]);
//        }
//    }
//
//    cout << "First Set: ";
//    for (int x : first_set) {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    cout << "Second Set: ";
//    for (int x : second_set) {
//        cout << x << " ";
//    }
//    cout << endl;
//}





//int partition(vector<int>& nums) {
//    int n = nums.size() / 2;
//
//    // Calculate the sum of all elements in nums
//    int sum = accumulate(nums.begin(), nums.end(), 0);
//
//    // dp[i][j] stores whether it is possible to obtain a sum of j using the first i elements of nums
//    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
//
//    // Base case: it is always possible to obtain a sum of 0 using 0 elements
//    dp[0][0] = true;
//
//    // Fill in the remaining entries of the dp table
//    for (int i = 1; i <= 2 * n; i++) {
//        for (int j = min(i, n); j >= 1; j--) {
//            for (int k = sum / 2; k >= nums[i - 1]; k--) {
//                dp[j][k] = dp[j][k] || dp[j - 1][k - nums[i - 1]];
//            }
//        }
//    }
//
//    // Find the largest j such that dp[j][sum/2] is true
//    int j;
//    for (j = n; j >= 0; j--) {
//        if (dp[j][sum / 2]) {
//            break;
//        }
//    }
//
//    // Construct the two sets that give the minimum possible absolute difference
//    vector<int> set1, set2;
//    int currSum = sum / 2;
//    for (int i = 2 * n; i >= 1; i--) {
//        if (j > 0 && currSum - nums[i - 1] >= 0 && dp[j - 1][currSum - nums[i - 1]]) {
//            set1.push_back(nums[i - 1]);
//            j--;
//            currSum -= nums[i - 1];
//        }
//        else {
//            set2.push_back(nums[i - 1]);
//            currSum -= nums[i - 1];
//        }
//    }
//
//    // Print the two sets
//    cout << "Set 1: ";
//    for (int i = 0; i < n; i++) {
//        cout << set1[i] << " ";
//    }
//    cout << "\nSet 2: ";
//    for (int i = 0; i < n; i++) {
//        cout << set2[i] << " ";
//    }
//    cout << "\n";
//    return 0;
//}






//부분집합으로 나누지 못할 때 최소값 출력하는 함수
//vector<vector<int>> partitionArray(vector<int>& nums) {
//    int n = nums.size() / 2;
//    vector<int> bitmask(n, 1);
//    bitmask.resize(nums.size(), 0);
//
//    int min_diff = INT_MAX;
//    vector<int> ans1, ans2;
//
//    do {
//        vector<int> set1, set2;
//        for (int i = 0; i < nums.size(); i++) {
//            if (bitmask[i] == 1) {
//                set1.push_back(nums[i]);
//            }
//            else {
//                set2.push_back(nums[i]);
//            }
//        }
//        int sum1 = accumulate(set1.begin(), set1.end(), 0);
//        int sum2 = accumulate(set2.begin(), set2.end(), 0);
//        int diff = abs(sum1 - sum2);
//        if (diff < min_diff) {
//            min_diff = diff;
//            ans1 = set1;
//            ans2 = set2;
//        }
//    } while (prev_permutation(bitmask.begin(), bitmask.end()));
//
//    sort(ans1.begin(), ans1.end());
//    sort(ans2.begin(), ans2.end());
//
//    if (ans1[0] < ans2[0]) {
//        cout << 0 << "\n" << "{ ";
//        for (int i = 0; i < ans1.size(); i++) {
//            cout << ans1[i];
//            if (i != ans1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < ans2.size(); i++) {
//            cout << ans2[i];
//            if (i != ans2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//    }
//    else {
//        cout << 0 << "\n" << "{ ";
//        for (int i = 0; i < ans2.size(); i++) {
//            cout << ans2[i];
//            if (i != ans2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < ans1.size(); i++) {
//            cout << ans1[i];
//            if (i != ans1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//    }
//
//    vector<vector<int>> ans;
//    ans.push_back(ans1);
//    ans.push_back(ans2);
//    return ans;
//}







/*
// Returns the minimum value of the difference of the two
// sets.
int findMin(vector<int>& nums)
{
    int n = nums.size();
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    // Create an array to store results of subproblems
    //bool dp[n + 1][sum + 1];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    cout << diff << "\n";
    return diff;
}*/