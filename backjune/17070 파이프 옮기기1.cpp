#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> room(N, vector<int>(N));
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3, 0)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> room[i][j];
        }
    }
    dp[0][1][0] = 1;

    for (int y = 0; y < N; y++) {
        for (int x = 1; x < N; x++) {
            if (room[y][x] == 1) 
                continue;

            // 가로 이동 (0)
            if (x > 0 && room[y][x - 1] == 0) {
                dp[y][x][0] += dp[y][x - 1][0] + dp[y][x - 1][2];
            }

            // 세로 이동 (1)
            if (y > 0 && room[y - 1][x] == 0) {
                dp[y][x][1] += dp[y - 1][x][1] + dp[y - 1][x][2];
            }

            // 대각선 이동 (2)
            if (x > 0 && y > 0 && room[y - 1][x] == 0 && room[y][x - 1] == 0 && room[y - 1][x - 1] == 0) {
                dp[y][x][2] += dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
            }
        }
    }
    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
}