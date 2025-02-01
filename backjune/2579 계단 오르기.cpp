#include <iostream>
#include <vector>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    if (n == 1) {
        cout << score[0];
        return 0;
    }
    vector<int> dp(n);
    dp[0] = score[0];
    dp[1] = score[0] + score[1];
    if (n > 2) {
        dp[2] = max(dp[0] + score[2], score[1] + score[2]);
    }
    for (int i = 3; i < n; i++) {
        dp[i] = max(score[i] + score[i - 1] + dp[i-3], score[i] + dp[i - 2]);
    }
    cout << dp[n-1];
}
