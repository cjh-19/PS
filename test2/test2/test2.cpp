//unordered_map�� �̿��Ͽ� �����ε����� ó���� ���
//���� �ֽ��� ���� ����

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
//    //���� Ȧ�� �϶� subset�� ����
//    //sum /= 2;
//    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));
//    //�ʱ�ȭ
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
    // Partition not possible.
    // �� �κ������� ���� Ȧ�� �� ���
    if (sum & 1)
    {
        return vector<bool>();
    }

    int n = nums.size();

    // dp state
    unordered_map<int, int> *dp = new unordered_map<int, int>[n];
    // dp2�� subset ���� �ٸ����
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
    //count : ��� �κ������� ����� ��
    count = dp[idx][required];
    // Parition not possible. //subset ���� ���� ���� ���
    if (!dp[idx][required])
    {
        //vector<bool> ret;
        //return ret;
        
        // Initialize difference of two sums.
        int diff = INT_MAX;

        // Find the largest j such that dp2[n][j]
        // is true where j loops from sum/2 t0 0
        // sum/2 ���� 0������ j����
        // dp2[n][j]�� ���� ����� j���� ã�� ��?
        // diff�� �� ���� ���� ���� ����
        // �׷��� sum - j - j
        // �� ������ ���� �� s1 s2��� �ϸ�
        // |s1 - s2| == sum - (j + j)
        // ���� sum�� 11 �̶�� �Ѵ�.
        // �׷��� diff �� 3�̶�������
        // 4��7�ۿ� ����.
        // sum = 11, 2*j = 8 �̴�. j=4
        // j�� 4�� ������?
        // �츮�� �� ���� dp2[n][j]�� �̿��Ͽ� �ּҰ�
        // �� ���� ������ ã�� ���̴�.
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
        cout << "���� : " << count << "\n";
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
        cout << "���� : " << count << "\n";
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