//unordered_map을 이용하여 음수인덱스도 처리한 방법
//가장 최신의 구현 파일

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

void solve(vector<int>& nums, int idx, int n, int acc, int sum, vector<vector<int>>& v)
{
    if (idx == n)
    {
        v[acc].push_back(sum);
    }
    else
    {
        solve(nums, idx + 1, n, acc, sum - nums[idx], v);
        solve(nums, idx + 1, n, acc + 1, sum + nums[idx], v);
    }
}

int minimumDifference6(vector<int>& nums) {
    int n = nums.size() / 2;
    vector<vector<int>> va(n + 1), vb(n + 1);
    solve(nums, 0, n, 0, 0, va);
    solve(nums, n, 2 * n, 0, 0, vb);
    for (int i = 0; i <= n; i++)
    {
        sort(va[i].begin(), va[i].end());
        sort(vb[i].begin(), vb[i].end());
    }
    int ans = 1e9;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < va[i].size(); j++)
        {
            int tar = -va[i][j];
            if (tar <= vb[n - i][0])
            {
                ans = min(ans, abs(va[i][j] + vb[n - i][0]));
            }
            else if (tar >= vb[n - i].back())
            {
                ans = min(ans, abs(va[i][j] + vb[n - i].back()));
            }
            else
            {
                int idx = lower_bound(vb[n - i].begin(), vb[n - i].end(), tar) - vb[n - i].begin();
                int val = min(abs(va[i][j] + vb[n - i][idx]), abs(va[i][j] + vb[n - i][idx - 1]));
                ans = min(ans, val);
            }
        }
    }
    cout << ans << "\n";
    return ans;
}



//int solve(vector<int>& nums, int i, int j, int sum1, int sum2, unordered_map<string, int>& memo) {
//    if (i == nums.size()) {
//        return abs(sum1 - sum2);
//    }
//    string key = to_string(i) + "-" + to_string(j);
//    if (memo.find(key) != memo.end()) {
//        return memo[key];
//    }
//    if (j == 0) {
//        int res = solve(nums, i + 1, j, sum1 + nums[i], sum2, memo);
//        memo[key] = res;
//        return res;
//    }
//    if (i - j == nums.size() / 2) {
//        int res = solve(nums, i + 1, j - 1, sum1, sum2 + nums[i], memo);
//        memo[key] = res;
//        return res;
//    }
//    int res = min(abs(sum1 - sum2), min(solve(nums, i + 1, j - 1, sum1 + nums[i], sum2, memo), solve(nums, i + 1, j, sum1, sum2 + nums[i], memo)));
//    memo[key] = res;
//    return res;
//}
//
//pair<vector<int>, vector<int>> partition(vector<int>& nums) {
//    int n = nums.size();
//    int target = accumulate(nums.begin(), nums.end(), 0) / 2;
//    unordered_map<string, int> memo;
//    int diff = solve(nums, 0, n / 2, 0, 0, memo);
//    vector<int> left, right;
//    int i = 0, j = n / 2, sum1 = 0, sum2 = 0;
//    while (i < n && j > 0) {
//        if (j == 1) {
//            left.push_back(nums[i]);
//            sum1 += nums[i];
//            i++;
//            j--;
//        }
//        else if (i - j == n / 2) {
//            right.push_back(nums[i]);
//            sum2 += nums[i];
//            i++;
//            j--;
//        }
//        else if (abs(sum1 + nums[i] - sum2) <= abs(sum2 + nums[i] - sum1)) {
//            left.push_back(nums[i]);
//            sum1 += nums[i];
//            i++;
//            j--;}
//        else {
//            right.push_back(nums[i]);
//            sum2 += nums[i];
//            i++;
//            j--;
//        }
//    }
//    while (i < n) {
//        right.push_back(nums[i]);
//        sum2 += nums[i];
//        i++;
//    }
// /*   while (j > 0) {
//        left.push_back(nums[i]);
//        sum1 += nums[i];
//        i++;
//        j--;
//    }*/
//    cout << "{ ";
//    for (int i = 0; i < left.size(); i++) {
//        cout << left[i];
//        if (i != left.size() - 1) {
//            cout << ", ";
//        }
//    }
//    cout << " } { ";
//    for (int i = 0; i < right.size(); i++) {
//        cout << right[i];
//        if (i != right.size() - 1) {
//            cout << ", ";
//        }
//    }
//    cout << " }\n";
//    return {left, right};
//}











