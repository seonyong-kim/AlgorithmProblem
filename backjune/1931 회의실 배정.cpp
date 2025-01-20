#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> vec;
	while (N--) {
		int start, end;
		cin >> start >> end;
		vec.push_back({end, start});
	}
	sort(vec.begin(), vec.end());

	int count = 0;
	int endTime = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (endTime <= vec[i].second) {
			endTime = vec[i].first;
			count++;
		}
	}

	cout << count;
}