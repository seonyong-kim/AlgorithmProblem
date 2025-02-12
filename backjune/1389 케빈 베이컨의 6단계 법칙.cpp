#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<int>>& friends, vector<bool>& visited);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b;
	cin >> N >> M;
	vector<vector<int>> friends(N+1);
	vector<bool> visited(N + 1, false);
	while (M--) {
		cin >> a >> b;
		friends[a].emplace_back(b);
		friends[b].emplace_back(a);
	}

	int answer = 0;
	int min = 5001;
	for (int i = 1; i <= N; i++) {
		int kevin = bfs(i, friends, visited);
		if (min > kevin) {
			min = kevin;
			answer = i;
		}
	}
	cout << answer;
}

int bfs(int n, vector<vector<int>>& friends, vector<bool>& visited) {
	visited.assign(friends.size(), false);
	vector<int> dist(friends.size(), 0);
	visited[n] = true;
	int sum = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i : friends[a]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				dist[i] = dist[a] + 1;
				sum += dist[i];
			}
		}
	}
	return sum;
}