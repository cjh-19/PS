//test2 ����

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <cmath>

using namespace std;

const long long NUMEROUS = ULONG_MAX;

int minimumDifference2(vector<int>& nums) {
    int totalSum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    int totLengthOfSubarray = (n / 2) - 1 - 0 + 1;
    vector<vector<int>> res1(totLengthOfSubarray + 1); //����+1�� res 2���� ���ͻ���
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[j];
                countOfChosenNos++;
            }
        }
        res1[countOfChosenNos].push_back(sum);
    }
    auto left = res1;

    totLengthOfSubarray = (n - 1) - (n / 2) + 1;
    vector<vector<int>> res2(totLengthOfSubarray + 1); //����+1�� res 2���� ���ͻ���
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[n / 2 + j];
                countOfChosenNos++;
            }
        }
        res2[countOfChosenNos].push_back(sum);
    }
    auto right = res2;



    //iterator ���, �ξ� ������
    int target = totalSum / 2, ans = INT_MAX;

    vector<int> L, R;

    //we can take (0 to n/2) length numbers from left
    for (int i = 0; i <= n / 2; i++) {
        //now we take rest - (n/2-i) length from right, we sort it to binary search
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));
        //curleftSum : left �κ����տ��� ������ ��� ��
        for (int curleftSum : left[i]) {
            int needSumFromRight = target - curleftSum;
            auto it = lower_bound(begin(r), end(r), needSumFromRight); //needSumFromRight�� ã�� ���� �̺�Ž���� �Ѵ�
            if (it != end(r)) {
                int curAns = abs(totalSum - 2 * (curleftSum + *it));
                
                if (curAns < ans) {
                    ans = curAns;
                    L.clear();
                    R.clear();
                    L = vector<int>(begin(nums), begin(nums) + (n / 2 - i));
                    R = vector<int>(begin(nums) + (n / 2 - i), end(nums));
                }
            }
        }
    }





    if (L[0] < R[0]) {
        cout << "{ ";
        for (int i = 0; i < L.size(); i++) {
            cout << L[i];
            if (i != L.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < R.size(); i++) {
            cout << R[i];
            if (i != R.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
    }
    else {
        cout << "{ ";
        for (int i = 0; i < R.size(); i++) {
            cout << R[i];
            if (i != R.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < L.size(); i++) {
            cout << L[i];
            if (i != L.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
    }


    cout << "Minimum possible absolute difference: " << ans << "\n";
    return ans;
}

vector<vector<int>> minimizeDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int targetSum = abs((totalSum + 1) / 2);

    vector<vector<int>> dp(n + 1, vector<int>(abs(totalSum) + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= abs(totalSum); j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] |= dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    int minDiff = INT_MAX, sum1 = 0;
    for (int j = targetSum; j <= abs(totalSum); j++) {
        if (dp[n][j]) {
            int diff = abs(totalSum - 2 * j);
            if (diff < minDiff) {
                minDiff = diff;
                sum1 = j;
            }
        }
    }
    vector<int> s1, s2;
    vector<vector<int>> result(2);
    int i = n;
    while (i > 0 && sum1 > 0) {
        if (sum1 >= nums[i - 1] && dp[i - 1][sum1 - nums[i - 1]]) {
            s1.push_back(nums[i - 1]);
            sum1 -= nums[i - 1];
        }
        else {
            s2.push_back(nums[i - 1]);
        }
        i--;
    }
    while (i > 0) {
        s2.push_back(nums[i - 1]);
        i--;
    }
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
    return result;
}

void minAbsoluteDiff(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int target = abs(totalSum);

    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            if (j >= abs(nums[i - 1])) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - abs(nums[i - 1])];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int halfSum = target / 2;
    while (!dp[n][halfSum] && halfSum >= 0) --halfSum;
    int set1Sum = halfSum;
    int set2Sum = totalSum - set1Sum;

    vector<int> s1, s2;
    for (int i = n; i >= 1; --i) {
        if (set1Sum >= abs(nums[i - 1]) && dp[i - 1][set1Sum - abs(nums[i - 1])]) {
            set1Sum -= abs(nums[i - 1]);
            s1.push_back(nums[i - 1]);
        }
        else {
            s2.push_back(nums[i - 1]);
        }
    }
    // ���� ��ü ���� �������ٸ�, set1�� set2�� �ٲ��ش�.
    if (totalSum < 0) swap(s1, s2);
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
    return ;
}

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

    //�ε����� ���� 0�ΰ��� s1, 1�� ���� s2�� �߰�
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


//�κ��������� ������ ���� �� �ּҰ� ����ϴ� �Լ� // ����
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
    unordered_map<int, bool>* dp = new unordered_map<int, bool>[n];

    // Initialize top row as true
    /*for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize leftmost column, except part[0][0], as false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;*/

    dp[0][nums[0]] = true;

    // Fill the partition table in bottom up manner 
    for (int i = 1; i < n; i++)
    {
        //dp[i][0] = true;
        for (int j = sum_neg; j <= sum_pos; j++)
        {
            dp[i][j] = dp[i - 1][j];
            /*if (j == nums[i - 1]) {
                dp[i][j] = true;
                //cout << dp[i][j] << " ";
            }*/
            if (j - nums[i] >= sum_neg) {
                dp[i][j] |= dp[i - 1][j - nums[i]];
                //cout << dp[i][j] << " ";
            }
        }
        //cout << "\n";
    }
    /*
    // ������ ��� ���� ����
    int leftSum = 0;
    for (int j = sum_pos; j >= sum_neg; j--) {
        if (dp[n][j]) { // j�� ������ ���
            leftSum = j; // leftSum�� �����ϰ� ����
            break;
        }
    }

    // �� ���� �迭 ����
    vector<int> leftSubset;
    vector<int> rightSubset;
    int curleftSum = leftSum;
    for (int i = n; i >= 1; i--) {
        if (curleftSum >= nums[i - 1]+sum_neg && dp[i - 1][curleftSum - nums[i - 1]]) { // i��° ���� ����ϴ� ���
            leftSubset.push_back(nums[i - 1]);
            curleftSum -= nums[i - 1];
        }
        else { // i��° ���� ������� �ʴ� ���
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


    int diff = 0;
    for (int i = sum / 2; i >= sum_neg; i--) {
        if (dp[n][i]) {
            diff = sum - 2 * i;
            break;
        }
    }

    vector<int> s1, s2;
    int sum1 = 0, sum2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i][diff + sum / 2]) {
            s1.push_back(nums[i]);
            sum1 += nums[i];
            diff -= nums[i];
        }
        else {
            s2.push_back(nums[i]);
            sum2 += nums[i];
        }
    }
    if (sum1 > sum2) {
        //swap(s1, 2);
    }

    // ������ �ε��� üũ
    //vector<bool> result_subset(nums.size(), 0);
    //int required = sum / 2;
    //int idx = n - 1;
    //int diff = INT_MAX;
    //int cnt = 0;
    //int check =0;
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
    //        //break;
    //    }
    //    check++;
    //}
    


    //int tmp = 0;
    //for (int j = required; j >= sum_neg; j--)
    //{
    //    idx = n - 1;
    //    tmp = j;
    //    if (dp[idx][tmp] == true) {
    //        diff = sum - 2 * (tmp+check);
    //        while (idx >= 0)
    //        {
    //            if (idx != 0)
    //            {
    //                // Reverse dp transition.
    //                if (dp[idx][tmp] && !dp[idx - 1][tmp])
    //                {
    //                    //diff = sum - 2 * tmp;
    //                    result_subset[idx] = 1;
    //                    cnt++;
    //                    tmp -= nums[idx];
    //                    if (tmp == 0)
    //                        break;
    //                }
    //            }
    //            else {
    //                result_subset[idx] = 1;
    //                cnt++;
    //            }
    //            idx--;
    //        }
    //        if (tmp == 0)
    //            break;
    //    }
    //    check++;
    //}

    //cout << diff << " \n";
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

    //�ε����� ���� 0�ΰ��� s1, 1�� ���� s2�� �߰�
    //vector<int> s1, s2;
    //for (int i = 0; i < n; i++) {
    //    //cout << result_subset[i] << " ";
    //    if (result_subset[i] == 0)
    //        s1.push_back(nums[i]);
    //    else
    //        s2.push_back(nums[i]);

    //}
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
    //������ �հ� ����� ���� ���� ������. ��� ���� ��츦 ���ϱ� ���ؼ�. dp[i][val] ���� val�� �������� ������ �̷��� ���Ѵ�.
    int sum_neg = 0, sum_pos = 0, count = 0;
    for (auto val : nums)
    {
        if (val < 0)
            sum_neg += val;
        else
            sum_pos += val;
    }

    // Total sum of the array.
    // ��� �׸��� ��
    int sum = sum_pos + sum_neg;

    int n = nums.size();

    // dp state
    unordered_map<int, int>* dp = new unordered_map<int, int>[n];
    // dp2�� subset ���� �޶� �κ��������� ���������� �ʴ� ���
    unordered_map<int, bool>* dp2 = new unordered_map<int, bool>[n];


    // Base state:
    // for idx 0 only one sum nums[0] is possible
    dp[0][nums[0]] = 0; //dp[i][j] : i��° �ε������� ����� �迭�� �κ����� �߿��� ���� j�� ���� �����Ѵٸ� +1 �̴�.
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
                dp[i][val] += 1; // ���� val�� ���� �����Ѵٸ� +1 �Ѵ�
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
    //count : ��� �κ������� ����� ��
    count = dp[idx][required];

    if (count > NUMEROUS) {
        cout << "NUMEROUS\n";
        return  vector<bool>();
    }

    // Parition not possible. //subset ���� ���� ���� ���
    if (!dp2[idx][required] || sum & 1)
    {

        //findMin(nums);//�ֿ�
        //findMin2(nums); //�ֿ�
        //minAbsoluteDiff(nums);
        //minimizeDifference(nums);
        minimumDifference2(nums);
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

    //�Է��� ������ 2�� �϶��� ������ ����
    //ex) 1 -1 > {-1, 1} {0}
    //ex) -1 1 -2 2 �� ��� {-1,1 -2, 2} { } �� ī��Ʈ ���� �ʴ´ٴ� ������ ����

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
    //�̷��� ���� �ذ�?
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