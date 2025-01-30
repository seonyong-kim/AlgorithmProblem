#include <iostream>
#include <vector>

using namespace std;

struct people {
    int before;
    int after;

    int sub() {
        return after - before;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<people> vec(4);

    for (int i = 0; i < 4; i++) {
        cin >> vec[i].before >> vec[i].after;
    }

    cout << vec[1].sub() + vec[2].sub() + vec[3].sub() << "\n" << vec[2].sub() + vec[3].sub() << "\n" << vec[3].sub();
}