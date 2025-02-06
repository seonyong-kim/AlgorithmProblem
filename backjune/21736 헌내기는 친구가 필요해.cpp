#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, M, I_x, I_y;
void dfs(int x, int y, vector<vector<char>>& space, vector<vector<bool>>& visited, int& count);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    char k;
    vector<vector<char>> space(N,vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> k;
            space[i][j] = k;
            if (k == 'I') {
                I_x = j;
                I_y = i;
            }
        }
    }
    int count = 0;
    dfs(I_y, I_x, space, visited, count);
    if (count == 0)
        cout << "TT";
    else
        cout << count;
}

void dfs(int y, int x, vector<vector<char>>& space, vector<vector<bool>>& visited, int& count) {
    visited[y][x] = true;
    if (space[y][x] == 'P')
        count++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) { 
            if (space[ny][nx] != 'X' && !visited[ny][nx]) {
                dfs(ny, nx, space, visited, count);
            }
        }
    }
}