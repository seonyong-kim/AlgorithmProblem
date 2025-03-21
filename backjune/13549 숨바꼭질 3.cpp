#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int>& vec, int maxSize);
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> K;
    int maxSize = max(2 * K, N) + 1;
    vector<int> vec(maxSize, 100001);
    vec[N] = 0;

    bfs(vec, maxSize);
}

void bfs(vector<int>& vec, int maxSize) {
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) {
            cout << vec[K];
            return;
        }

        if (now + 1 < maxSize) {
            if ((vec[now] + 1) < vec[now + 1]) {
                q.push(now + 1);
                vec[now + 1] = vec[now] + 1;
            }
        }

        if (now - 1 >= 0) {
            if ((vec[now] + 1) < vec[now - 1]) {
                q.push(now - 1);
                vec[now - 1] = vec[now] + 1;
            }
        }

        if (2 * now < maxSize) {
            if (vec[now] < vec[2 * now]) {
                q.push(2 * now);
                vec[2 * now] = vec[now];
            }
        }
    }
}