//test2 연습

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

const long long NUMEROUS = ULONG_MAX;

int findMin2(vector<int>& nums)
{
    int m = 125250;
    int n = nums.size();

    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    // Create an array to store results of subproblems
    //bool dp[n + 1][sum + 1];
    //bool** dp = new bool* [n + 1];
    //for (int i = 0; i <= n; i++)
    //    dp[i] = new bool[sum + 1];
    vector<vector<bool>> dp(m+1, vector<bool>(m+1,false));

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    /*for (int i = 1; i <= sum; i++)
        dp[0][i] = false;*/

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

    int required = sum / 2;
    int idx = n - 1;

    // Tracks partition elements.
    vector<bool> result_subset(nums.size(), 0);
    // Tracks count of elements included in S1.
    int cnt = 0;
    int diff = INT_MAX;
    for (int j = required; j >= 0; j--)
    {
        idx = n - 1;
        if (dp[idx][j] == true)
        {
            diff = sum - 2 * j;
            while (idx >= 0)
            {
                if (idx != 0)
                {
                    // Reverse dp transition.
                    if (dp[idx][j] && !dp[idx - 1][j])
                    {
                        result_subset[idx] = 1;
                        cnt++;
                        j -= nums[idx];
                        if (j == 0)
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
        }
    }

    //인덱스의 값이 0인것을 s1, 1인 것을 s2에 추가
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
    }

    // Initialize difference of two sums.
    //int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    //for (int j = sum / 2; j >= 0; j--) {
    //    // Find the
    //    if (dp[n][j] == true) {
    //        diff = sum - 2 * j;
    //        break;
    //    }
    //}
    cout << diff << "\n";

    //for (int i = 0; i <= n; i++)
    //    delete[] dp[i];
    //delete[] dp;
    return diff;
}


//부분집합으로 나누지 못할 때 최소값 출력하는 함수 // 오류
int findMin(vector<int>& nums) {
    int sum = 0, sum_neg = 0, sum_pos = 0;
    int n = nums.size();

    for (int num : nums)
    {
        if (num < 0)
            sum_neg += num;
        else
            sum_pos += num;
    }
    // Calculcate sum of all elements
    //for (int i = 0; i < n; i++)
    //    sum += nums[i];
    sum = sum_pos + sum_neg;

    // Allocate a 2D array for calculating DP
    //bool** part = new bool* [sum / 2 + 1];
    //vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    unordered_map<int, bool>* dp = new unordered_map<int, bool>[n + 1];

    // Initialize top row as true
    /*for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize leftmost column, except part[0][0], as false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;*/

    dp[0][nums[0]] = true;

    // Fill the partition table in bottom up manner 
    for (int i = 1; i <= n; i++)
    {
        //dp[i][0] = true;
        for (int j = sum_neg; j <= sum_pos; j++)
        {
            dp[i][j] = dp[i - 1][j];
            /*if (j == nums[i - 1]) {
                dp[i][j] = true;
                //cout << dp[i][j] << " ";
            }*/
            if (j - nums[i - 1] >= sum_neg) {
                dp[i][j] |= dp[i - 1][j - nums[i - 1]];
                //cout << dp[i][j] << " ";
            }
        }
        //cout << "\n";
    }
    /*
    // 가능한 모든 분할 생성
    int leftSum = 0;
    for (int j = sum_pos; j >= sum_neg; j--) {
        if (dp[n][j]) { // j가 가능한 경우
            leftSum = j; // leftSum을 설정하고 종료
            break;
        }
    }

    // 두 개의 배열 생성
    vector<int> leftSubset;
    vector<int> rightSubset;
    int curleftSum = leftSum;
    for (int i = n; i >= 1; i--) {
        if (curleftSum >= nums[i - 1]+sum_neg && dp[i - 1][curleftSum - nums[i - 1]]) { // i번째 수를 사용하는 경우
            leftSubset.push_back(nums[i - 1]);
            curleftSum -= nums[i - 1];
        }
        else { // i번째 수를 사용하지 않는 경우
            rightSubset.push_back(nums[i - 1]);
        }
    }

    cout << "{ ";
    for (int i = 0; i < leftSubset.size(); i++) {
        cout << leftSubset[i];
        if (i != leftSubset.size() - 1) {
            cout << ", ";
        }
    }
    cout << " } { ";
    for (int i = 0; i < rightSubset.size(); i++) {
        cout << rightSubset[i];
        if (i != rightSubset.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }\n";

    return 0;
    */

    // 집합의 인덱스 체크
    vector<bool> result_subset(nums.size(), 0);
    int required = sum / 2;
    int idx = n - 1;
    int diff = INT_MAX;
    int cnt = 0;
    //for (int j = required; j >= sum_neg; j--)
    //{
    //    if (dp[idx][j] == true)
    //    {
    //        diff = sum - 2 * j;
    //        while (idx >= 0)
    //        {
    //            if (idx != 0)
    //            {
    //                // Reverse dp transition.
    //                if (dp[idx][j] && !dp[idx - 1][j])
    //                {
    //                    result_subset[idx] = 1;
    //                    cnt++;
    //                    j -= nums[idx];
    //                    if (j == 0)
    //                        break;
    //                }
    //            }
    //            else
    //            {
    //                //result_subset[idx] = 1;
    //                cnt++;
    //            }
    //            idx--;
    //        }
    //        break;
    //    }
    //}

    for (int j = required; j >= sum_neg; j--)
    {
        idx = n - 1;
        //if (dp[idx][j] == true) {
            //diff = sum - 2 * j;
        while (idx >= 0)
        {
            if (idx != 0)
            {
                // Reverse dp transition.
                if (dp[idx][j] && !dp[idx - 1][j])
                {
                    diff = sum - 2 * j;
                    result_subset[idx] = 1;
                    cnt++;
                    j -= nums[idx];
                    if (j == 0)
                        break;
                }
                else
                    cnt++;
            }
            else
                cnt++;
            idx--;
        }
        if (cnt == n)
            break;
        //}
    }

    cout << diff << " \n";
    //return 0;

    // Tracks partition elements.
    //vector<bool> result_subset(nums.size(), 0);
    // Tracks count of elements included in S1.
    //int cnt = 0;
    /*
    while (idx >= 0)
    {
        if (idx != 0)
        {
            // Reverse dp transition.
            if (dp[idx][required] && !dp[idx - 1][required])
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
    }*/

    //인덱스의 값이 0인것을 s1, 1인 것을 s2에 추가
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
    }

    /*
    int diff = INT_MAX;

    // Find the largest j such that part[n][j] is true
    // where j loops from sum/2 to 0
    for (int j = sum/2; j >= sum_neg; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    cout << diff << " \n";
    return diff;*/
    return 0;
}

vector<bool> subset_sum_partition(vector<int>& nums)
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

    int n = nums.size();

    // dp state
    unordered_map<int, int>* dp = new unordered_map<int, int>[n];
    // dp2는 subset 합이 달라 부분집합으로 나뉘어지지 않는 경우
    unordered_map<int, bool>* dp2 = new unordered_map<int, bool>[n];


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
                //cout << "[" << i << ' ' << val << "]" << dp[i][val] << " ";
            }
            else if (val - nums[i] >= sum_neg)
            {
                // 3) state(i, val) = state(i - 1, val - s[i]) when taking current element.
                dp[i][val] = dp[i - 1][val] + dp[i - 1][val - nums[i]];
                dp2[i][val] |= dp2[i - 1][val - nums[i]];
                //cout << "[" << i << ' ' << val << "]" << dp[i][val] << " ";
            }
        }
        //cout << "\n";
    }


    int required = sum / 2;
    int idx = n - 1;
    //count : 모든 부분집합의 경우의 수
    count = dp[idx][required];

    if (count > NUMEROUS) {
        cout << "NUMEROUS\n";
        return  vector<bool>();
    }

    // Parition not possible. //subset 합이 같지 않은 경우
    if (!dp2[idx][required] || sum & 1)
    {

        //findMin(nums);//주요
        findMin2(nums); //주요
        return vector<bool>();
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
            if (dp2[idx][required] and !dp2[idx - 1][required])
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

    //입력의 개수가 2개 일때는 문제가 없음
    //ex) 1 -1 > {-1, 1} {0}
    //ex) -1 1 -2 2 일 경우 {-1,1 -2, 2} { } 가 카운트 되지 않는다는 문제가 있음

    if (cnt == n)
    {
        result_subset.clear();
        cout << count << "\n" << "{ ";
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            if (i != n - 1) {
                cout << ", ";
            }
        }
        cout << " } { }\n";
        return result_subset;
    }
    //이렇게 문제 해결?
    if (sum == 0)
        count++;


    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        //cout << result_subset[i] << " ";
        if (result_subset[i] == 0)
            s1.push_back(nums[i]);
        else
            s2.push_back(nums[i]);

    }
    if (s1[0] < s2[0]) {
        cout << count << "\n";
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
    }
    else {
        cout << count << "\n";
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
        subset_sum_partition(nums);
    }
    return 0;
}