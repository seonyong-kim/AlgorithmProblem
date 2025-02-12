#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int N, int K, vector<int>& vec, vector<bool>& visited);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> vec(100001);
	vector<bool> visited(100001, false);
	vec[N] = 0;
	bfs(N, K, vec, visited);
	cout << vec[K];
}

void bfs(int N, int K, vector<int>& vec, vector<bool>& visited) {
	visited[N] = true;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		if (!visited[f - 1] && f != 0) {
			q.push(f - 1);
			visited[f - 1] = true;
			vec[f - 1] = vec[f] + 1;
			if (f - 1 == K)
				break;
		}
		if (!visited[f + 1] && f + 1 <= 100000) {
			q.push(f + 1);
			visited[f + 1] = true;
			vec[f + 1] = vec[f] + 1;
			if (f + 1 == K)
				break;
		}
		if (!visited[2 * f] && 2 * f <= 100000) {
			q.push(2 * f);
			visited[2 * f] = true;
			vec[2 * f] = vec[f] + 1;
			if (2 * f == K)
				break;
		}
	}
}