#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for (char c : rny_string) {
        c == 'm' ? answer += "rn" : answer += c;
    }
    return answer;
}