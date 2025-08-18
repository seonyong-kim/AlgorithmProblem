#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> buildingBuiltTime(N + 1);
        vector<int> nextStruct(N + 1);     
        vector<int> indegree(N + 1, 0);
        vector<vector<int>> adj(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> buildingBuiltTime[i];
            nextStruct[i] = buildingBuiltTime[i]; 
        }

        for (int i = 0; i < K; i++) {
            int pre, nxt;
            cin >> pre >> nxt;
            adj[pre].push_back(nxt);
            indegree[nxt]++;
        }

        int answer;
        cin >> answer;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                nextStruct[nxt] = max(nextStruct[nxt], nextStruct[cur] + buildingBuiltTime[nxt]);
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        cout << nextStruct[answer] << "\n";
    }
}

