#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_distance(pair<int, int> a, pair<int, int> b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N));
    vector<pair<int, int>> home;
    vector<pair<int, int>> chicken;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                home.emplace_back(j, i);
            if (map[i][j] == 2)
                chicken.emplace_back(j, i);
        }
    }

    vector<int> comb(chicken.size(), 0);
    fill(comb.end() - M, comb.end(), 1);
    int min_distance = 1e9;
    do {
        int city_distance = 0;

        for (auto h : home) {
            int home_x = h.first;
            int home_y = h.second;
            int min_home_distance = 1e9;

            for (int i = 0; i < chicken.size(); i++) {
                if (comb[i] == 1) { 
                    int chicken_x = chicken[i].first;
                    int chicken_y = chicken[i].second;
                    min_home_distance = min(min_home_distance, get_distance(h, chicken[i]));
                }
            }
            city_distance += min_home_distance;
        }

        min_distance = min(min_distance, city_distance);

    } while (next_permutation(comb.begin(), comb.end()));

    cout << min_distance;
}

int get_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}