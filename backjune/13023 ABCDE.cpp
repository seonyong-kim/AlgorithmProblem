#include <iostream>
#include <vector>

using namespace std;

void DFS(int n, int depth, vector<bool>& visited, vector<vector<int>>& vec, bool& result);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool arrived = false;
    vector<vector<int>> vec(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1, visited, vec, arrived);
        if (arrived) break;
    }

    if (arrived)  cout << 1;
    else  cout << 0;
}

void DFS(int n, int depth, vector<bool>& visited, vector<vector<int>>& vec, bool& result) {
    if (depth == 5 || result) {
        result = true;
        return;
    }

    visited[n] = true;

    for (int i : vec[n]) {
        if (!visited[i]) {
            DFS(i, depth + 1, visited, vec, result);
        }
    }

    visited[n] = false;
}
