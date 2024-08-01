#include <string>
#include <vector>

using namespace std;

// A부터 알파벳 최소 이동 거리
int alpha_move[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0;
    // 첫 문자는 'A'로 시작함

    int len = name.length();
    // 한쪽 방향으로 갔을때 조이스틱 최소 이동 거리
    int min_move = len - 1; // 첫 위치 제외

    // 모든 문자열 탐색(오른쪽으로)
    for (int i = 0; i < len; i++) {
        answer += alpha_move[name[i] - 'A']; // 알파벳 name[x] 부터 'A'까지의 차이

        // 원점부터 역방향으로 i+1까지 탐색했을 경우(왼쪽으로) -> 뒤쪽에 'A'가 많을 경우
        int j = i + 1;
        while (j < len && name[j] == 'A') j++;

        min_move = min(min_move, i + len - j + min(i, len - j));
    }

    answer += min_move;
    return answer;
}