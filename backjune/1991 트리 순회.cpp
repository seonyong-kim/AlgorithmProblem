#include <iostream>
#include <vector>
using namespace std;

void predfs(int start, vector<vector<int>>& vec);
void inorder(int start, vector<vector<int>>& vec);
void postdfs(int start, vector<vector<int>>& vec);
vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    char a, b, c;
    vector<vector<int>> vec(26);
    visited.assign(N, false);

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        if (b != '.')
            vec[a - 'A'].emplace_back(b - 'A');
        else
            vec[a - 'A'].emplace_back(-1);
        if (c != '.')
            vec[a - 'A'].emplace_back(c - 'A');
        else
            vec[a - 'A'].emplace_back(-1);
    }

    predfs(0, vec);
    cout << "\n"; 

    visited.assign(N, false);
    inorder(0, vec);
    cout << "\n";

    visited.assign(N, false);
    postdfs(0, vec);
}

void predfs(int start, vector<vector<int>>& vec) {
    visited[start] = true;
    cout << (char)(start + 'A');

    for (int c : vec[start]) {
        if (c != -1 && !visited[c]) {
            predfs(c, vec);
        }
    }
}

void inorder(int start, vector<vector<int>>& vec) {
    visited[start] = true;
    if (vec[start][0] != -1) {
        inorder(vec[start][0], vec);
    }

    cout << (char)(start + 'A');

    if (vec[start][1] != -1) {
        inorder(vec[start][1], vec);
    }
}

void postdfs(int start, vector<vector<int>>& vec) {
    visited[start] = true;
    for (int c : vec[start]) {
        if (c != -1 && !visited[c]) {
            postdfs(c, vec);
        }
    }

    cout << (char)(start + 'A');
}

// ÀüÀ§ -> dfs
// 