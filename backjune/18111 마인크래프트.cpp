#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;
    vector<vector<int>> vec(N, vector<int>(M));
    int max = 0, min = 256;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
            if (max < vec[i][j])     max = vec[i][j];
            if (min > vec[i][j])     min = vec[i][j];
        }
    }

    vector<pair<int, int>> answer;
    for (int a = min; a <= max; a++) {
        int time = 0;
        int Block = B;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int c = vec[i][j] - a;
                if (c < 0) {
                    time += 1 * -c;
                    Block += c;
                }
                else if (c > 0) {
                    time += 2 * c;
                    Block += c;
                }
            }
        }
        answer.emplace_back(time, Block);
    }

    int timeMin = INT_MAX;
    int height = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i].second >= 0 && timeMin >= answer[i].first) {
            timeMin = answer[i].first;
            height = min + i;
        }
    }

    cout << timeMin << " " << height;
}