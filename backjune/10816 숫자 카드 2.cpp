#include <iostream>
#include <map>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int number;
    cin >> N;
    map<int, int> m;
    while (N--) {
        cin >> number;
        if (m.find(number) != m.end()) {
            m[number]++;
        }
        else {
            m.insert({ number, 1 });
        }
    }
    cin >> M;
    while (M--) {
        cin >> number;
        if (m.find(number) != m.end()) {
            cout << m[number] << " ";
        }
        else {
            cout << "0" << " ";
        }
    }
}