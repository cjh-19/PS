#include<iostream>

using namespace std;

int main() {
	int N, num=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int len = str.size();
		if (len == 1 || len == 2){
			num++; continue;
        }
		int tmp = 1;
		for (int j = 0; j < len; j++) {
			if (j < len - 2) {
				int z = 1;
				if(str[j] != str[j+1]) {
					while (tmp == 1) {
						if (str[j] == str[j + 1 + z])
							tmp = 2;
						else if (j + 1 + z == len - 1)
							break;
						z++;
					}
				}
			}
		}
		if(tmp == 1)
			num++;
	}
	cout << num;
	return 0;
}