//
const int INF = 1e9;

vector<vector<int>> memo;

int solve(int i, int sum, vector<int>& nums) {
    if (i == 0) {
        return abs(sum);
    }
    if (memo[i][sum + 50000] != -1) {
        return memo[i][sum + 50000];
    }
    int ans = INF;
    ans = min(ans, solve(i - 1, sum + nums[i - 1], nums));
    ans = min(ans, solve(i - 1, sum - nums[i - 1], nums));
    memo[i][sum + 50000] = ans;
    return ans;
}

vector<vector<int>> getSubsets(int n, vector<int>& nums) {
    vector<vector<int>> res(n + 1);
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0, count = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += nums[j];
                count++;
            }
        }
        res[count].push_back(sum);
    }
    return res;
}

pair<vector<int>, vector<int>> minimizeSubsetDifference(vector<int>& nums) {
    int n = nums.size();
    memo.assign(n + 1, vector<int>(100001, -1));
    int diff = solve(n, 0, nums);
    vector<vector<int>> subsets = getSubsets(n, nums);
    for (int i = 0; i <= n / 2; i++) {
        sort(subsets[i].begin(), subsets[i].end());
    }
    vector<int> left, right;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j < subsets[i].size(); j++) {
            int target = subsets[i][j];
            int idx = n / 2 - i;
            auto it = lower_bound(subsets[idx].begin(), subsets[idx].end(), target);
            if (it != subsets[idx].end() && *it == target) {
                left.clear();
                right.clear();
                for (int k = 0; k < n; k++) {
                    if (k < idx && abs(*it - nums[k]) <= diff / 2) {
                        left.push_back(nums[k]);
                    }
                    else if (k >= idx && abs(*it + nums[k]) <= diff / 2) {
                        right.push_back(nums[k]);
                    }
                }
                cout << "{ ";
                for (int i = 0; i < left.size(); i++) {
                    cout << left[i];
                    if (i != left.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " } { ";
                for (int i = 0; i < right.size(); i++) {
                    cout << right[i];
                    if (i != right.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }\n";
                return { left, right };
            }
        }
    }
    cout << "{ ";
    for (int i = 0; i < left.size(); i++) {
        cout << left[i];
        if (i != left.size() - 1) {
            cout << ", ";
        }
    }
    cout << " } { ";
    for (int i = 0; i < right.size(); i++) {
        cout << right[i];
        if (i != right.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }\n";
    

    return { left, right };
}



/*int sum(vector<int>& nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    return total;
}

// 두 개의 배열의 합의 차이를 반환하는 함수
int diff(vector<int>& nums1, vector<int>& nums2) {
    return abs(sum(nums1) - sum(nums2));
}

// 가능한 모든 배열 분할을 생성하는 함수
void findAllPartitions(vector<vector<int>>& partitions, vector<int>& curPartition, vector<int>& nums, int startIdx, int n) {
    if (startIdx == n) {
        partitions.push_back(curPartition);
        return;
    }
    // 현재 원소를 첫 번째 배열에 추가하고 다음 원소를 처리하는 재귀 호출
    curPartition.push_back(nums[startIdx]);
    findAllPartitions(partitions, curPartition, nums, startIdx + 1, n);
    curPartition.pop_back(); // 첫 번째 배열에서 현재 원소를 제거하고 두 번째 배열에 추가하는 재귀 호출
    curPartition.push_back(-nums[startIdx]); // 음수로 추가하여 두 번째 배열의 합 계산 시 고려
    findAllPartitions(partitions, curPartition, nums, startIdx + 1, n);
    curPartition.pop_back(); // 두 번째 배열에서 현재 원소를 제거하여 다음 분할을 계산하는 재귀 호출
}

// 다이나믹 프로그래밍을 사용하여 분할을 계산하는 함수
pair<vector<int>, vector<int>> dpPartition(vector<int>& nums) {
    int n = nums.size();
    int total = sum(nums);
    // dp[i][j] : 0 ~ i번째 원소까지 이용해서 두 배열의 합 차이를 j로 만들 때 첫 번째 배열의 크기의 최대값
    vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
    vector<vector<int>> dpPrev(n, vector<int>(2 * total + 1, -1));
    dp[0][total + nums[0]] = 1;
    dp[0][total - nums[0]] = 0;
    dpPrev[0][total + nums[0]] = 1;
    dpPrev[0][total - nums[0]] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = -total; j <= total; j++) {
            // dpPrev[i - 1][j] != -1이 아니면, dpPrev[i - 1][j]에 대응되는 첫 번째 배열이 존재함
            if (dpPrev[i - 1][j + total] != -1) {
                dp[i][j + total] = dpPrev[i - 1][j + total];
            }
            // dpPrev[i - 1][j - nums[i]] != -1이 아니면, dpPrev[i - 1][j - nums[i]]에 대응되는 첫 번째 배열이 존재함
            if (j - nums[i] >= -total && j - nums[i] <= total && dpPrev[i - 1][j - nums[i] + total] != -1) {
                dp[i][j + total] = max(dp[i][j + total], dpPrev[i - 1][j - nums[i] + total] + 1);
}
            // dpPrev[i - 1][j + nums[i]] != -1이 아니면, dpPrev[i - 1][j + nums[i]]에 대응되는 첫 번째 배열이 존재함
            if (j + nums[i] >= -total && j + nums[i] <= total && dpPrev[i - 1][j + nums[i] + total] != -1) {
                dp[i][j + total] = max(dp[i][j + total], dpPrev[i - 1][j + nums[i] + total]);
            }
        }
        dpPrev[i] = dp[i];
    }
    // dp[n - 1][0]은 두 배열의 합 차이가 0이 되도록 첫 번째 배열을 나눴을 때 첫 번째 배열의 최대 크기를 의미
    int firstSize = dp[n - 1][total];
    vector<int> firstPartition;
    vector<int> secondPartition;
    int i = n - 1;
    int j = total;
    while (i >= 1 && j >= 0) {
        if (dpPrev[i - 1][j + total] == firstSize) { // 첫 번째 배열에 포함됨
            firstPartition.push_back(nums[i]);
            firstSize--;
            j -= nums[i];
        }
        else { // 두 번째 배열에 포함됨
            secondPartition.push_back(nums[i]);
            j += nums[i];
        }
        i--;
    }
    // 첫 번째 원소는 항상 첫 번째 배열에 포함되어야 함
    firstPartition.push_back(nums[0]);
    cout << "{ ";
    for (int i = 0; i < firstPartition.size(); i++) {
        cout << firstPartition[i];
        if (i != firstPartition.size() - 1) {
            cout << ", ";
        }
    }
    cout << " } { ";
    for (int i = 0; i < secondPartition.size(); i++) {
        cout << secondPartition[i];
        if (i != secondPartition.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }\n";
    return make_pair(firstPartition, secondPartition);
}
*/





vector<int> minDiffPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0); // 배열 전체의 합 계산

    // dp 배열 초기화
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum / 2 + 1, false));
    dp[0][0] = true;

    // dp 배열 채우기
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalSum / 2; j++) {
            dp[i][j] = dp[i - 1][j]; // i번째 수를 사용하지 않는 경우
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // i번째 수를 사용하는 경우
            }
        }
    }

    // 가능한 모든 분할 생성
    int leftSum = 0;
    for (int j = totalSum / 2; j >= 0; j--) {
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
        if (curleftSum >= nums[i - 1] && dp[i - 1][curleftSum - nums[i - 1]]) { // i번째 수를 사용하는 경우
            leftSubset.push_back(nums[i - 1]);
            curleftSum -= nums[i - 1];
        }
        else { // i번째 수를 사용하지 않는 경우
            rightSubset.push_back(nums[i - 1]);
        }
    }

    //int n = nums.size();
    //int totalSum = 0;
    //for (int i = 0; i < n; i++) {
    //    totalSum += nums[i];
    //}

    //int targetSum = (totalSum + 1) / 2;
    //vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
    ////unordered_map<int, bool>* dp = new unordered_map<int, bool>[n];

    //dp[0][0] = true;
    //if (targetSum > 0) {
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = 0; j <= targetSum; j++) {
    //            if (nums[i - 1] > j) {
    //                dp[i][j] = dp[i - 1][j];
    //            }
    //            else {
    //                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    //            }
    //        }
    //    }
    //}
    //else {
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = 0; j >= targetSum; j--) {
    //            if (nums[i - 1] > j) {
    //                dp[i][j] = dp[i - 1][j];
    //            }
    //            else {
    //                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    //            }
    //        }
    //    }
    //}

    //int leftSum = 0;
    //for (int i = targetSum; i >= 0; i--) {
    //    if (dp[n][i]) {
    //        leftSum = i;
    //        break;
    //    }
    //}

    //int rightSum = totalSum - leftSum;

    //vector<int> leftSubset, rightSubset;

    //int i = n, curSum = leftSum;
    //while (i > 0 && curSum >= 0) {
    //    if (curSum - nums[i - 1] >= 0 && dp[i - 1][curSum - nums[i - 1]]) {
    //        leftSubset.push_back(nums[i - 1]);
    //        curSum -= nums[i - 1];
    //    }
    //    i--;
    //}

    //i = n, curSum = rightSum;
    //while (i > 0 && curSum >= 0) {
    //    if (curSum - nums[i - 1] >= 0 && dp[i - 1][curSum - nums[i - 1]]) {
    //        rightSubset.push_back(nums[i - 1]);
    //        curSum -= nums[i - 1];
    //    }
    //    i--;
    //}

    // 결과 반환
    reverse(leftSubset.begin(), leftSubset.end());
    reverse(rightSubset.begin(), rightSubset.end());
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


    vector<int> result;// = { leftSubset, rightSubset };
    return result;
}


