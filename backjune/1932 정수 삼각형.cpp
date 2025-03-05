#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = vec.size() - 1; i >= 1; i--) {
        for (int j = 0; j < vec[i].size() - 1; j++) {
            if (vec[i][j] > vec[i][j + 1])
                vec[i - 1][j] += vec[i][j];
            else
                vec[i - 1][j] += vec[i][j + 1];
        }
    }
    cout << vec[0][0];
}

// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5

// 30
// 23 21
// 20 13 10
// 7 12 10 10