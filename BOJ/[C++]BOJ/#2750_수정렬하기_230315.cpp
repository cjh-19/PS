#include<iostream>
using namespace std;

void sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int& A, int& B);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int *arr = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}
	sort(arr, 0, T - 1);

	for (int i = 0; i < T; i++)
		cout << arr[i] << "\n";
	return 0;
}

void sort(int arr[], int left, int right) {
	if (left < right) {
		int p = partition(arr, left, right);

		sort(arr, left, p - 1);
		sort(arr, p + 1, right);
	}

}

int partition(int arr[], int left, int right) {
	int pivot = arr[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);

	return (i + 1);
}

void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}