//bitmask 사용
int minimumDifference5(vector<int>& nums) {
    int n = nums.size(), res = 0, sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);

    int N = n / 2;
    vector<vector<int>> left(N + 1), right(N + 1);

    //storing all possible sum in left and right part
    for (int mask = 0; mask < (1 << N); ++mask) {
        int sz = 0, l = 0, r = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sz++;
                l += nums[i];
                r += nums[i + N];
            }
        }
        left[sz].push_back(l);
        right[sz].push_back(r);
    }
    
    for (int sz = 0; sz <= N; ++sz) {
        sort(right[sz].begin(), right[sz].end());
    }

    res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));
    int lastLeft = 0, lastRight = 0;
    //iterating over left part
    for (int sz = 1; sz < N; ++sz) {
        for (auto& a : left[sz]) {
            int b = (sum - 2 * a) / 2, rsz = N - sz;
            auto& v = right[rsz];
            auto itr = lower_bound(v.begin(), v.end(), b); //binary search over right part

            if (itr != v.end()) res = min(res, abs(sum - 2 * (a + (*itr))));
            if (itr != v.begin()) {
                auto it = itr; --it;
                res = min(res, abs(sum - 2 * (a + (*it))));
                /*int ans = abs(sum - 2 * (a + (*it)));
                if (ans < res) {
                    res = ans;
                    lastLeft = a;
                    lastRight = *it;
                }*/
            }
        }
    }
    /*vector<vector<int>> left2(N + 1), right2(N + 1);
    vector<int> L, R;
    for (int mask = 0; mask < (1 << N); ++mask) {
        int sz = 0, l = 0, r = 0;
        L.clear();
        R.clear();
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sz++;
                l += nums[i];
                r += nums[i + N];
                L.push_back(nums[i]);
                R.push_back(nums[i + N]);
            }
        }
        left2[sz].push_back(l);
        right2[sz].push_back(r);
        if (l == lastLeft && r == lastRight) {
            break;
        }
    }
    cout << "Left subset: ";
    for (int i : L) cout << i << " ";
    cout << "\n";

    cout << "Right subset: ";
    for (int i : R) cout << i << " ";
    cout << "\n";*/



    //return res;
    cout << "Minimum possible absolute difference: " << res << "\n";
    return res;
}


