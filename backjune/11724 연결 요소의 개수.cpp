#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>>& vec, vector<bool>& visited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b, count = 0;
    cin >> N >> M;
    vector<vector<int>> vec(N + 1);
    vector<bool> visited(N + 1, false);
    while (M--) {
        cin >> a >> b;
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }


    for (int i = 1; i < N + 1; i++) {
        if (visited[i] == false) {
            dfs(i, vec, visited);
            count++;
        }
    }

    cout << count;
}

void dfs(int n, vector<vector<int>>& vec, vector<bool>& visited) {
    visited[n] = true;

    for (int i : vec[n]) {
        if(!visited[i])
            dfs(i, vec, visited);
    }
}