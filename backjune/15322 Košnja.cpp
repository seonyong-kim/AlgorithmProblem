#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    while (k--) {
        int n,m;
        cin >> n >> m;
        int min = (n > m ? m : n);
        cout << 2 * (min - 1) << "\n";
    }
}
