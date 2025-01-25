#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	vector<int> vec(M);
	for (int i = 0; i < M; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		bool result = false;
		int leftIndex = 0; int rightIndex = vec.size() - 1;
		while (leftIndex <= rightIndex) {
			int midIndex = (leftIndex + rightIndex) / 2;
			if (vec[midIndex] < number) {
				leftIndex = midIndex + 1;
			}
			else if (vec[midIndex] > number) {
				rightIndex = midIndex - 1;
			}
			else {
				result = true;
				break;
			}
		}
		cout << (result ? "1\n" : "0\n");
	}
}