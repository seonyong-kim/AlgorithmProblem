#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int start, finish;
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> start >> finish;
        bfs();
    }
}

void bfs() {
    vector<bool> visited(10000, false);
    visited[start] = true;
    queue<pair<int, string>> q;
    q.push({ start, "" });
    
    while (!q.empty()) {
        int n = q.front().first;
        string s = q.front().second;
        q.pop();

        if (n == finish) {
            cout << s << "\n";
            return;
        }

        if (!visited[(2 * n) % 10000]) {
            visited[(2 * n) % 10000] = true;
            q.push({ (2 * n) % 10000, s + "D" });
        }

        int changeS = ((n == 0) ? 9999 : n - 1);
        if (!visited[changeS]) {
            visited[changeS] = true;
            q.push({ changeS, s + "S" });
        }

        int changeL = (n * 10) % 10000 + (n / 1000);
        if (!visited[changeL]) {
            visited[changeL] = true;
            q.push({ changeL, s + "L" });
        }

        int changeR = (n % 10) * 1000 + n / 10;
        if (!visited[changeR]) {
            visited[changeR] = true;
            q.push({ changeR, s + "R" });
        }
    }
}