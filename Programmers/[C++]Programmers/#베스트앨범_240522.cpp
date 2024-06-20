// unordered_map, pair, custom sort 방법 이용

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 재생횟수가 같으면 인덱스 오름차순, 기본적으로는 횟수 내림차순 정렬
bool cmp(pair<int, int> v1, pair<int, int> v2) {
    if (v1.first == v2.first)
        return v1.second < v2.second; // 인덱스 오름차순
    else
        return v1.first > v2.first; // 횟수 내림차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> map1; // 장르, 장르별 총 횟수
    unordered_map<string, vector<pair<int, int>>> map2; // 장르, <횟수, 인덱스>

    for (int i = 0; i < genres.size(); i++) {
        map1[genres[i]] += plays[i];
        map2[genres[i]].push_back({ plays[i], i });
    }

    for (int k = 0; k < map1.size(); k++) {
        string max_gen;
        int max = 0;
        // 총 횟수가 가장 높은 장르 찾기
        for (auto i : map1) {
            if (i.second > max) {
                max = i.second;
                max_gen = i.first;
            }
        }
        map1[max_gen] = 0; // 가장 높은 장르의 횟수 0으로 초기화

        // &i처럼 &를 사용해야 하는 이유: 원본 요소를 직접 참조하여 루프 내에서 요소를 수정하기 위해서이다.
        // 루프 내에서 정렬하기 때문. "i"를 그냥 사용하게 되면 복사본에 작업하므로 원본 맵에 아무런 변경을 주지 못한다.
        // map2에서 max_gen에 해당하는 vector 정렬 후 1,2 순위 빼기
        for (auto &i : map2) {
            if (i.first == max_gen) {
                // 이것은 맵을 정렬하는 것이 아닌 맵 내부의 vector을 정렬하는 것
                sort(i.second.begin(), i.second.end(), cmp);
                answer.push_back(i.second[0].second);
                if (i.second.size() > 1) { // 장르에 속한 곡이 두개 이상이라면
                    answer.push_back(i.second[1].second);
                }
            }
        }
    }

    return answer;
}