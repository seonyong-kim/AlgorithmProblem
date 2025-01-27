#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<double> vec;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		vec.emplace_back(number);
	}
	sort(vec.begin(), vec.end());

	double outliers = round(n * 0.15);
	double sum = 0;
	for (int i = outliers; i < vec.size() - outliers; i++) {
		sum += vec[i];
	}

	cout << round(sum / (vec.size() - 2*outliers));
}

