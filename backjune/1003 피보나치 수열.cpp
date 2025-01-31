#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> fibonacci(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<long long, long long>> count = fibonacci(N);
        cout << count[N].first << " " << count[N].second << "\n";
    }

}

vector<pair<long long, long long>> fibonacci(int n) {
    vector<pair<long long, long long>> dp(n+1);
    if (n == 0) {
        dp[0].first++;
        return dp;
    }
    else if (n == 1) {
        dp[1].second++;
        return dp;
    }
    dp[0].first++;
    dp[1].second++;
    for (int i = 2; i <= n; i++) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    return dp;
}