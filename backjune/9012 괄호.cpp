#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        queue<char> q;
        for (int i = 0; i < str.size(); i++) {
            if (q.empty()) {
                q.push(str[i]);
            }
            else {
                if (str[i] == ')' && q.front() == '(') {
                    q.pop();
                }
                else {
                    q.push(str[i]);
                }
            }
        }
        if (q.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
