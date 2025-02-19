#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> answer;
vector<vector<int>> vec;
vector<bool> visited;

void dfs(int start, int node) {
    for (int next = 0; next < N; next++) {
        if (vec[node][next] == 1 && !visited[next]) {
            visited[next] = true;
            answer[start][next] = 1;
            dfs(start, next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vec.assign(N, vector<int>(N, 0));
    answer.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        visited.assign(N, false);
        dfs(i, i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
