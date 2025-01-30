#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) {
        a.insert(a.begin(), b.size() - a.size(), '0');
    }
    else if (b.size() < a.size()){
        b.insert(b.begin(), a.size() - b.size(), '0');
    }

    string a1 = "", b1 = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) {
            a1 += a[i];
        }
        else if (a[i] < b[i]) {
            b1 += b[i];
        }
        else {
            a1 += a[i];
            b1 += b[i];
        }
    }

    while (!a1.empty() && a1[0] == '0' && a1.size() != 1) {
        a1.erase(a1.begin());
    }
    while (!b1.empty() && b1[0] == '0' && b1.size() != 1) {
        b1.erase(b1.begin());
    }

    cout << (a1.empty() ? "YODA" : a1) << "\n";
    cout << (b1.empty() ? "YODA" : b1) << "\n";
}