/*
int minimumDifference4(vector<int>& nums) {
    int totalSum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    int totLengthOfSubarray = r - l + 1;
    vector<vector<int>> res(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[l + j];
                countOfChosenNos++;
            }
        }
        res[countOfChosenNos].push_back(sum);
    }


    //iterator 사용, 훨씬 빨라짐
    auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
    auto right = findAllSubsetsSum(nums, n / 2, n - 1);
    int target = totalSum / 2, ans = INT_MAX;

    vector<int> leftAns, rightAns;

    //we can take (0 to n/2) length numbers from left
    for (int i = 0; i <= n / 2; i++) {
        //now we take rest - (n/2-i) length from right, we sort it to binary search
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));
        //curleftSum : left 부분집합에서 가능한 모든 합
        for (int curleftSum : left[i]) {
            int needSumFromRight = target - curleftSum;
            auto it = lower_bound(begin(r), end(r), needSumFromRight); //needSumFromRight를 찾기 위해 이분탐색을 한다
            if (it != end(r)) {
                ans = min(ans, abs(totalSum - 2 * (curleftSum + *it))); //합의 차이 계산
                int curAns = abs(totalSum - 2 * (curleftSum + *it));
                ans = curAns;
                rightAns.push_back(*it);
                //}
            }
            else leftAns.push_back(curleftSum);
        }
    }
    cout << "Left subset: ";
    for (int i : leftAns) cout << i << " ";
    cout << "\n";

    cout << "Right subset: ";
    for (int i : rightAns) cout << i << " ";
    cout << "\n";

    cout << "Minimum possible absolute difference: " << ans << "\n";
    return ans;
    ///

    cout << ans << "\n";
    return ans;
}*/


