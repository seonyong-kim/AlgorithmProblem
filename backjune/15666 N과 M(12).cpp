#include <iostream>
#include <map>
#include <vector>
using namespace std;

void bactstrace();
vector<int> answer;
vector<bool> visited(8, false);
map<int, int> numCount;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a;
        numCount[a] = M;
    }

    bactstrace();
}

void bactstrace() {
    if (answer.size() == M) {
        for (int i : answer) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (auto& pair : numCount) {
        int num = pair.first;
        int& count = pair.second;

        if (count > 0) {
            if (answer.empty() || num >= answer[answer.size() - 1]) {
                count--;
                answer.emplace_back(num);
                bactstrace();
                answer.pop_back();
                count++;
            }
        }
    }
}
