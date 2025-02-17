#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, d;
    string str;
    cin >> N;
    vector<pair<int, string>> vec;
    for (int j = 0; j < N; j++) {
        cin >> str >> i >> d;
        str = toupper(str[d - 1]);
        
        vec.emplace_back( i,str );
    }

    sort(vec.begin(), vec.end());
    for (auto it : vec) {
        cout << it.second;
    }
}