#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    for (int i = 0; i < score.size(); i++) {
        temp.emplace_back(score[i]);
        sort(temp.begin(), temp.end());
        temp.size() < k ? answer.emplace_back(temp[0]) : answer.emplace_back(temp[temp.size() - k]);
    }
    return answer;
}