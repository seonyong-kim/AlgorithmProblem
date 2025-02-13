#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, answer = "";
    cin >> s;

    int i = s.size() - 2;
    while (true) {
        int a = 0;
        if (i >= -1) {
            if (s[i + 1] == '1') {
                a += 1;
            }
        }
        if (i >= 0) {
            if (s[i] == '1') {
                a += 2;
            }
        }
        if (i >= 1) {
            if (s[i - 1] == '1') {
                a += 4;
            }
        }
        answer += to_string(a);
        if (i <= 1)
            break;
        i -= 3;
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i];
    }
}