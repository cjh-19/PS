/* 2�� Ǯ�� */

#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // ��ü ���� = brown + yellow
    // (���� ���� - 2) * (���� ���� - 2) = yellow
    int total = brown + yellow;

    for (int height = 3; height <= sqrt(total); height++) {
        // ���ΰ� ������ �ƴ� ���
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


/* 1�� Ǯ��*/

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