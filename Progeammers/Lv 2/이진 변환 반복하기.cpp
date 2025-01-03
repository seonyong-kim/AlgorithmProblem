#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int removeZero = 0;

    while (s != "1") {
        int oneLength = 0;
        for (char c : s) {
            if (c == '0')
                removeZero++;
            else
                oneLength++;
        }

        s = "";
        while (oneLength != 0) {
            s = s + to_string(oneLength % 2);
            oneLength /= 2;
        }
        reverse(s.begin(), s.end());
        count++;
    }

    answer.push_back(count);
    answer.push_back(removeZero);
    return answer;
}