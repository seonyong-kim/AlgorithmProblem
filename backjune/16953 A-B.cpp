#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A, B;
vector<int> vec;
void bfs(int start, int end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    bfs(A, B);
}

void bfs(int start, int end) {
    vector<bool> visited(B+1, false);
    queue<pair<int, int>> q;
    q.push({start, 1});
    while (!q.empty()) {
        int number = q.front().first;
        int min = q.front().second;
        q.pop();

        if (number == end) {
            cout << min;
            return;
        }

        if (number <= end/2 && !visited[2 * number]) {
            q.push({ 2 * number , min  + 1});
            visited[2 * number] = true;
        }

        if (number <= (end - 1)/10 && !visited[10 * number + 1]) {
            q.push({ 10 * number + 1 , min + 1});
            visited[10 * number + 1, min + 1] = true;
        }
    }
    cout << -1;
}