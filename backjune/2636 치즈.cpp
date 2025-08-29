#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct save {
    int stage; // 어느 단계에서 0이 됬는지 
    bool visited; // 방문 여부 확인
};

int N, M;
int dx[4] = { 0,0, 1, -1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> changePoint; // 변경될 좌표를 저장하는 큐

void bfs(int y, int x, vector<vector<int>>& ch, vector<vector<save>>& s) {
    s[y][x].visited = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N || s[ny][nx].visited == true)
            continue;

        if (ch[ny][nx] == 1) {
            changePoint.push({ ny,nx });
            s[ny][nx].stage = s[y][x].stage + 1;
            s[ny][nx].visited = true;
        }

        if (ch[ny][nx] == 0) {
            bfs(ny, nx, ch, s);
        }
            
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> ch(N, vector<int>(M));
    vector<vector<save>> s(N, vector<save>(M)); 
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> ch[y][x];
            if (ch[y][x] == 0) 
                s[y][x].stage = 0;
        }
    }

    int stage = 0, pointNumber = 0; // 단계와 각 마지막 단계전 개수 파악을 위한 변수

    // bfs로 외부 0과 1로 갈 수 있는 곳을 확인
    // 아마 좌표로 정리하겠지(개수 파악 -> 계속 갱신)
    // 1을 0으로 바꿔 준다.(단계 증가)
    // 위를 반복
    while (true) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                s[y][x].visited = false; // 초기화 하는 이유는 지형이 바뀌기 때문
            }
        }

        bfs(0, 0, ch, s);

        if (changePoint.empty())
            break;

        pointNumber = changePoint.size();

        while (!changePoint.empty()) {
            int y = changePoint.front().first;
            int x = changePoint.front().second;
            ch[y][x] = 0;
            s[y][x].visited = false;
            changePoint.pop();
        }
        stage++;
    }

    cout << stage << "\n" << pointNumber;
}
