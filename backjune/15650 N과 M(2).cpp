#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
void backtrack(int start);

int main() {
    cin >> N >> M;
    backtrack(1);  
}

void backtrack(int start) {
    if (path.size() == M) {
        for (int num : path) cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        path.push_back(i);
        backtrack(i + 1);
        path.pop_back();
    }
}