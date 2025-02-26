#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> root;
void dfs(int start, vector<vector<int>>& tree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int a, b;
    vector<vector<int>> tree(N + 1);
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    dfs(1, tree);

    for (int i = 2; i <= N; i++) {
        cout << root[i] << "\n";
    }
}

void dfs(int start, vector<vector<int>>& tree) {
    root.assign(N + 1, 0);
    vector<bool> visited(N + 1,false);
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i : tree[front]) {
            if (!visited[i]){
                q.push(i);
                visited[i] = true;
                root[i] = front;
        }
        }
    }
}

// 1 6 3 5 
//   4 2 7