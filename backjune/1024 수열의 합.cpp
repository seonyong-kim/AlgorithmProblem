#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    // a ½ÃÀÛ k°³ -> ka + k(k-1)/2 = N
    int start;
    for (int k = L; k <= 100; k++) {
        if (((N - k * (k - 1) / 2) % k) == 0 && (N - k * (k - 1) / 2) >= 0) {
            start = (N - k * (k - 1) / 2) / k;
            for (int i = 0; i < k; i++) {
                cout << start + i << " ";
            }
            return 0;
        }
    }
    cout << -1;
}
