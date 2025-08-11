#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct info {
	int count = 0;
	int order;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C, number;
	cin >> N >> C;
	unordered_map<int, info> m;
	for (int i = 0; i < N; i++) {
		cin >> number;
		if (m[number].count == 0) {
			m[number].order = i;
		}
		m[number].count++;
	}
	
	vector<pair<int, info>> v(m.begin(), m.end());
	// 람다함수를 통해 정렬
	sort(v.begin(), v.end(), [](auto& a, auto& b) {
		if (a.second.count != b.second.count) {
			return a.second.count > b.second.count;
		}
		return a.second.order < b.second.order;
	});

	for (pair<int, info> i : v) {
		for (int j = 0; j < i.second.count; j++) {
			cout << i.first << " ";
		}
	}
}