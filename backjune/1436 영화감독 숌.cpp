#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int i = 666;
    for (;; i++) {
        if (to_string(i).find("666") != string::npos) {
            N--;
        }
        if (N == 0) {
            cout << i;
            return 0;
        }
    }

}
