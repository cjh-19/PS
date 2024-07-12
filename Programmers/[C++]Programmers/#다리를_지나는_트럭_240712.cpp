#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 하나의 트럭이 다리를 건너는데 걸리는 시간: 2초
    queue<pair<int, int>> truckQ; // 트럭과 다리에 올라간 시간을 담을 큐
    int time = 0; // 트럭이 모두 지나가기까지 시간
    int bW = 0; // 다리에 올라간 무게
    int index = 0; // 추가할 트럭 번호

    // truck_weights가 비어있거나 truckQ가 빌때까지 반복
    while (!truckQ.empty() || index < truck_weights.size()) {
        time++;

        // 다리에 올라간지 2초가 됐다면 트럭 빼기
        if (!truckQ.empty() && truckQ.front().second == time) {
            bW -= truckQ.front().first;
            truckQ.pop();
        }

        // 큐의 길이가 2 이하, weight 이하 라면 추가
        // pair: (트럭의 무게, 현재시간+다리를 다 지나는데 걸리는 시간)
        if (truckQ.size() < bridge_length && index < truck_weights.size() && bW + truck_weights[index] <= weight) {
            truckQ.push(pair<int, int>(truck_weights[index], time + bridge_length));
            bW += truck_weights[index];
            index++;
        }
    }
    return time;
}