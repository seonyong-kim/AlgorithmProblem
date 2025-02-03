#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> vec(1001);
    vec[1] = 1;
    vec[2] = 2;
    for (int i = 3; i <= n; i++) {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 10007;
    }
    cout << vec[n];
}
// 1 2 3 5 8 13