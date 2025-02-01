#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, kind;
    cin >> n;
    while (n--) {
        map <string, vector<string>> object;
        cin >> kind;
        while (kind--) {
            string str1, str2;
            cin >> str1 >> str2;
            object[str2].emplace_back(str1);
        }

        int count = 1;
        for (auto s : object) {
            count *= (s.second.size() + 1);
        }
        cout << count - 1 << "\n";
    }
}
