#include <iostream>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        multiset<int> dq;
        int T;
        cin >> T;
        while (T--) {
            string str;
            int n;
            cin >> str >> n;
            if (str == "I") {
                dq.insert(n);
            }
            else if (str == "D") {
                if (dq.empty()) 
                    continue;
                else if (n == 1) {
                    dq.erase(prev(dq.end()));
                }
                else if(n == -1){
                    dq.erase(dq.begin());
                }
            }        
        }
        if (dq.empty())
            cout << "EMPTY\n";
        else {

            cout << *dq.rbegin() << " " << *dq.begin() << "\n";
        }
    }
}
