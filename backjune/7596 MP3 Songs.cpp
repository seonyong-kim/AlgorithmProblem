#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int i = 1;
    while (true) {
        cin >> n;

        if (n == 0)
            return 0;

        vector<string> vec;
        string str;
        cin.ignore();
        while (n--) {
            getline(std::cin, str);
            vec.emplace_back(str);
        }

        sort(vec.begin(), vec.end());
        cout << i << "\n";
        i++;
        for (string s : vec) {
            cout << s << "\n";
        }
    }
}