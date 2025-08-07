#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;

void dfs(int y, int x, int h, vector<vector<int>>& vec, vector<vector<bool>>& visited) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[ny][nx] == true) continue;
        if (vec[ny][nx] > h) {
            dfs(ny, nx, h, vec, visited);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<vector<int>> vec(N, vector<int>(N));
    int max = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> vec[y][x];
            if (vec[y][x] > max) {
                max = vec[y][x];
            }
        }
    }

    int maxAnswer = 0;
    for (int h = 0; h < max; h++) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int answer = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (vec[y][x] > h && visited[y][x] == false) {
                    answer++;
                    dfs(y, x, h, vec, visited);
                }
            }
        }
        if (maxAnswer < answer) {
            maxAnswer = answer;
        }
    }
    cout << maxAnswer;
}