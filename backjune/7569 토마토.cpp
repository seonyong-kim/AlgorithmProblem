#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int M, N, H;
struct Point {
    int x, y, z, day;
};
queue<Point> q;
void bfs(vector<vector<vector<int>>>& vec);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    vector<vector<vector<int>>> vec(H, vector<vector<int>>(N, vector<int>(M)));
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> vec[h][n][m]; 
                if (vec[h][n][m] == 1)
                    q.push({ m,n,h,0 });
            }
        }
    }

    bfs(vec);
}

void bfs(vector<vector<vector<int>>>& vec) {
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M, false)));
    visited[q.front().z][q.front().y][q.front().x] = true;
    int maxDay = 0;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int day = q.front().day;
        q.pop();

        maxDay = max(maxDay, day);
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && !visited[nz][ny][nx] && vec[nz][ny][nx] == 0) {
                q.push({ nx, ny, nz, day +1 });
                vec[nz][ny][nx] = 1;
                visited[nz][ny][nx] = true;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (vec[h][n][m] == 0) {
                    cout << -1;
                    return;
                }
            }
        }
    }
    cout << maxDay;
}