#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, x;
    cin >> M;
    string str;
    unordered_set<int> s;
    while (M--) {
        cin >> str;
        if (str == "add") {
            cin >> x;
            s.insert(x);
        }
        else if (str == "remove") {
            cin >> x;
            s.erase(x);
        }
        else if (str == "check") {
            cin >> x;
            cout << (s.find(x) == s.end() ? "0\n" : "1\n");
                
        }
        else if (str == "toggle") {
            cin >> x;
            if (s.find(x) == s.end())
                s.insert(x);
            else
                s.erase(x);
        }
        else if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                s.insert(i);
            }
        }
        else if (str == "empty") {
            s.clear();
        }
    }
}
