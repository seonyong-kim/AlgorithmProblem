#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec;
	while (N--) {
		int number;
		cin >> number;
		vec.emplace_back(number);
	}

	sort(vec.begin(), vec.end());

	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[vec.size() -1 - i] * (i + 1);
	}
	cout << sum;
}
