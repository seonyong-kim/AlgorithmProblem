#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int maxDp[2][3], minDp[2][3];
    cin >> maxDp[0][0] >> maxDp[0][1] >> maxDp[0][2];

    minDp[0][0] = maxDp[0][0];
    minDp[0][1] = maxDp[0][1];
    minDp[0][2] = maxDp[0][2];

    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        maxDp[1][0] = max(maxDp[0][0], maxDp[0][1]) + a;
        maxDp[1][1] = max({ maxDp[0][0], maxDp[0][1], maxDp[0][2] }) + b;
        maxDp[1][2] = max(maxDp[0][1], maxDp[0][2]) + c;

        minDp[1][0] = min(minDp[0][0], minDp[0][1]) + a;
        minDp[1][1] = min({ minDp[0][0], minDp[0][1], minDp[0][2] }) + b;
        minDp[1][2] = min(minDp[0][1], minDp[0][2]) + c;

        swap(maxDp[0], maxDp[1]);
        swap(minDp[0], minDp[1]);
    }

    cout << max({ maxDp[0][0], maxDp[0][1], maxDp[0][2] }) << " "
        << min({ minDp[0][0], minDp[0][1], minDp[0][2] }) << "\n";
}


