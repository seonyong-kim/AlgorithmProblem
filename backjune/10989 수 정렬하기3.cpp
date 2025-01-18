#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int arr[10001] = {0};
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		arr[number]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (arr[i] != 0) {
			cout << i << "\n";
			arr[i]--;
		}
	}
}