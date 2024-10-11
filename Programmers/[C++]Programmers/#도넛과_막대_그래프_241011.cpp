#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
int maxN = 0; // 가장 큰 노드값

// 두번째 인덱스 기준 오름차순 정렬
bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

// 생성한 정점 번호 구하기
int createEdge(vector<vector<int>> edges) {
    int node = 0;
    sort(edges.begin(), edges.end(), cmp);
    // 들어오는 간선이 없으며, 나가는 간선이 2개 이상인 정점
    for (int i = 0; i < edges.size();) {
        if (edges[i][1] == node + 1) { i++; node++; }
        else if (edges[i][1] == node) { i++; continue; }
        else if (edges[i][1] >= node + 2) {
            if (graph[node + 1].size() >= 2) break; // 나가는 간선 2개 이상 체크(생성 점)
            node++;
        }
    }
    return node + 1;
}

// 1은 도넛, 2는 막대, 3은 8자
int check(int num) {
    int start = num;
    while (1) {
        if (graph[num].size() >= 2) return 3;
        else if (graph[num].size() == 0) return 2;
        num = graph[num][0];
        if (start == num) return 1;
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    graph.clear();

    for (auto edge : edges) {
        maxN = max(maxN, max(edge[0], edge[1]));
    }

    graph.resize(maxN + 1);

    // 그래프 간선 관계 설정
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    int startNode = createEdge(edges);
    answer[0] = startNode;

    for (int i = 0; i < graph[startNode].size(); i++) {
        int chk = check(graph[startNode][i]);
        answer[chk]++;
    }

    return answer;
}