// 이함수가 가장빠르지만 어떻게 집합을 출력해야할지를 모르겠음.. 하
vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
    int totLengthOfSubarray = r - l + 1;
    vector<vector<int>> res(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[l + j];
                countOfChosenNos++;
            }
        }
        res[countOfChosenNos].push_back(sum);
    }
    return res;
}

int minimumDifference2(vector<int>& nums) {
    int totalSum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    int totLengthOfSubarray = (n / 2) - 1 - 0 + 1;
    vector<vector<int>> res1(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
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
    vector<vector<int>> res2(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[n/2 + j];
                countOfChosenNos++;
            }
        }
        res2[countOfChosenNos].push_back(sum);
    }
    auto right = res2;



    //iterator 사용, 훨씬 빨라짐
    //auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
    //auto right = findAllSubsetsSum(nums, n / 2, n - 1);
    int target = totalSum / 2, ans = INT_MAX;

    vector<int> leftAns, rightAns;
    int lastLeft = 0, lastRight = 0;

    //we can take (0 to n/2) length numbers from left
    for (int i = 0; i <= n / 2; i++) {
        //now we take rest - (n/2-i) length from right, we sort it to binary search
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));
        //curleftSum : left 부분집합에서 가능한 모든 합
        for (int curleftSum : left[i]) {
            int needSumFromRight = target - curleftSum;
            auto it = lower_bound(begin(r), end(r), needSumFromRight); //needSumFromRight를 찾기 위해 이분탐색을 한다
            if (it != end(r)) {
                //ans = min(ans, abs(totalSum - 2 * (curleftSum + *it))); //합의 차이 계산
                /*int diff = abs(totalSum - 2 * (curleftSum + *it));
                if (diff < ans) {
                    ans = diff;
                    leftAns = findAllSubsetsSum(nums, 0, n / 2 - 1)[i];
                    rightAns = findAllSubsetsSum(nums, n / 2, n - 1)[n / 2 - i];
                }*/
                //copy(left[i].begin(), left[i].end(), leftAns.begin());
                //copy(r.begin(), it + 1, rightAns.begin());
                //int curAns = abs(totalSum - 2 * (curleftSum + *it));
                //ans = curAns;
                int curAns = abs(totalSum - 2 * (curleftSum + *it));
                lastLeft = curleftSum;
                lastRight = *it;
                if (curAns < ans) {
                    ans = curAns;
                    lastLeft = curleftSum;
                    lastRight = *it;
                    //copy(left[i].begin(), left[i].end(), leftAns.begin());
                    //copy(r.begin(), it + 1, rightAns.begin());
                    //leftAns.push_back(curleftSum);
                    //rightAns.push_back(*it);
                }
            }
            //else leftAns.push_back(curleftSum);
        }
    }


    vector<int> L, R;
    totLengthOfSubarray = (n / 2) - 1 - 0 + 1;
    int totLengthOfSubarray2 = (n - 1) - n / 2 + 1;
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        for (int k = 0; k < (1 << totLengthOfSubarray2); k++) {
            int sum = 0;
            int sum2 = 0;
            L.clear();
            R.clear();
            for (int j = 0; j < totLengthOfSubarray; j++) {
                if (i & (1 << j)) {
                    sum += nums[j];
                    L.push_back(nums[j]);
                }
                else {
                    sum2 += nums[j];
                    R.push_back(nums[j]);
                }
            }
            for (int j = 0; j < totLengthOfSubarray2; j++) {
                if (k & (1 << j)) {
                    sum2 += nums[n / 2 + j];
                    R.push_back(nums[n / 2 + j]);
                }
                else {
                    sum += nums[n/2 + j];
                    L.push_back(nums[n/2 + j]);
                }
            }
            if (lastLeft == sum && lastRight == sum2)
                break;
        }
    }

 






    //vector<int> L, R;
    //totLengthOfSubarray = (n / 2) - 1 - 0 + 1;
    ////vector<vector<int>> res3(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
    //for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
    //    int sum = 0, countOfChosenNos = 0;
    //    L.clear();
    //    for (int j = 0; j < totLengthOfSubarray; j++) {
    //        if (i & (1 << j)) {
    //            sum += nums[j];
    //            countOfChosenNos++;
    //            L.push_back(nums[j]);
    //        }
    //    }
    //    if (lastLeft == sum)
    //        break;
    //    //res3[countOfChosenNos].push_back(sum);
    //}
    ////auto left = res1;

    //totLengthOfSubarray = (n - 1) - n / 2 + 1;
    ////vector<vector<int>> res4(totLengthOfSubarray + 1); //길이+1의 res 2차원 벡터생성
    //for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
    //    int sum = 0, countOfChosenNos = 0;
    //    R.clear();
    //    for (int j = 0; j < totLengthOfSubarray; j++) {
    //        if (i & (1 << j)) {
    //            sum += nums[n/2 + j];
    //            countOfChosenNos++;
    //            R.push_back(nums[n/2 + j]);
    //        }
    //    }
    //    if (lastRight == sum)
    //        break;
    //    //res4[countOfChosenNos].push_back(sum);
    //}
    ////auto right = res2;


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

    //cout << "Left subset: ";
    //for (int i : L) cout << i << " ";
    //cout << "\n";

    //cout << "Right subset: ";
    //for (int i : R) cout << i << " ";
    //cout << "\n";

    cout << "Minimum possible absolute difference: " << ans << "\n";
    return ans;
    ///

    cout << ans << "\n";
    return ans;
}



