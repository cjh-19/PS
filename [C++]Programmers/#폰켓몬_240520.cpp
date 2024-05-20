#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size() / 2;
    set<int> s(nums.begin(), nums.end());
    if (s.size() < answer)
        answer = s.size();

    return answer;
}