#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> vec;

int dfs(int cur, int parent, int banW, int banV) {
    int cnt = 1;
    for (int next : vec[cur]) {
        if ((cur == banW && next == banV) || (cur == banV && next == banW))
            continue;
        if (next == parent) continue;
        cnt += dfs(next, cur, banW, banV);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vec.resize(n + 1);
    for (auto w : wires) {
        vec[w[0]].push_back(w[1]);
        vec[w[1]].push_back(w[0]);
    }

    int answer = n;
    for (auto w : wires) {
        int cnt = dfs(w[0], -1, w[0], w[1]);
        int diff = abs(n - 2 * cnt);
        answer = min(answer, diff);
    }
    return answer;
}