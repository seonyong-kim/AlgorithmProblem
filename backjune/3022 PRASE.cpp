#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string str;
    map<string, int> m;
    int count = 0;  int sum = 0;
    while (n--) {
        cin >> str;
        m[str]++;
        sum++;

        if (m[str] - 1 > (sum - m[str]))
            count++;
    }
    cout << count;
}