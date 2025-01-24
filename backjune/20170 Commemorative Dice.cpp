#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		vec1.emplace_back(n);
	}

	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		vec2.emplace_back(n);
	}

	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (vec1[i] > vec2[j])
				count++;
		}
	}

	vector<int> vec3 = {36,18,12,9,6,4,3,2,1};
	int max = 0;
	for (int i : vec3) {
		if (count % i == 0) {
			max = i;
			break;
		}
	}
	cout << count / max << "/" << 36 / max;
}
