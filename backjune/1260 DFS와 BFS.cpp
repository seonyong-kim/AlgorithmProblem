#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int n, vector<vector<int>> vec, vector<bool>& visited);
void bfs(int n, vector<vector<int>> vec, vector<bool>& visited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V, a, b;
    cin >> N >> M >> V;
    vector<vector<int>> vec(N+1);
    vector<bool> visited(N+1,false);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }

    for (int i = 0; i < vec.size(); i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(V, vec, visited);
    cout << "\n";
    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }
    bfs(V, vec, visited);
}

void dfs(int n, vector<vector<int>> vec, vector<bool>& visited) {
    visited[n] = true;
    cout << n << " ";
    for (int i : vec[n]) {
        if (!visited[i])
            dfs(i, vec, visited);
    }
}

void bfs(int n, vector<vector<int>> vec, vector<bool>& visited) {
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i : vec[x]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}