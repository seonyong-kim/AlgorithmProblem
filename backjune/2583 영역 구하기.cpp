#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int M, N, K;

int dfs(int x, int y, vector<vector<int>>& vec, vector<vector<int>>& visited, int s) {
    visited[y][x]++;
    s++;
    if (s < visited[y][x]) {
        s = visited[y][x];
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[ny][nx] != 0) continue;
        if (vec[ny][nx] == 0) {
            s = dfs(nx, ny, vec, visited, s);
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N >> K;

    vector<vector<int>> vec(M, vector<int>(N, 0));
    vector<vector<int>> visited(M, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                vec[y][x] = 1;
            }
        }

    }

    vector<int> sizeList;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            int s = 0;
            if (vec[y][x] == 0 && visited[y][x] == 0) {
                s = dfs(x, y, vec, visited, s);
                sizeList.push_back(s);
            }
        }
    }

    sort(sizeList.begin(), sizeList.end());
    cout << sizeList.size() << "\n";
    for (int i : sizeList) {
        cout << i << " ";
    }
}