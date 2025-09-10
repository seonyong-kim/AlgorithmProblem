#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int m = arr1.size();
    int n = arr2[0].size();
    vector<vector<int>> answer(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int prod = 0;
            for (int h = 0; h < arr2.size(); h++) {
                prod += arr1[i][h] * arr2[h][j];
            }
            answer[i][j] = prod;
        }
    }
    return answer;
}