#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    cin >> N;
    vector<int> vec;
    map<int, int> m;
    while (N--) {
        cin >> x;
        vec.emplace_back(x);
        m[x]=0;
    }

    int index = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
        i->second = index;
        index++;
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << m.find(vec[i])->second << " ";
    }
}