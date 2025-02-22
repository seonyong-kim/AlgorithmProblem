#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int,int>> q;
int N, M;
void bfs(queue<pair<int, int>> q, vector<vector<int>>& box);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    vector<vector<int>> box(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({ i,j });
            }
        }
    }

    bfs(q, box);
}

void bfs(queue<pair<int, int>> q, vector<vector<int>>& box) {
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    int x = q.front().second;
    int y = q.front().first;
    visited[y][x] = true;
    vector<vector<int>> day(N, vector<int>(M,0));
    int maxDay = 0;
    while (!q.empty()) {
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (!visited[ny][nx] && box[ny][nx] == 0) {
                    q.push({ ny,nx });
                    visited[ny][nx] = true;
                    day[ny][nx] = day[y][x] + 1;
                    maxDay = max(maxDay, day[ny][nx]);
                    box[ny][nx] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return;
            }
        }
    }

    cout << maxDay;
}
