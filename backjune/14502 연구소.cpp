#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int y;
    int x;
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    vector<point> empties;
    vector<point> viruses;
    int emptyCount = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] == 0) {
                empties.push_back({ y, x });
                emptyCount++;
            }
            else if (map[y][x] == 2) {
                viruses.push_back({ y, x });
            }
        }
    }

    const int dy[4] = { -1, 1, 0, 0 };
    const int dx[4] = { 0, 0, -1, 1 };
    int best = 0;
    int E = (int)empties.size();

    for (int i = 0; i < E; i++) {
        for (int j = i + 1; j < E; j++) {
            for (int k = j + 1; k < E; k++) {
                vector<vector<int>> tmp = map;
                tmp[empties[i].y][empties[i].x] = 1;
                tmp[empties[j].y][empties[j].x] = 1;
                tmp[empties[k].y][empties[k].x] = 1;

                // 바이러스 퍼뜨리기(BFS)
                queue<point> q;
                for (auto& v : viruses) 
                    q.push(v);

                int infected = 0;
                while (!q.empty()) {
                    int y = q.front().y;
                    int x = q.front().x;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= M) 
                            continue;
                        if (tmp[ny][nx] != 0) 
                            continue; 
                        tmp[ny][nx] = 2;
                        infected++;
                        q.push({ ny, nx });

                        if (emptyCount - 3 - infected <= best) {
                            while (!q.empty()) 
                                q.pop();
                            break;
                        }
                    }
                }

                int safe = emptyCount - 3 - infected;
                if (safe > best) best = safe;
            }
        }
    }
    cout << best << "\n";
}

