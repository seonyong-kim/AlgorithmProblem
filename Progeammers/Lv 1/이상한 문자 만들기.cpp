#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    int index = 0;
    for (char c : s) {
        if (c == ' ') {
            index = 0;
            answer += " ";
            continue;
        }
        if (index % 2 == 0 && c > 90)
            answer += c - 32;
        else if (index % 2 == 1 && c < 91)
            answer += c + 32;
        else
            answer += c;
        index++;
    }
    return answer;
}