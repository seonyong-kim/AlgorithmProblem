#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        int a = commands[i][0];  int b = commands[i][1];  int k = commands[i][2];
        for (int j = a - 1; j < b; j++)
            temp.emplace_back(array[j]);
        sort(temp.begin(), temp.end());
        answer.emplace_back(temp[k - 1]);
    }
    return answer;
}