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

	for (int i : vec) {
		cout << i << endl;
	}
}
