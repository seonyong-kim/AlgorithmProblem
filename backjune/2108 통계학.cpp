#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
    }
    double r1 = round(sum / vec.size());
    if (r1 == -0) r1 = 0;

    int r2 = vec[vec.size() / 2];

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[vec[i]]++;
    }

    vector<int> modes;
    int maxCount = 0;
    for (auto& pair : count) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            modes = { pair.first };
        }
        else if (pair.second == maxCount) {
            modes.push_back(pair.first);
        }
    }
    sort(modes.begin(), modes.end());
    int r3 = (modes.size() > 1) ? modes[1] : modes[0];

    int r4 = vec[vec.size() - 1] - vec[0];
    cout << r1 << "\n" << r2 << "\n" << r3 << "\n" << r4;

    return 0;
}
