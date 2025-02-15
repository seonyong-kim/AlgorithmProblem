#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string str;
    cin >> N >> M;
    map<string, int> m1;
    map<int, string> m2;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        m1[str] = i;
        m2[i] = str;
    }

    while (M--) {
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9') 
            cout << m2[stoi(str)] << "\n";
        else {
            cout << m1[str] << "\n";
        }
    }
}