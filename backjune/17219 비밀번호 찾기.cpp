#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string web, password;
    cin >> N >> M;
    map<string, string> m;
    while (N--) {
        cin >> web >> password;
        m.insert({ web , password });
    }
    while (M--) {
        cin >> web;
        cout << m[web] << "\n";
    }
}
