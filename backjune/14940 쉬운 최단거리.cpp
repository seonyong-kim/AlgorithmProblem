#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
void bfs(pair<int, int>, vector<vector<int>>&, vector<vector<bool>>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> start;
    cin >> n >> m;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 2) {
                start = { i,j };
            }
        }
    }

    bfs(start, vec, visited);
}

void bfs(pair<int, int> start, vector<vector<int>>& vec, vector<vector<bool>>& visited) {
    int y = start.first;    int x = start.second;
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    int c = 1;
    vector<vector<int>> map(n, vector<int>(m,0));
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int mx = nx + dx[i];
            int my = ny + dy[i];

            if (mx >=0 && mx < m && my >=0 && my < n) {
                if (!visited[my][mx] && vec[my][mx] == 1) {
                    q.push({ mx, my });
                    visited[my][mx] = true;
                    map[my][mx] = map[ny][nx] + 1;
                }
            }
        }
        c++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 1 && !visited[i][j])
                cout << "-1 ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
// 4 4
// 2 1 1 1
// 1 1 0 0
// 1 1 0 1
// 1 1 0 0
// 
// 0 1 2 3
// 1 2 0 0
// 2 3 0 -1
// 3 4 0 0
// 
// 0 1 2 3
// 1 2 3 0
// 2 3 4 5
// 3 0 5 6