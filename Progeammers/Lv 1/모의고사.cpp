#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> patterns = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };

    vector<int> scores(patterns.size(), 0);
    for (int i = 0; i < answers.size(); i++) {
        for (int p = 0; p < patterns.size(); p++) {
            if (answers[i] == patterns[p][i % patterns[p].size()]) {
                scores[p]++;
            }
        }
    }

    int maxScore = *max_element(scores.begin(), scores.end());

    vector<int> result;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] == maxScore) {
            result.push_back(i + 1);
        }
    }

    return result;
}