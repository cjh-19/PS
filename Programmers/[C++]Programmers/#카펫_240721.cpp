/* 2차 풀이 */

#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 전체 넓이 = brown + yellow
    // (갈색 가로 - 2) * (갈색 세로 - 2) = yellow
    int total = brown + yellow;

    for (int height = 3; height <= sqrt(total); height++) {
        // 세로가 정수가 아닌 경우
        if (total % height != 0) {
            continue;
        }
        if ((total / height - 2) * (height - 2) == yellow) {
            answer.push_back(total / height);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}


/* 1차 풀이*/

// #include <vector>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;

//     int total_size = brown + yellow;
//     for(int h=3; h<total_size/2; h++){
//         if(total_size % h != 0)
//             continue;
//         if(((total_size/h)-2)*(h-2) == yellow){
//             answer.push_back(total_size/h);
//             answer.push_back(h);
//             break;
//         }
//     }

//     return answer;
// }