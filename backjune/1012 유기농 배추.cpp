#include <iostream>
#include <vector>
using namespace std;

int M, N, K;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, const vector<vector<int>> land, vector<vector<bool>>& visited) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (land[ny][nx] == 1) {
            dfs(nx, ny, land, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int answer = 0;
        cin >> M >> N >> K;
        vector<vector<int>> land(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int x, y;
        while (K--) {
            cin >> x >> y;
            land[y][x] = 1;
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (land[y][x] == 1 && visited[y][x] == false) {
                    answer++;
                    dfs(x, y, land, visited);
                }
            }
        }

        cout << answer << "\n";
    }
}