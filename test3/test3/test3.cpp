//test2 ����

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

    // ������ �ε��� üũ
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
        findMin2(nums); //�ֿ�
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