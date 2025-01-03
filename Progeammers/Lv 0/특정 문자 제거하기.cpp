#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for (char c : my_string) {
        if (string(1, c) == letter) {
            continue;
        }
        answer += c;
    }
    return answer;
}