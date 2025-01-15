#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    int index = 0;
    for (int i = 0; i < n_str.size(); i++) {
        if (n_str[i] != '0') {
            index = i;
            break;
        }
    }
    return n_str.substr(index);
}