#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> alphabet(26, 0);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i] == 'a' + j) {
                alphabet[j]++;
            }
        }
    }

    for (int i : alphabet)
        cout << i << " ";
}