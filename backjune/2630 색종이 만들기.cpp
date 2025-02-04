#include <iostream>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& paper, int x, int y, int size);
void count(vector<vector<int>>& paper, int x, int y, int size);

int white = 0;
int blue = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    count(paper, 0, 0, N);
    cout << white << "\n" << blue;
}

bool check(vector<vector<int>>& paper, int x, int y, int size) {
    int color = paper[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color)
                return false;
        }
    }
    return true;
}

void count(vector<vector<int>>& paper, int x, int y, int size){
    if (check(paper, x, y, size)) {
        paper[x][y] == 0 ? white++ : blue++;
        return;
    }

    size = size / 2;
    count(paper, x, y, size);
    count(paper, x, y + size, size);
    count(paper, x + size, y, size);
    count(paper, x + size, y + size, size);
}
