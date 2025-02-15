#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M, N, x, y, num;
    cin >> T;
    while (T--) {
        cin >> M >> N >> x >> y;

        int max_n, min_n;
        if (M > N) {
            max_n = M;
            min_n = N;
        }
        else {
            max_n = N;
            min_n = M;
        }
        while (max_n % min_n != 0) {
            int temp = max_n % min_n;
            max_n = min_n;
            min_n = temp;
        }
        num = M * N / min_n;

        while (true) {
            if (x < y)
                x += M;
            else if (x > y)
                y += N;
            else {
                cout << x << "\n";
                break;
            }
            if (x > num || y > num) {
                cout << -1 << "\n";
                break;
            }
        }
    }
}

// 3 13 23 33 43 53 63 
// 9 21 33

// 7 17 27 37 47 57
// 2 14 26 38 50 

// 5 18 31 44 57 70 83 
// 6 17 28 39 50 61 72 83


