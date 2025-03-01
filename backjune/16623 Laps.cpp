#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> answer;
    int count;
    while (m--) {
        cin >> count;
        answer.emplace_back(count);
    }

    count = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (i != 0 && answer[i] < answer[i - 1]) {
            count++;
        }
    }
    cout << count;
}