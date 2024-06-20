#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string>s1 =
	{
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};
	vector<string>s2 =
	{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};
	vector<string>str;
	string s;
	int X, Y;
	cin >> X >> Y;
	for (int i = 0; i < X; i++) {
		cin >> s;
		str.push_back(s);
	}
	int minC = 2500;
	for (int i = 0; i <= Y - 8; i++) {
		for (int j = 0; j <= X - 8; j++) {
			string tmp;
			for (int h = 0; h < 8; h++) {
				tmp.append(str[j + h], i, 8);
			}
			int count = 0, c1 = 0, c2 = 0;
			int t = 0;
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					if (s1[k][q] != tmp[t++])
						c1++;
				}
			}
			t = 0;
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					if (s2[k][q] != tmp[t++])
						c2++;
				}
			}
			if (c1 > c2)
				count = c2;
			else
				count = c1;
			if (minC > count)
				minC = count;
		}
	}
	cout << minC;
	return 0;
}