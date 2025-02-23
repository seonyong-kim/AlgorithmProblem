#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int>& board);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int start, end;
    vector<int> board(101);
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    while (N--) {
        cin >> start >> end;
        board[start] = end;
    }

    while (M--) {
        cin >> start >> end;
        board[start] = end;
    }
    board[1] = 0;

    bfs(board);
}

void bfs(vector<int>& board) {
    vector<bool> visited(101, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1,0});

    while (!q.empty()) {
        int pos = q.front().first;
        int count = q.front().second;
        q.pop();
        if (pos == 100) {
            cout << count;
            return;
        }
        for (int i = 1; i <= 6; i++) {
            int newN = pos + i;
            if (newN > 100 || visited[newN])
                continue;
            visited[newN] = true;
            q.push({ board[newN], count + 1 });
        }
    }
}