#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, s="";
    cin >> str;
    bool plus = true;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            plus ? sum += stoi(s) : sum -= stoi(s);
            plus = false;
            s = "";
        }
        else if (str[i] == '+') {
            plus ? sum += stoi(s) : sum -= stoi(s);
            s = "";
        }
        else if (str[i] != '+' && str[i] != '-') {
            s += str[i];
        }
    }
    plus ? sum += stoi(s) : sum -= stoi(s);

    cout << sum;
}
