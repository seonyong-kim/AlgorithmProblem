#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    string str = "";
    vector<string> answer;
    for (char c : my_string) {
        if (c == ' ') {
            if (str != "") {
                answer.emplace_back(str);
                str = "";
            }
        }
        else
            str += c;
    }

    if (str != "")
        answer.emplace_back(str);

    return answer;
}