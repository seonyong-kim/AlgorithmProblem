#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            }
            else {
                int a = triangle[i - 1][j - 1] + triangle[i][j];
                int b = triangle[i - 1][j] + triangle[i][j];
                triangle[i][j] = max(a, b);
            }
        }
    }
    int maxNumber = 0;
    for (int n : triangle[triangle.size() - 1]) {
        maxNumber = max(maxNumber, n);
    }
    return maxNumber;
}