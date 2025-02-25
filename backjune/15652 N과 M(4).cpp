#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
void backtrack(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    backtrack(1);  
}

void backtrack(int start) {
    if (path.size() == M) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        path.emplace_back(i);
        backtrack(i);
        path.pop_back();
    }
}