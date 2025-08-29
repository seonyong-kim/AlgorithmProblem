#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct save {
    int stage; // ��� �ܰ迡�� 0�� ����� 
    bool visited; // �湮 ���� Ȯ��
};

int N, M;
int dx[4] = { 0,0, 1, -1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> changePoint; // ����� ��ǥ�� �����ϴ� ť

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

    int stage = 0, pointNumber = 0; // �ܰ�� �� ������ �ܰ��� ���� �ľ��� ���� ����

    // bfs�� �ܺ� 0�� 1�� �� �� �ִ� ���� Ȯ��
    // �Ƹ� ��ǥ�� �����ϰ���(���� �ľ� -> ��� ����)
    // 1�� 0���� �ٲ� �ش�.(�ܰ� ����)
    // ���� �ݺ�
    while (true) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                s[y][x].visited = false; // �ʱ�ȭ �ϴ� ������ ������ �ٲ�� ����
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
