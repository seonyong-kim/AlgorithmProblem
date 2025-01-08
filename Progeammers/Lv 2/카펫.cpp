#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int number = brown + yellow;
    for (int i = sqrt(number); i >= 1; i--) {
        if (number % i == 0 && yellow % (i - 2) == 0 && yellow % (number / i - 2) == 0) {
            answer.emplace_back(number / i);
            answer.emplace_back(i);
            break;
        }
    }
    return answer;
}