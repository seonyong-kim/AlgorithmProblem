#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        vector<int> vec(k);
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            cin >> vec[i];
            if (i == 0)
                vec[i] == 1 ? answer.emplace_back(2) : answer.emplace_back(1);
            else {
                (answer[i - 1] + 1) != vec[i] ? answer.emplace_back(answer[i - 1] + 1) :
                    answer.emplace_back(answer[i - 1] + 2);
            }
        }
        cout << answer[answer.size() - 1] << "\n";
    }
}