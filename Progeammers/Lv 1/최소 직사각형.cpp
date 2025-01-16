#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int bigMax = 0;
    int smallMin = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            if (bigMax < sizes[i][0])
                bigMax = sizes[i][0];
            if (smallMin < sizes[i][1])
                smallMin = sizes[i][1];
        }
        else {
            if (bigMax < sizes[i][1])
                bigMax = sizes[i][1];
            if (smallMin < sizes[i][0])
                smallMin = sizes[i][0];
        }
    }
    return bigMax * smallMin;
}