#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int,int>> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i].first;
		vec[i].second = i;
	}

	sort(vec.begin(), vec.end());

	int min = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second - i > min)
			min = vec[i].second - i;
	}
	cout << min + 1;
}