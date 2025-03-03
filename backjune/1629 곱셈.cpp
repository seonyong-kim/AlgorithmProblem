#include <iostream>
using namespace std;

long long power(long long A, long long B, long long C);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C);
}

long long power(long long A, long long B, long long C) {
    if (B == 0)
        return 1;
    long long half = power(A, B / 2, C);
    long long result = half * half;

    if (B % 2 != 0)
        result *= A;

    return result % C;
}