#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    if (sides[2] < (sides[1] + sides[0]))
        return 1;
    return 2;
}