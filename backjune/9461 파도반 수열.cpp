#include <iostream>
#include <vector>

using namespace std;

vector<long long> calculate();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<long long> dp = calculate();
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n - 1] << "\n";
    }
}

vector<long long> calculate() {
    vector<long long> dp(100);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 5; i < 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    return dp;
}
