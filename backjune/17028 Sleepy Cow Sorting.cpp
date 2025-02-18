#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, number;
	cin >> N;
	vector<int> vec;
	while (N--) {
		cin >> number;
		vec.emplace_back(number);
	}

	int n = vec.size();
	for (int i = n - 1; i >= 1; i--) {
		if (vec[i] < vec[i - 1]) {
			cout << i;
			break;
		}
	}
}
