//unordered_map�� �̿��Ͽ� �����ε����� ó���� ���
//���� �ֽ��� ���� ����

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

const long long NUMEROUS = ULONG_MAX;

//�κ��������� ������ ���� �� �ּҰ� ����ϴ� �Լ�
vector<vector<int>> partitionArray(vector<int>& nums) {
    int n = nums.size() / 2;
    vector<int> bitmask(n, 1);
    bitmask.resize(nums.size(), 0);

    int min_diff = INT_MAX;
    vector<int> ans1, ans2;

    do {
        vector<int> set1, set2;
        for (int i = 0; i < nums.size(); i++) {
            if (bitmask[i] == 1) {
                set1.push_back(nums[i]);
            }
            else {
                set2.push_back(nums[i]);
            }
        }
        int sum1 = accumulate(set1.begin(), set1.end(), 0);
        int sum2 = accumulate(set2.begin(), set2.end(), 0);
        int diff = abs(sum1 - sum2);
        if (diff < min_diff) {
            min_diff = diff;
            ans1 = set1;
            ans2 = set2;
        }
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());

    if (ans1[0] < ans2[0]) {
        cout << 0 << "\n" << "{ ";
        for (int i = 0; i < ans1.size(); i++) {
            cout << ans1[i];
            if (i != ans1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < ans2.size(); i++) {
            cout << ans2[i];
            if (i != ans2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
    }
    else {
        cout << 0 << "\n" << "{ ";
        for (int i = 0; i < ans2.size(); i++) {
            cout << ans2[i];
            if (i != ans2.size() - 1) {
                cout << ", ";
            }
        }
        cout << " } { ";
        for (int i = 0; i < ans1.size(); i++) {
            cout << ans1[i];
            if (i != ans1.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }\n";
    }

    vector<vector<int>> ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
}


//�κ��������� ������ ���� �� �ּҰ� ����ϴ� �Լ� // ����
//int findMin(vector<int>& nums) {
//    int sum = 0, sum_neg = 0, sum_pos = 0;
//    int n = nums.size();
//
//    for (int num : nums)
//    {
//        if (num < 0)
//            sum_neg += num;
//        else
//            sum_pos += num;
//    }
//    // Calculcate sum of all elements
//    //for (int i = 0; i < n; i++)
//    //    sum += nums[i];
//    sum = sum_pos + sum_neg;
//
//    // Allocate a 2D array for calculating DP
//    //bool** part = new bool* [sum / 2 + 1];
//    //vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
//    unordered_map<int, bool>* dp = new unordered_map<int, bool>[n];
//    
//    // Initialize top row as true
//    /*for (int i = 0; i <= n; i++)
//        dp[i][0] = true;
//
//    // Initialize leftmost column, except part[0][0], as false
//    for (int i = 1; i <= sum; i++)
//        dp[0][i] = false;*/
//    dp[0][nums[0]] = true;
//
//    // Fill the partition table in bottom up manner 
//    for (int i = 1; i < n; i++)
//    {
//        dp[i][0] = true;
//        for (int j = sum_neg; j <= sum_pos; j++)
//        {
//            dp[i][j] = dp[i-1][j];
//            /*if (j == nums[i - 1]) {
//                dp[i][j] = true;
//                cout << dp[i][j] << " ";
//            }*/
//            if (j - nums[i - 1] >= sum_neg) {
//                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//                cout << dp[i][j] << " ";
//            }
//        }
//        cout << "\n";
//    }
//    
//    // ������ �ε��� üũ
//    int required = sum / 2;
//    int idx = n - 1;
//    // Tracks partition elements.
//    vector<bool> result_subset(nums.size(), 0);
//    // Tracks count of elements included in S1.
//    int cnt = 0;
//    
//    while (idx >= 0)
//    {
//        if (idx != 0)
//        {
//            // Reverse dp transition.
//            if (dp[idx][required] && !dp[idx - 1][required])
//            {
//                result_subset[idx] = 1;
//                cnt++;
//                required -= nums[idx];
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
//    if (cnt == n)
//    {
//        result_subset.clear();
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
//    //�ε����� ���� 0�ΰ��� s1, 1�� ���� s2�� �߰�
//    vector<int> s1, s2;
//    for (int i = 0; i < n; i++) {
//        //cout << result_subset[i] << " ";
//        if (result_subset[i] == 0)
//            s1.push_back(nums[i]);
//        else
//            s2.push_back(nums[i]);
//
//    }
//    if (s1[0] < s2[0]) {
//        cout << "{ ";
//        for (int i = 0; i < s1.size(); i++) {
//            cout << s1[i];
//            if (i != s1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < s2.size(); i++) {
//            cout << s2[i];
//            if (i != s2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//    }
//    else {
//        cout << "{ ";
//        for (int i = 0; i < s2.size(); i++) {
//            cout << s2[i];
//            if (i != s2.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " } { ";
//        for (int i = 0; i < s1.size(); i++) {
//            cout << s1[i];
//            if (i != s1.size() - 1) {
//                cout << ", ";
//            }
//        }
//        cout << " }\n";
//    }
//
//    /*
//    int diff = INT_MAX;
//
//    // Find the largest j such that part[n][j] is true
//    // where j loops from sum/2 to 0
//    for (int j = sum/2; j >= sum_neg; j--)
//    {
//        if (dp[n][j] == true)
//        {
//            diff = sum - 2 * j;
//            break;
//        }
//    }
//    cout << diff << " \n";
//    return diff;*/
//    return 0;
//}

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
    unordered_map<int, int> *dp = new unordered_map<int, int>[n];
    // dp2�� subset ���� �޶� �κ��������� ���������� �ʴ� ���
    unordered_map<int, bool> *dp2 = new unordered_map<int, bool>[n];

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
                dp[i][val] = dp[i-1][val] + dp[i - 1][val - nums[i]];
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
        partitionArray(nums);
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