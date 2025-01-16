#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char c : s) {
        if (c == ' ')
            answer += ' ';
        else if (c >= 'a' && c <= 'z')
            c + n > 'z' ? answer += 'a' + c + n - 'z' - 1 : answer += c + n;
        else if (c >= 'A' && c <= 'Z')
            c + n > 'Z' ? answer += 'A' + c + n - 'Z' - 1 : answer += c + n;
    }
    return answer;
}