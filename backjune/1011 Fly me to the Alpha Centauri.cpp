#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;

        int diff = y - x;
        int k = sqrt(diff);
        if (diff <= k * k) {
            cout << 2 * k - 1 << "\n";
        }
        else if (diff <= k * k + k) {
            cout << 2 * k << "\n";
        }
        else {
            cout << 2 * k + 1 << "\n";
        }
    }
}