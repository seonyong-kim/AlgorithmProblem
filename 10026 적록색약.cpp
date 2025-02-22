#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;
void dfs(int x, int y, vector<vector<char>>& vec, vector<vector<bool>>& visited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<char>> vec(N,vector<char>(N));
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec[i][j];
        }
    }

    int count1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(j, i, vec, visited);
                count1++;
            }
        }
    }

    int count2 = 0;
    visited.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(j, i, vec, visited);
                count2++;
            }
        }
    }
    cout << count1 << " " << count2;
}

void dfs(int x, int y, vector<vector<char>>& vec, vector<vector<bool>>& visited){
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (!visited[ny][nx] && vec[ny][nx] == vec[y][x])
            dfs(nx, ny, vec, visited);
    }

    if (vec[y][x] == 'G') 
            vec[y][x] = 'R';
}