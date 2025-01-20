#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch(vector<int>& v, int value, int min, int max) {

	if (max < min) {
		return false;
	}

	int mid = (max + min) / 2;

	if (v[mid] == value) {
		return true;
	}

	else if (v[mid] > value) {
		return BinarySearch(v, value, min, mid - 1);
	}

	else {
		return BinarySearch(v, value, mid + 1, max);
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cin >> m;
	vector<int> check(m);

	for (int i = 0; i < m; i++) {
		cin >> check[i];
	}

	sort(v.begin(), v.end());

	for (int i : check) {
		if (BinarySearch(v, i, 0, v.size() - 1)) cout << 1 << " ";
		else cout << 0 << " ";
	}
	return 0;
}