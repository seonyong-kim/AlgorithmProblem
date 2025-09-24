#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& used, int cnt) {
    answer = max(answer, cnt);
    for (int i = 0; i < dungeons.size(); i++) {
        if (used[i]) continue;
        if (k < dungeons[i][0]) continue;
        used[i] = true;
        dfs(k - dungeons[i][1], dungeons, used, cnt + 1);
        used[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> used(dungeons.size(), false);
    dfs(k, dungeons, used, 0);
    return answer;
}