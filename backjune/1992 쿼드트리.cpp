#include <iostream>
#include <vector>
using namespace std;

void DAQ(int x, int y, int N, vector<vector<char>>& quadTree) {
    bool result = true;
    char start = quadTree[y][x];
    for (int y1 = y; y1 < y + N; y1++) {
        for (int x1 = x; x1 < x + N; x1++) {
            if (quadTree[y1][x1] != start) {
                result = false;
                break;
            }
        }
        if (!result)
            break;
    }
    if (!result) {
        cout << "(";
        DAQ(x, y, N / 2, quadTree);
        DAQ(x + N / 2, y, N / 2, quadTree);
        DAQ(x, y + N / 2, N / 2, quadTree);
        DAQ(x + N / 2, y + N / 2, N / 2, quadTree);
        cout << ")";
    }
    else {
        cout << start;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<char>> quadTree(N, vector<char>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> quadTree[y][x];
        }
    }

    DAQ(0, 0, N, quadTree);
}
