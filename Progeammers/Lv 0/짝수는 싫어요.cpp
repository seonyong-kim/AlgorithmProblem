#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int i = 1;
    while (i <= n) {
        answer.emplace_back(i);
        i += 2;
    }
    return answer;
}