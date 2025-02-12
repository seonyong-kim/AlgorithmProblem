#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int d_x[4] = { 0, 0, -1, 1 };  
int d_y[4] = { 1, -1, 0, 0 };  
vector<vector<int>> maze;
vector<vector<bool>> visited;

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startY][startX] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + d_x[i];
            int ny = y + d_y[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && maze[ny][nx] == 1) {
                q.push({ nx, ny });
                visited[ny][nx] = true;
                maze[ny][nx] = maze[y][x] + 1;  
            }
        }
    }

    return maze[N - 1][M - 1];  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    maze.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';  
        }
    }

    cout << bfs(0, 0);  
}
