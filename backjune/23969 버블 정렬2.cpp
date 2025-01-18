#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;
	vector<int> A;

	while (N--) {
		int number;
		cin >> number;
		A.emplace_back(number);
	}

	int answer = 0;
	for (int i = A.size(); i >= 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = temp;
				answer++;
			}
			if (answer == k)  break;
		}
		if (answer == k) break;
	}
	if (answer == k) {
		for (int i : A) {
			cout << i << " ";
		}
	}
	else {
		cout << -1;
	}
}