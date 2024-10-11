#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
int maxN = 0; // ���� ū ��尪

// �ι�° �ε��� ���� �������� ����
bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

// ������ ���� ��ȣ ���ϱ�
int createEdge(vector<vector<int>> edges) {
    int node = 0;
    sort(edges.begin(), edges.end(), cmp);
    // ������ ������ ������, ������ ������ 2�� �̻��� ����
    for (int i = 0; i < edges.size();) {
        if (edges[i][1] == node + 1) { i++; node++; }
        else if (edges[i][1] == node) { i++; continue; }
        else if (edges[i][1] >= node + 2) {
            if (graph[node + 1].size() >= 2) break; // ������ ���� 2�� �̻� üũ(���� ��)
            node++;
        }
    }
    return node + 1;
}

// 1�� ����, 2�� ����, 3�� 8��
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

    // �׷��� ���� ���� ����
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