#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n1, n2;
    cin >> N >> M;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        if (i > 0)
            vec[i] += vec[i - 1];
    }
    
    while (M--) {
        cin >> n1 >> n2;
        if (n1 == 1)
            cout << vec[n2 - 1] << '\n';
        else
            cout << vec[n2 - 1] - vec[n1 - 2] << "\n";
    }
}