int minimumDifference3(vector<int>& nums) {
    int n = nums.size(), res = 0, sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);

    int N = n / 2;
    vector<vector<int>> left(N + 1), right(N + 1);

    //storing all possible sum in left and right part
    for (int mask = 0; mask < (1 << N); ++mask) {
        int sz = 0, l = 0, r = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sz++;
                l += nums[i];
                r += nums[i + N];
            }
        }
        left[sz].push_back(l);
        right[sz].push_back(r);
    }

    for (int sz = 0; sz <= N; ++sz) {
        sort(right[sz].begin(), right[sz].end());
    }

    res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

    //iterating over left part
    for (int sz = 1; sz < N; ++sz) {
        for (auto& a : left[sz]) {
            int b = (sum - 2 * a) / 2, rsz = N - sz;
            auto& v = right[rsz];
            auto itr = lower_bound(v.begin(), v.end(), b); //binary search over right part

            if (itr != v.end()) res = min(res, abs(sum - 2 * (a + (*itr))));
            if (itr != v.begin()) {
                auto it = itr; --it;
                res = min(res, abs(sum - 2 * (a + (*it))));
            }
        }
    }
    cout << res << "\n";
    return res;

}

const int MAX_INT = ~(1 << 31);

// Returns the minimum value of the difference of the two sets.
int findMinimum(vector<int>& arr)
{
    int n = arr.size();
    int sum = 0;

    // Calculcate sum of all elements
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Allocate a 2D array for calculating DP
    //bool** part = new bool* [sum / 2 + 1];

    vector<vector<bool>> part(sum/2 + 1, vector<bool>(n + 1));
    //for (int i = 0; i < sum / 2 + 1; i++)
    //    part[i] = new bool[n + 1];

    // Initialize top row as true
    for (int i = 0; i <= n; i++)
        part[0][i] = true;

    // Initialize leftmost column, except part[0][0], as false
    for (int i = 1; i <= sum / 2; i++)
        part[i][0] = false;

    // Fill the partition table in bottom up manner 
    for (int i = 1; i <= sum / 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
        }
    }

    int diff = MAX_INT;

    // Find the largest j such that part[n][j] is true
    // where j loops from sum/2 to 0
    for (int j = sum / 2; j >= 0; j--)
    {
        if (part[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    cout << diff << "\n";

    return diff;
}

int findMin2(vector<int>&nums)
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

    int required = sum / 2;
    int idx = n - 1;

    // Tracks partition elements.
    vector<bool> result_subset(nums.size(), 0);
    // Tracks count of elements included in S1.
    int cnt = 0;
    int diff = INT_MAX;
    for (int j = required; j >= 0; j--)
    {
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
            break;
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
    unordered_map<int, bool>* dp = new unordered_map<int, bool>[n+1];
    
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
            dp[i][j] = dp[i-1][j];
            /*if (j == nums[i - 1]) {
                dp[i][j] = true;
                //cout << dp[i][j] << " ";
            }*/
            if (j - nums[i - 1] >= sum_neg) {
                dp[i][j] |=  dp[i - 1][j - nums[i - 1]];
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


//하 슈발 모르겠다
void test(vector<int>& nums) {
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
    map<int, bool>* dp3 = new map<int, bool>[n + 1];
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp3[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp3[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = sum_neg; j <= sum_pos; j++) {
            // If i'th element is excluded
            dp3[i][j] = dp3[i - 1][j];

            // If i'th element is included
            if (sum_neg <= j-nums[i-1])
                dp3[i][j] |= dp3[i - 1][j - nums[i - 1]];
        }
    }

    //int required = sum / 2;

    //// Tracks partition elements.
    //vector<bool> result_subset(nums.size(), 0);
    //// Tracks count of elements included in S1.
    //int cnt = 0;
    //for (int i = n; i >= 1 && cnt < n / 2; i--) {
    //    if (required >= nums[i - 1] && dp3[i - 1][required - nums[i - 1]]) {
    //        required -= nums[i - 1];
    //        cnt++;
    //        result_subset[i - 1] = 1;
    //    }
    //}

    int required = sum / 2;
    int idx = n - 1;


    // Tracks partition elements.
    vector<bool> result_subset(nums.size(), 0);
    // Tracks count of elements included in S1.
    int cnt = 0;
    while (idx >= 0)
    {
        if (idx != 0)
        {
            // Reverse dp transition.
            if (required >= nums[idx - 1] && dp3[idx - 1][required - nums[idx - 1]])
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
    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        //cout << result_subset[i] << " ";
        if (result_subset[i] == 0)
            s1.push_back(nums[i]);
        else
            s2.push_back(nums[i]);

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
    unordered_map<int, int> *dp = new unordered_map<int, int>[n];
    // dp2는 subset 합이 달라 부분집합으로 나뉘어지지 않는 경우
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
    //count : 모든 부분집합의 경우의 수
    count = dp[idx][required];

    if (count > NUMEROUS) {
        cout << "NUMEROUS\n";
        return  vector<bool>();
    }

    // Parition not possible. //subset 합이 같지 않은 경우
    if (!dp2[idx][required] || sum & 1)
    {
        //test(nums);
        //partitionArray(nums);
        //partition(nums);
        //findMinDiff(nums);
        //minimumAbsDifference(nums);
        //findPartition(nums);
        //minAbsDifference(nums);
        findMin(nums);//주요
        //partition2(nums);
        //minimumDifference(nums);
        //minimumDifference2(nums);//주요
        //sum1(nums);
        //minDiffPartition(nums);
        //dpPartition(nums);
        //minimumDifference5(nums);//주요
        //minimizeSubsetDifference(nums);
        //partition(nums);
        //minimumDifference6(nums);
        //findMin2(nums); //주요
        //findMinimum(nums);
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