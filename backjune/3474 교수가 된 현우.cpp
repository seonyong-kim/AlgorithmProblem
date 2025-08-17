#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	while (T--) {
		int answer = 0;
		cin >> N;
		while (N > 0) {
			answer += (N / 5);
			N /= 5;
		}
		cout << answer << "\n";
	}
}
