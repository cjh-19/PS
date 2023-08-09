#include<iostream>

using namespace std;

#define MAX 1000001
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < MAX; i++)
		arr[i] = i;
	for (int i = 2; i * i < MAX; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j < MAX; j += i)
			arr[j] = 0;
	}
	int Num;
	cin >> Num;
	for (int i = 0; i < Num; i++) {
		int N, count = 0;
		cin >> N;
		for (int i = 2; i <= N / 2; i++)
			if (arr[i] != 0)
				if (arr[N-i] + arr[i] == N)
					count++;
		cout << count << "\n";
	}
	return 0;
}