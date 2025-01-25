#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		q.push(i+1);
	}
	int answer = 1;
	while (true) {
		if (q.size() == 1)
			break;
		q.pop();
		answer = q.front();
		q.push(answer);
		q.pop();
	}
	cout << answer;
}