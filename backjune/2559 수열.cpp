#include<iostream> 
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> sum(N);
	for (int i = 0; i < N; i++) {
		cin >> sum[i];
		if (i != 0)
			sum[i] += sum[i - 1];
	}

	int max = sum[K - 1];
	for (int i = 0; i < N - K; i++) {
		if (max < sum[i + K] - sum[i])
			max = sum[i + K] - sum[i];
	}

	cout << max;
}