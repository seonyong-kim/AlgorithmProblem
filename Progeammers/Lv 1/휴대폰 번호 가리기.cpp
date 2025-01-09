#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for (int i = 0; i < phone_number.length(); i++) {
        i < phone_number.length() - 4 ? answer += "*" : answer += string(1, phone_number[i]);
    }
    return answer;
}