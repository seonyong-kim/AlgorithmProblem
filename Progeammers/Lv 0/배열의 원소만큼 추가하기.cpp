#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int i : arr) {
        for (int j = 0; j < i; j++)
            answer.emplace_back(i);
    }
    return answer;
}