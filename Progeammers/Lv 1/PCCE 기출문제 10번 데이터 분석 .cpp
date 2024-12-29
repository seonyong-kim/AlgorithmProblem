#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int index;

    if (ext == "date")
        index = 1;
    else if (ext == "code")
        index = 0;
    else if (ext == "maximum")
        index = 2;
    else
        index = 3;

    for (int i = 0; i < data.size(); i++) {
        if (data[i][index] < val_ext) {
            answer.push_back(data[i]);
        }
    }

    if (sort_by == "date")
        index = 1;
    else if (sort_by == "code")
        index = 0;
    else if (sort_by == "maximum")
        index = 2;
    else
        index = 3;

    sort(answer.begin(), answer.end(), [index](const vector<int>& a, const vector<int>& b) {
        return a[index] < b[index];
        });

    return answer;
}