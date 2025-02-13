#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int d_x[4] = {0,0,1,-1};
int d_y[4] = { 1,-1,0,0 };
int bfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited);
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                count++;
                answer.emplace_back(bfs(j, i, map, visited));
            }
        }
    }

    cout << count << "\n";
    sort(answer.begin(), answer.end());
    for (int i : answer)
        cout << i << "\n";
}


int bfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited) {
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({ x,y });
    int c = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dx = x + d_x[i];
            int dy = y + d_y[i];
            if (dx >= 0 && dy >= 0 && dx < N && dy < N && map[dy][dx] == 1 && !visited[dy][dx]) {
                c++;
                q.push({ dx,dy });
                visited[dy][dx] = true;
            }

        }
    }
    return c;
}