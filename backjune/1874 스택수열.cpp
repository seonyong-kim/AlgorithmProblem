#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    stack<int> st;
    vector<string> vec;
    int current = 1;
    while (n--) {
        int number;
        cin >> number;
        while (current <= number) {
            st.push(current);
            vec.emplace_back("+");
            current++;
        }
        if (st.empty() || st.top() < number) {
            cout << "NO";
            return 0;
        }
        st.pop();
        vec.emplace_back("-");
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
}
