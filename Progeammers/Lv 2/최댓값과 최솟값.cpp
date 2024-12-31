#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int maxNumber = INT_MIN;
    int minNumber = INT_MAX;
    int j = 0;
    int count = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            int number = stoi(s.substr(j, count));
            minNumber = min(number, minNumber);
            maxNumber = max(number, maxNumber);
            count = 1;
            j = i;
        }
        else {
            count++;
        }
        if (s[s.length() - 1] != ' ') {
            int number = stoi(s.substr(j, s.length() - 1));
            minNumber = min(number, minNumber);
            maxNumber = max(number, maxNumber);
        }
    }
    answer = to_string(minNumber) + " " + to_string(maxNumber);
    return answer;
}