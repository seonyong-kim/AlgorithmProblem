#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> bag(N);
    for (int i = 0; i < N; i++) {
        cin >> bag[i].first >> bag[i].second;
    }

    vector<int> dp(K + 1, 0);
    for (int i = 0; i < N; i++) {
        int weight = bag[i].first, value = bag[i].second;

        for (int w = K; w >= weight; w--) {
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    }

    cout << dp[K] << endl;
}