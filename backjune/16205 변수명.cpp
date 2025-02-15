#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;
    cin >> N >> str;

    for (int i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] >= 'A' && str[i] <= 'Z') {
            cout << (char)(str[i] + 32);
            continue;
        }
        if (str[i] == '_') {
            cout << (char)(str[i + 1] - 32);
            i++;
            continue;
        }
        cout << str[i];
    }
    cout << "\n";

    for (int i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] >= 'A' && str[i] <= 'Z') {
            cout << (char)(str[i] + 32);
            continue;
        }
        if (i != 0 && str[i] >= 'A' && str[i] <= 'Z') {
            cout << "_" << (char)(str[i] + 32);
            continue;
        }
        cout << str[i];
    }
    cout << "\n";

    for (int i = 0; i < str.size(); i++) {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z') {
            cout << (char)(str[i] - 32);
            continue;
        }
        if (str[i] == '_') {
            cout << (char)(str[i + 1] - 32);
            i++;
            continue;
        }
        cout << str[i];
    }
}