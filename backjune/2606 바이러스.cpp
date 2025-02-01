#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, vector<bool>& visited, vector<vector<int>>& computer);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec;
    int numberOfComputer, connect, a, b;
    cin >> numberOfComputer >> connect;

    vector<bool> visited(numberOfComputer);
    vector<vector<int>> computer(numberOfComputer);

    while (connect--) {
        cin >> a >> b;
        computer[a - 1].emplace_back(b - 1);
        computer[b - 1].emplace_back(a - 1);
    }

    dfs(0, visited, computer);
    int sum = 0;
    for (int i = 0; i < visited.size(); i++) {
        sum += (visited[i] ? 1 : 0);
    }
    cout << sum - 1;
}

void dfs(int x, vector<bool>& visited, vector<vector<int>>& computer) {
    visited[x] = true;

    for (int i = 0; i < computer[x].size(); i++) {
        int y = computer[x][i];
        if (!visited[y])
            dfs(y, visited, computer);
    }
}