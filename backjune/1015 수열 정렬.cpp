#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N , number;
	cin >> N;
	vector<pair<int,bool>> arr(N);
	vector<int> arr1(N);
	for (int i = 0; i < N; i++) {
		cin >> number;
		arr[i].first = number;
		arr[i].second = false;
		arr1[i] = number;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j].first == arr1[i] && arr[j].second == false) {
				cout << j<< " ";
				arr[j].second = true;
				break;
			}
		}
	}
}