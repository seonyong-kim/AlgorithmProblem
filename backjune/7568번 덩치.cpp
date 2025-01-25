#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> vec;
	vector<int> rank(N,1);

	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;
		vec.emplace_back(weight, height);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j && vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i] << " ";
	}
}

// 88 60 58 55 46