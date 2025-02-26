#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> dp;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        dp.emplace_back(num, 1);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[i].first > dp[j].first) {
                dp[i].second = max(dp[i].second, dp[j].second + 1);
            }
        }
    }
    
    int maxLTS = 0;
    for (int i = 0; i < N; i++) {
        maxLTS = max(maxLTS, dp[i].second);
    }

    cout << maxLTS;
}

// 40 10 30 20 50
// 20 30 10 50
// 1 10 2 3