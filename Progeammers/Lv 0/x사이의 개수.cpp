#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    int count = 0;
    vector<int> answer;
    for (char c : myString) {
        if (c != 'x')
            count++;
        else {
            answer.emplace_back(count);
            count = 0;
        }
    }
    answer.emplace_back(count);
    return answer;
}