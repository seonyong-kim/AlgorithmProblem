#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    int n = my_string.size();
    for (int i = 0; i < n; i++) {
        answer.push_back(my_string[n - 1 - i]);
    }
    return answer;
}