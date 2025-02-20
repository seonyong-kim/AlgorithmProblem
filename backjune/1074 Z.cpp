#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void check(int, int ,int, int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c;

    check(pow(2,N), r, c, 0);
}

void check(int n, int r, int c, int cnt) {
    if (n == 1) {
        cout << cnt;
        return;
    }

    int half = n / 2;
    int size = half * half;

    if (r < half && c < half) { 
        check(half, r, c, cnt);
    }
    else if (r < half && c >= half) { 
        check(half, r, c - half, cnt + size);
    }
    else if (r >= half && c < half) { 
        check(half, r - half, c, cnt + 2 * size);
    }
    else { 
        check(half, r - half, c - half, cnt + 3 * size);
    }
}