#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[0] <= 122 && s[0] >= 97)
            s[0] -= 32;
        if (s[i] == ' ' && s[i + 1] <= 122 && s[i + 1] >= 97)
            s[i + 1] -= 32;
        if (s[i] != ' ' && s[i + 1] <= 90 && s[i + 1] >= 65)
            s[i + 1] += 32;
    }
    return s;
}