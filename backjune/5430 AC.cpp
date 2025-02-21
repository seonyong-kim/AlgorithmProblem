#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print(vector<int> vec);
bool fun(vector<int>& vec, string work);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    int n;
    string work, number;
    while (T--) {
        cin >> work >> n >> number;
        vector<int> vec;
        string num = "";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == '[')
                continue;
            if (number[i] >= '0' && number[i] <= '9') {
                num += number[i];
            }
            else {
                if (num != "") {
                    vec.emplace_back(stoi(num));
                    num = "";
                }
            }
        }

        bool result = fun(vec, work);
        
        if (result) {
            print(vec);
        }
    }
}

bool fun(vector<int>& vec, string work) {
    int count_R = 0;
    for (int i = 0; i < work.size(); i++) {
        if (work[i] == 'R') {
            count_R++;
        }
        else if (work[i] == 'D') {
            if (vec.empty()) {
                cout << "error\n";
                return false;
            }
            else if (count_R % 2 == 0) {
                vec.erase(vec.begin());
            }
            else {
                vec.erase(vec.end()-1);
            }
        }
    }

    if(count_R % 2 == 1)
        reverse(vec.begin(), vec.end());
    return true;
}

void print(vector<int> vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            cout << vec[i];
        }
        else {
            cout << vec[i] << ",";
        }
    }
    cout << "]\n";
}